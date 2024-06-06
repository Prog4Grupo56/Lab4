#include "../include/DataProducto.h"

DataProducto::DataProducto(string _codigo, int _stock, float _precio, string _nombre, string _descripcion/*, Categoria* _categoria*/){
    codigo = _codigo;
    stock = _stock;
    precio = _precio;
    nombre = _nombre;
    descripcion = _descripcion;
    //categoria = _categoria;
};

DataProducto::~DataProducto(){};

//Getters
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
/*Categoria* DataProducto::getCategoria(){
    return categoria;
}*/

//Setters
void DataProducto::setCodigo(string _codigo){
    codigo = _codigo;
}
void DataProducto::setStock(int _stock){
    stock = _stock;
}
void DataProducto::setPrecio(float _precio){
    precio = _precio;
}
void DataProducto::setNombre(string _nombre){
    nombre = _nombre;
}
void DataProducto::setDescripcion(string _descripcion){
    descripcion = _descripcion;
}
/*void DataProducto::setCategoria(Categoria* _categoria){
    categoria = _categoria;
}*/
