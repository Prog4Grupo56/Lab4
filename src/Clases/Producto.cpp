#include "../../include/Clases/Producto.h"

//Constructor
Producto::Producto(){}

//Destructor
Producto::~Producto(){}

string Producto::getCodigo(){
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

void Producto::setCodigo(string _codigo){
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
    compraProducto.push_back(new CompraProducto(c, cantidad));
}

CantMin* Producto::getCantMin(){
    return cantMin;
}

vector<CompraProducto*> Producto::getCompraProducto(){
    return compraProducto;
}

void Producto::setCantMin(CantMin* _cantMin){
    cantMin = _cantMin;
}

void Producto::setCompraProducto(vector<CompraProducto*> _compraProducto){
    compraProducto = _compraProducto;
}

vector<ParNickFecha> Producto::obtenerClienteFecha(){
    vector<ParNickFecha> clienteFecha;
    for(const CompraProducto* cp : compraProducto){
        clienteFecha.push_back( cp->obtenerClienteFecha() );
    }
    return clienteFecha;
}