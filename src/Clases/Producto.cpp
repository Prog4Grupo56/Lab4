#include "../../include/Clases/Producto.h"

//Constructor
Producto::Producto(){}

//Destructor
Producto::~Producto(){}

string Producto::getCodigo(){
    return codigo;
}
//string Producto::getCategoria(){}
string Producto::getNombre(){
    return nombre;
}
string Producto::getDescripcion(){
    return descripcion;
}
int Producto::getStock(){
    return stock;
}
float Producto::getPrecio(){
    return precio;
}

void Producto::setCodigo(string _codigo){
    codigo = _codigo;
}
//void sProducto::etCategoria(){}
void Producto::setNombre(string _nombre){
    nombre = _nombre;
}
void Producto::setDescripcion(string _descripcion){
    descripcion = _descripcion;
}
void Producto::setStock(int _stock){
    stock = _stock;
}
void Producto::setPrecio(float _precio){
    precio = _precio;
}


//Operaciones:

DataProducto Producto::getDataProducto(){
    return DataProducto(codigo, stock, precio, nombre, descripcion);
}

bool Producto::pertenecePromoVigente(){
    return DTFecha(9,06,2024) <= cantMin->obtenerFechaPromocion(); // REVISAR LO DE LA FECHA ACTUAL
}

void Producto::crearEnvio(Compra* c, int cantidad){  
    compraProducto.insert(new CompraProducto(c, cantidad));
}