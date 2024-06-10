#include "../../include/Clases/CompraProducto.h"

CompraProducto::CompraProducto(Compra* _c, int _cantidad){
    c = _c;
    cantidad = _cantidad;
}

CompraProducto::~CompraProducto(){}

Compra* CompraProducto::getCompra(){
    return c;
}
int CompraProducto::getCantidad(){
    return cantidad;
}
bool CompraProducto::getEstado(){
    return enviado;
}
//Setters
void CompraProducto::setCompra(Compra* _c){
    c = _c;
}
void CompraProducto::setCantidad(int cant){
    cantidad = cant;
}
void CompraProducto::setEstado(bool e){
    enviado = e;
}