#include "../../include/Datatypes/DTVendedor.h"

DTVendedor::DTVendedor(){};

DTVendedor::DTVendedor(string _nickname, string _contrasena, DTFecha _fecha, string _RUT): DTUsuario(_nickname, _contrasena, _fecha), RUT(_RUT){};

DTVendedor::~DTVendedor(){};

string DTVendedor::getRUT(){
    return RUT;
}

string DTVendedor::toString(){
    return "Nickname: " + this->getNickname() + " | Fecha de nacimiento: " + this->getFecha().toString() + " | Rut: " + RUT;
}
