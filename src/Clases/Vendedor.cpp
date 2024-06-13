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
//     vector<ParCodigoNombre> lista;

//     for(Producto* producto : productos){
//         bool productoOcupado = producto->pertenecePromoVigente();
//         if (!productoOcupado){
//             ParCodigoNombre par = ParCodigoNombre(producto->getNombre(), producto->getCodigo());
//             lista.insert(par);
//         }
//     }
//      return lista;*/
    return {};
};

/*======= SETTERS ========*/
void Vendedor::setRUT(int _RUT){
    RUT = _RUT;
};

void Vendedor::setProducto(Producto* producto){
    productos.insert(producto);
}

void Vendedor::agregarSuscriptor(Cliente* c){
    suscriptores.insert(c);
}

void Vendedor::eliminarSuscriptor(Cliente* c){
    suscriptores.erase(c);
}

bool Vendedor::estaSuscrito(string nicknameCliente){
    set<Cliente*>::iterator it;
    for(it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Cliente* c = *it;
        if (c->getNickname() == nicknameCliente){
            return true;
        }
    }
    return false;
}

// void Vendedor::agregarPromocionYNotificar(set<DataProducto> dtProductos, string nombrePromocion, Promocion* pr){
//     promociones.insert(pr);
//     notificarClientes(dtProductos, nombrePromocion);
// }

void Vendedor::notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion){
    set<Cliente*>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Cliente* c = *it;
        c->notificar(this->getNickname(), dtProductos, nombrePromocion);
    }
}

