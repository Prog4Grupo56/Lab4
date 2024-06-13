#include "../../include/Clases/Cliente.h"

Cliente::Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad):Usuario(_nickname, _contrasenia, _fecha), direccion(_direccion), ciudad(_ciudad) {};

Cliente::Cliente(DataCliente cliente): Usuario(cliente.getNickname(), cliente.getContrasena(), cliente.getFecha()){
    direccion = cliente.getDireccion();
    ciudad = cliente.getCiudad();
};

Cliente::~Cliente(){
    /*set<Vendedor*>::iterator it;
    for (it=suscripciones.begin();it!=suscripciones.end();++it){
        Vendedor* v = *it;
        v->eliminarSuscriptor(this);
    }*/
};

/*======= GETTERS ========*/
DTDireccion Cliente::getDireccion(){
    return direccion;
};  
string Cliente::getCiudad(){
    return ciudad;
};  

// set<DTNotificacion> Cliente::getNotificaciones(){
//     set<DTNotificacion> copiaNotificaciones = notificaciones;

//     // for (DTNotificacion notificacion : notificaciones){ //hago una copia para retornar
//     //     DTNotificacion copia = DTNotificacion(notificacion.getNombreVendedor(), notificacion.getNombrePromocion(), notificacion.getProductos());
//     //     copiaNotificaciones.insert(copia);
//     // }

//     // for (DTNotificacion notificacion : notificaciones){ //seteo en vacio las notificaciones
//     //     notificaciones.erase(notificacion);
//     // }

//     notificaciones = {};
//     return copiaNotificaciones;
// }

vector<DataVendedor> Cliente::obtenerSuscripciones(){


    vector<DataVendedor> lista; 

    // for (Vendedor* v: suscripciones){
    //     string nickname = v->getNickname();
    //     DTFecha fecha = v->getFecha();
    //     int RUT = v->getRUT();
    //     string contrasena = v->getContrasena();
    //     DataVendedor dataV = DataVendedor(nickname, contrasena, fecha, RUT);
    //     lista.insert(dataV);
    // }
    return lista; //limpiar memoria de dataVendedor al finalizar el caso de uso
}

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
    
    // DTNotificacion notificacion = DTNotificacion(nombreVendedor, nombrePromocion, dtProductos);
    // notificaciones.insert(notificacion);
}
