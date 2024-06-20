#include "../../include/Clases/Vendedor.h"

Vendedor::Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, string _RUT):
Usuario(_nickname, _contrasenia, _fecha), RUT(_RUT){};

Vendedor::Vendedor(DTVendedor vendedor): Usuario(vendedor.getNickname(), vendedor.getContrasena(), vendedor.getFecha()){
    RUT = vendedor.getRUT();
};

Vendedor::~Vendedor(){
};

/*======= GETTERS ========*/
string Vendedor::getRUT(){
    return RUT;
};

DTVendedor Vendedor::getDataVendedor(){
    return DTVendedor(this->getNickname(), this->getContrasena(), this->getFecha(), RUT); 
}

vector<DTCodigoNombre> Vendedor::obtenerProductos(DTFecha _fecha){

    vector<DTCodigoNombre> lista;
    map<int,Producto*>::iterator it;
    for(it = productos.begin(); it != productos.end(); ++it){
        Producto* producto = it->second;
        bool productoOcupado = producto->pertenecePromoVigente(_fecha);
        if (!productoOcupado){
            DTCodigoNombre par = DTCodigoNombre(producto->getNombre(), producto->getCodigo());
            lista.push_back(par);
        }
    }
    return lista;
};

/*======= SETTERS ========*/
void Vendedor::setRUT(string _RUT){
    RUT = _RUT;
};

void Vendedor::setProducto(Producto* producto){
    productos[producto->getCodigo()] = producto;
}

void Vendedor::agregarSuscriptor(Cliente* c){
    suscriptores[c->getNickname()] = c;
}

void Vendedor::eliminarSuscriptor(Cliente* c){
    suscriptores.erase(c->getNickname());
}

bool Vendedor::estaSuscrito(string nicknameCliente){
    return suscriptores[nicknameCliente] != NULL;
}

void Vendedor::agregarPromocionYNotificar(vector<DTProducto> dtProductos, string nombrePromocion, Promocion* pr){
    promociones[pr->getNombre()] = pr;
    notificarClientes(dtProductos, nombrePromocion);
}

void Vendedor::notificarClientes(vector<DTProducto> dtProductos, string nombrePromocion){
    map<string, Cliente*>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Cliente* c = it->second;
        c->notificar(this->getNickname(), dtProductos, nombrePromocion);
    }
}

vector<DTPromocion> Vendedor::obtenerInfoPromocionesVigentes(DTFecha _fecha){
    vector<DTPromocion> dPromociones;
    for (std::map<string, Promocion*>::iterator it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion* promocionActual = it->second;
        if(_fecha<=promocionActual->getFechaVenc()){
            dPromociones.push_back(promocionActual->getDataPromocion());
        }
    }
    return dPromociones;
}

vector<DTProducto> Vendedor::obtenerInfoProductos(){
    vector<DTProducto> dProductos;
    for (std::map<int, Producto*>::iterator it = productos.begin(); it != productos.end(); ++it) {
        Producto* productoActual = it->second;
        dProductos.push_back(productoActual->getDataProducto());
    }
    return dProductos;
}

vector<DTCodigoNombre> Vendedor::obtenerProductosPendientesEnvio(){

    vector<DTCodigoNombre> prodPend;
    for(const pair<int, Producto*> par : productos){
        vector<CompraProducto*> compraProductos = par.second->getCompraProducto();
        for(unsigned int i = 0; i<compraProductos.size(); i++){
            if (!compraProductos[i]->getEstado()){
                prodPend.push_back(DTCodigoNombre(par.second->getNombre() ,par.second->getCodigo() ));
            }
        }
    }
    return prodPend;

}