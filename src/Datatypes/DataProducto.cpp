#include "../../include/Datatypes/DataProducto.h"

DataProducto::DataProducto(){}
DataProducto::DataProducto(int _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria){
    codigo = _codigo;
    stock = _stock;
    precio = _precio;
    nombre = _nombre;
    descripcion = _descripcion;
    categoria = _categoria;
};

DataProducto::~DataProducto(){};

/*======= GETTERS ========*/
int DataProducto::getCodigo(){
    return codigo;
}
int DataProducto::getStock(){
    return stock;
}
float DataProducto::getPrecio(){
    return precio;
}
string DataProducto::getNombre(){
    return nombre;
}
string DataProducto::getDescripcion(){
    return descripcion;
}
/*Categoria DataProducto::getCategoria(){
    return categoria;
}*/

string DataProducto::toString(){
    return codigo + ", " + nombre + ", " + descripcion + ", " + to_string(stock) + ", " + to_string(precio) + ", " + to_string(categoria);
}