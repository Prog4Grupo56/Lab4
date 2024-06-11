#include "../../include/Datatypes/DTNotificacion.h"

DTNotificacion::DTNotificacion(string _nombreVendedor, string _nombrePromocion, vector<DataProducto> _productos){
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
vector<DataProducto> DTNotificacion::getProductos(){
    return productos;
}