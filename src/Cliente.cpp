#include "../include/Cliente.h"

Cliente::Cliente(string _nickname, string _contrasenia, DTFecha* _fecha, DTDireccion* _direccion, string _ciudad):Usuario(_nickname, _contrasenia, _fecha), direccion(_direccion), ciudad(_ciudad) {};

Cliente::~Cliente(){};

/*======= GETTERS ========*/
DTDireccion* Cliente::getDireccion(){
    return direccion;
};  
string Cliente::getCiudad(){
    return ciudad;
};  

/*======= SETTERS ========*/
void Cliente::setDireccion(DTDireccion* _direccion){
    direccion = _direccion;
};
void Cliente::setCiudad(string _ciudad){
    ciudad = _ciudad;
};

//SETEAR SUSCRIPCIONES Y NOTIFICACIONES