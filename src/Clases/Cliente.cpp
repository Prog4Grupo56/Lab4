#include "../../include/Clases/Cliente.h"

Cliente::Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad):Usuario(_nickname, _contrasenia, _fecha), direccion(_direccion), ciudad(_ciudad) {};

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

set<DataVendedor> Cliente::obtenerSuscripciones(){


    set<DataVendedor> lista; 

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
    suscripciones.insert(v);
}

void Cliente::eliminarSuscripcion(Vendedor* v){
    suscripciones.erase(v);
}

void Cliente::eliminarSuscripciones(set<DataVendedor> vendedores){

    set<DataVendedor>::iterator it;
    for (it = vendedores.begin(); it != vendedores.end(); ++it){
        DataVendedor vend = *it;
        string nickname = vend.getNickname();
        set<Vendedor*>::iterator itv;
        for (itv = suscripciones.begin(); itv != suscripciones.end(); ++itv){
            Vendedor* v = *itv;
            if (v->getNickname() == nickname){
                eliminarSuscripcion(v);
                break;
            }
        }
    }
};

void Cliente::notificar(string nombreVendedor, set<DataProducto> dtProductos, string nombrePromocion){
    
    // DTNotificacion notificacion = DTNotificacion(nombreVendedor, nombrePromocion, dtProductos);
    // notificaciones.insert(notificacion);
}
