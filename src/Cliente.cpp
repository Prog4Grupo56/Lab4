#include "../include/Cliente.h"

Cliente::Cliente(string _nickname, string _contrasenia, DTFecha* _fecha, DTDireccion* _direccion, string _ciudad):Usuario(_nickname, _contrasenia, _fecha), direccion(_direccion), ciudad(_ciudad) {};

Cliente::~Cliente(){
    /*set<Vendedor*>::iterator it;
    for (it=suscripciones.begin();it!=suscripciones.end();++it){
        Vendedor* v = *it;
        v->eliminarSuscriptor(this);
    }*/
};

/*======= GETTERS ========*/
DTDireccion* Cliente::getDireccion(){
    return direccion;
};  
string Cliente::getCiudad(){
    return ciudad;
};  

set<DataVendedor*> Cliente::obtenerSuscripciones(){

    set<Vendedor*>::iterator it;
    set<DataVendedor*> lista; 

    for (it = suscripciones.begin(); it != suscripciones.end();++it){
        Vendedor* v = *it;
        string nickname = v->getNickname();
        DTFecha* fecha = v->getFecha();
        int RUT = v->getRUT();
        DataVendedor* dataV = new DataVendedor(nickname, fecha, RUT);
        lista.insert(dataV);
    }
    return lista; //limpiar memoria de dataVendedor al finalizar el caso de uso
}

/*======= SETTERS ========*/
void Cliente::setDireccion(DTDireccion* _direccion){
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

void Cliente::eliminarSuscripciones(set<DataVendedor*>){

    ////IMPLEMENTAAAAAAAAAAAAAAAAR
};

//void Cliente::notificar()