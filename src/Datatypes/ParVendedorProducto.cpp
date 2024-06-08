#include "../../include/Datatypes/ParVendedorProducto.h"

ParVendedorProducto::ParVendedorProducto():{
    producto = DataProducto()
}

ParVendedorProducto::ParVendedorProducto(string _nickname, DTFecha _fecha): fecha(_fecha){
    nickname = _nickname;
}

ParVendedorProducto::~ParVendedorProducto(){};

string ParVendedorProducto::getNickname(){
    return nickname;
}

DTFecha ParVendedorProducto::getFecha(){
    return fecha;
}