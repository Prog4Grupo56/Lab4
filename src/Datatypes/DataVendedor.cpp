#include "../../include/Datatypes/DataVendedor.h"

DataVendedor::DataVendedor(){};

DataVendedor::DataVendedor(string _nickname, string _contrasena, DTFecha _fecha, string _RUT): DataUsuario(_nickname, _contrasena, _fecha), RUT(_RUT){};

DataVendedor::~DataVendedor(){};

string DataVendedor::getRUT(){
    return RUT;
}

string DataVendedor::toString(){
    return this->getNickname() + ", " + this->getFecha().toString() + ", " + RUT;
}
