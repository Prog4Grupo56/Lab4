#include "../../include/Datatypes/DTCliente.h"

DTCliente::DTCliente(string _nickname, string _contrasena, DTFecha _fecha, DTDireccion _direccion, string _ciudad):
DTUsuario(_nickname, _contrasena, _fecha), direccion(_direccion), ciudad(_ciudad){};

DTCliente::~DTCliente(){

}

DTDireccion DTCliente::getDireccion(){
    return direccion;
}

string DTCliente::getCiudad(){
    return ciudad;
}


string DTCliente::toString(){
    return "Nickname: " + this->getNickname() + " | Fecha de nacimiento: " + this->getFecha().toString() + " | Direccion: " + this->getDireccion().toString() + " | Ciudad: " +  ciudad;
}