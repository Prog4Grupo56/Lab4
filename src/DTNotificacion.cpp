#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(string _nombreVendedor, string _nombrePromocion, set<DataProducto*> _productos){
    nombreVendedor = _nombreVendedor;
    nombrePromocion = _nombrePromocion;
    productos = _productos;
};

DTNotificacion::~DTNotificacion(){};

/*======= GETTERS ========*/
string DTNotificacion::getNombreVendedor(){
    return nombreVendedor;
}
string DTNotificacion::getNombrePromocion(){
    return nombrePromocion;
}
//No me convence un sorete, revisar despues
set<DataProducto*> DTNotificacion::getProductos(){
    return productos;
}

/*======= SETTERS ========*/
void DTNotificacion::setNombreVendedor(string _nombreVendedor){
    nombreVendedor = _nombreVendedor;
}
void DTNotificacion::setNombrePromocion(string _nombrePromocion){
    nombrePromocion = _nombrePromocion;
}
//Tampoco me convence un sorete, revisar despues
void DTNotificacion::setProductos(set<DataProducto*> _productos){
    productos = _productos;
}