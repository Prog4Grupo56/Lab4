#include "../../include/Datatypes/ParVendedorProducto.h"

ParVendedorProducto::ParVendedorProducto(){
    producto = DTProducto();
}

ParVendedorProducto::ParVendedorProducto(string _nickname, DTProducto prod){ 
    producto = prod;
    nickname = _nickname;
}

ParVendedorProducto::~ParVendedorProducto(){};

string ParVendedorProducto::getNickname(){
    return nickname;
}

DTProducto ParVendedorProducto::getProducto(){
    return producto;
}