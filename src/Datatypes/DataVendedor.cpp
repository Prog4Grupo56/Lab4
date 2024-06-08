#include "../../include/Datatypes/DataVendedor.h"

DataVendedor::DataVendedor(){};

DataVendedor::DataVendedor(string _nickname, DTFecha _fecha, int _RUT): DataUsuario(_nickname, _fecha), RUT(_RUT){};

DataVendedor::~DataVendedor(){};

int DataVendedor::getRUT(){
    return RUT;
}

