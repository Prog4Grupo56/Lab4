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

string DTNotificacion::toString(){
    string res;
    res = nombreVendedor + ", " + nombrePromocion;

    for(long unsigned int i = 0; i<productos.size(); i++){
        DataProducto producto = productos[i];
        res = res + ", " + producto.toString();
    }
    return res;
};