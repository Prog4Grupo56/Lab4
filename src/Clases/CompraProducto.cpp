#include "../../include/Clases/CompraProducto.h"

CompraProducto::CompraProducto(Compra* _c, int _cantidad, Producto* _producto){
    compra = _c;
    cantidad = _cantidad;
    producto = _producto;
}

CompraProducto::~CompraProducto(){
    // producto = NULL;
    // compra = NULL;
}

Compra* CompraProducto::getCompra(){
    return compra;
}
int CompraProducto::getCantidad(){
    return cantidad;
}
bool CompraProducto::getEstado(){
    return enviado;
}
Producto* CompraProducto::getProducto(){
    return producto;
}
//Setters
void CompraProducto::setCompra(Compra* _c){
    compra = _c;
}
void CompraProducto::setCantidad(int cant){
    cantidad = cant;
}
void CompraProducto::setEstado(bool e){
    enviado = e;
}
void CompraProducto::setProducto(Producto* _producto){
    producto = _producto;
}
DTNickFecha CompraProducto::obtenerClienteFecha() const{
    return DTNickFecha(compra->getNickCliente(), compra->getFecha());
}
bool CompraProducto::esCompraDeCliente(string _cliente) const{
    return (compra->getNickCliente() == _cliente);
}
