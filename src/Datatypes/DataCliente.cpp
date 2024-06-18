#include "../../include/Datatypes/DataCliente.h"

DataCliente::DataCliente(string _nickname, string _contrasena, DTFecha _fecha, DTDireccion _direccion, string _ciudad):
DataUsuario(_nickname, _contrasena, _fecha), direccion(_direccion), ciudad(_ciudad){};

DataCliente::~DataCliente(){

}

DTDireccion DataCliente::getDireccion(){
    return direccion;
}

string DataCliente::getCiudad(){
    return ciudad;
}


string DataCliente::toString(){
    return "Nickname: " + this->getNickname() + " | Fecha de nacimiento: " + this->getFecha().toString() + " | Direccion: " + this->getDireccion().toString() + " | Ciudad: " +  ciudad;
}