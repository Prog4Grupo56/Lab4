#include "../../include/Datatypes/ParVendedorProducto.h"

ParVendedorProducto::ParVendedorProducto(){
    producto = DataProducto();
}

ParVendedorProducto::ParVendedorProducto(string _nickname, DataProducto prod){ 
    producto = prod;
    nickname = _nickname;
}

ParVendedorProducto::~ParVendedorProducto(){};

string ParVendedorProducto::getNickname(){
    return nickname;
}

DataProducto ParVendedorProducto::getProducto(){
    return producto;
}