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
    return this->getNickname() + ", " + this->getFecha().toString() + ", " + this->getDireccion().toString() + ", " +  ciudad;
}