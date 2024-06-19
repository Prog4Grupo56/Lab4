#include "../../include/Datatypes/DTNotificacion.h"

DTNotificacion::DTNotificacion(string _nombreVendedor, string _nombrePromocion, vector<DTProducto> _productos){
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
vector<DTProducto> DTNotificacion::getProductos(){
    return productos;
}

string DTNotificacion::toString(){
    string res;
    res = "Nombre vendedor: " + nombreVendedor + " | Nombre promocion: " + nombrePromocion;

    for(long unsigned int i = 0; i<productos.size(); i++){
        DTProducto producto = productos[i];
        res = res + "\n\t\t " + producto.toString();
    }
    return res;
};