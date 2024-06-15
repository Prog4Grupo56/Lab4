#include "../../include/Clases/Producto.h"

//Constructor
Producto::Producto(int _codigo, Categoria _categoria, string _nombre, string _descripcion, int _stock, float _precio, Vendedor* _vendedor){
    codigo = _codigo;
    categoria = _categoria;
    nombre = _nombre;
    descripcion = _descripcion;
    stock = _stock;
    precio = _precio;
    cantMin = NULL;
    vendedor = _vendedor;
}

//Destructor
Producto::~Producto(){}

int Producto::getCodigo(){
    return codigo;
}
string Producto::getCategoria(){
    return to_string(categoria);
}
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

void Producto::setCodigo(int _codigo){
    codigo = _codigo;
}
void Producto::setCategoria(Categoria _categoria){
    categoria = _categoria;
}
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
    return DataProducto(codigo, stock, precio, nombre, descripcion, categoria);
}

bool Producto::pertenecePromoVigente(){
    return DTFecha(9,06,2024) <= cantMin->obtenerFechaPromocion(); // REVISAR LO DE LA FECHA ACTUAL
}

void Producto::crearEnvio(Compra* c, int cantidad){  
    compraProducto.insert(new CompraProducto(c, cantidad));
}

CantMin* Producto::getCantMin(){
    return cantMin;
}

set<CompraProducto*> Producto::getCompraProducto(){
    return compraProducto;
}

void Producto::setCantMin(CantMin* _cantMin){
    cantMin = _cantMin;
}

void Producto::setCompraProducto(set<CompraProducto*> _compraProducto){
    compraProducto = _compraProducto;
}

Vendedor* Producto::getVendedor(){
    return vendedor;
}

void Producto::setVendedor(Vendedor* _vendedor){
    vendedor = _vendedor;
}