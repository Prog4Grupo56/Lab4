#include "../../include/Datatypes/DataProducto.h"

DataProducto::DataProducto(){}
DataProducto::DataProducto(string _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria){
DataProducto::DataProducto(string _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria){
    codigo = _codigo;
    stock = _stock;
    precio = _precio;
    nombre = _nombre;
    descripcion = _descripcion;
    categoria = _categoria;
    categoria = _categoria;
};

DataProducto::~DataProducto(){};

/*======= GETTERS ========*/
string DataProducto::getCodigo(){
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
Categoria DataProducto::getCategoria(){
    return categoria;
}
