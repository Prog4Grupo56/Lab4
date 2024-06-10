#include "../../include/Datatypes/DataVendedor.h"

DataVendedor::DataVendedor(){};

DataVendedor::DataVendedor(string _nickname, string _contrasena, DTFecha _fecha, int _RUT): DataUsuario(_nickname, _contrasena, _fecha), RUT(_RUT){};

DataVendedor::~DataVendedor(){};

int DataVendedor::getRUT(){
    return RUT;
}

string DataVendedor::toString(){
    return this->getNickname() + ", " + this->getFecha().toString() + ", " + to_string(RUT);
}
