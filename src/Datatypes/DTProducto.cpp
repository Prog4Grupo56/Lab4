#include "../../include/Datatypes/DTProducto.h"

DTProducto::DTProducto(){}
DTProducto::DTProducto(int _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria){
    codigo = _codigo;
    stock = _stock;
    precio = _precio;
    nombre = _nombre;
    descripcion = _descripcion;
    categoria = _categoria;
};

DTProducto::~DTProducto(){};

/*======= GETTERS ========*/
int DTProducto::getCodigo(){
    return codigo;
}
int DTProducto::getStock(){
    return stock;
}
float DTProducto::getPrecio(){
    return precio;
}
string DTProducto::getNombre(){
    return nombre;
}
string DTProducto::getDescripcion(){
    return descripcion;
}
Categoria DTProducto::getCategoria(){
    return categoria;
}

string DTProducto::toString(){
    string _categoria;
    if (categoria == Ropa){
        _categoria = "Ropa";
    }
    else if (categoria == Electrodomesticos){
        _categoria = "Electrodomesticos";
    }
    else{
        _categoria = "Otros";
    }
    return "Codigo: " + to_string(codigo) + " | Nombre: " + nombre + " | Descripcion: " + descripcion + " | Stock: " + to_string(stock) + " | Precio: " + to_string(precio) + " | Categoria: " + _categoria ;
}
