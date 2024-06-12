#include "../../include/DTs/DataCliente.h"

DataCliente::DataCliente(string _nickname, DTFecha* _fecha, DTDireccion* _direccion, string _ciudad):
DataUsuario(_nickname, _fecha), direccion(_direccion), ciudad(_ciudad){};

DTDireccion* DataCliente::getDireccion(){
    return direccion;
}

string DataCliente::getCiudad(){
    return ciudad;
}