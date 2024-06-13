#include "../../include/Clases/Vendedor.h"

Vendedor::Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT):
Usuario(_nickname, _contrasenia, _fecha), RUT(_RUT){};

Vendedor::Vendedor(DataVendedor vendedor): Usuario(vendedor.getNickname(), vendedor.getContrasena(), vendedor.getFecha()){
    RUT = vendedor.getRUT();
};

Vendedor::~Vendedor(){
    /*set<Cliente*>::iterator it;
    for (it=suscriptores.begin();it!=suscriptores.end();++it){
        Cliente* c = *it;
        c->eliminarSuscripcion(this);
    }*/
};

/*======= GETTERS ========*/
int Vendedor::getRUT(){
    return RUT;
};

vector<ParCodigoNombre> Vendedor::obtenerProductos(){

    vector<ParCodigoNombre> lista;
    map<string,Producto*>::iterator it;

    for(it = productos.begin(); it != productos.end(); ++it){
        Producto* producto = it->second;
        bool productoOcupado = producto->pertenecePromoVigente();
        if (!productoOcupado){
            ParCodigoNombre par = ParCodigoNombre(producto->getNombre(), producto->getCodigo());
            lista.push_back(par);
        }
    }
    return lista;
};

/*======= SETTERS ========*/
void Vendedor::setRUT(int _RUT){
    RUT = _RUT;
};

void Vendedor::setProducto(Producto* producto){
    productos[producto->getNombre()] = producto;
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

void Vendedor::agregarPromocionYNotificar(vector<DataProducto> dtProductos, string nombrePromocion, Promocion* pr){
    promociones[pr->getNombre()] = pr;
    notificarClientes(dtProductos, nombrePromocion);
}

void Vendedor::notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion){
    map<string, Cliente*>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Cliente* c = it->second;
        c->notificar(this->getNickname(), dtProductos, nombrePromocion);
    }
}

