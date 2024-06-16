#include "../../include/Clases/Cliente.h"

Cliente::Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad):Usuario(_nickname, _contrasenia, _fecha), direccion(_direccion), ciudad(_ciudad) {};

Cliente::Cliente(DataCliente cliente): Usuario(cliente.getNickname(), cliente.getContrasena(), cliente.getFecha()){
    direccion = cliente.getDireccion();
    ciudad = cliente.getCiudad();
};

Cliente::~Cliente(){
};

/*======= GETTERS ========*/
DTDireccion Cliente::getDireccion(){
    return direccion;
};  
string Cliente::getCiudad(){
    return ciudad;
};  

vector<DTNotificacion> Cliente::getNotificaciones(){
    vector<DTNotificacion> copiaNotificaciones = notificaciones;

    notificaciones = {};
    return copiaNotificaciones;
}

vector<DataVendedor> Cliente::obtenerSuscripciones(){

    vector<DataVendedor> lista; 

    map<string, Vendedor*>::iterator it;
    for (it = suscripciones.begin(); it != suscripciones.end(); ++it){
        string nickname = it->first;
        DTFecha fecha = it->second->getFecha();
        string RUT = it->second->getRUT();
        string contrasena = it->second->getContrasena();
        DataVendedor dataV = DataVendedor(nickname, contrasena, fecha, RUT);
        lista.push_back(dataV);
    }
    return lista;
}

DataCliente Cliente::getDataCliente(){
    return DataCliente(this->getNickname(), this->getContrasena(), this->getFecha(), direccion, ciudad);
};

/*======= SETTERS ========*/
void Cliente::setDireccion(DTDireccion _direccion){
    direccion = _direccion;
};
void Cliente::setCiudad(string _ciudad){
    ciudad = _ciudad;
};

void Cliente::agregarSuscripcion(Vendedor* v){
    suscripciones[v->getNickname()] = v;
}

void Cliente::eliminarSuscripcion(Vendedor* v){
    suscripciones.erase(v->getNickname());
}

void Cliente::eliminarSuscripciones(vector<DataVendedor> vendedores){

    for (long unsigned int i = 0; i < vendedores.size(); i++){
        DataVendedor vend = vendedores[i];
        string nickname = vend.getNickname();

        Vendedor* v = suscripciones[nickname];
        eliminarSuscripcion(v);
    }
};

void Cliente::notificar(string nombreVendedor, vector<DataProducto> dtProductos, string nombrePromocion){
    DTNotificacion notificacion = DTNotificacion(nombreVendedor, nombrePromocion, dtProductos);
    notificaciones.push_back(notificacion);
}

vector<Compra*> Cliente::getCompras(){
    return compras;
}

void Cliente::setCompras(vector<Compra*> _compras){
    compras = _compras;
}

void Cliente::agregarCompra(Compra* _compra){
    compras.push_back(_compra);
}