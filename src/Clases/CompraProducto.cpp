#include "../../include/Clases/CompraProducto.h"

CompraProducto::CompraProducto(Producto* _producto,Compra* _compra)
{
    producto = _producto;
    compra = _compra;
};
CompraProducto::~CompraProducto()
{

};

      
Producto* CompraProducto::getProducto()
{
    return producto;
};
Compra* CompraProducto::getCompra()
{
    return compra;
};
int CompraProducto::getCantMin()
{
    return cantidadMinima;
};
int CompraProducto::getCantidad()
{
    return cantidad;
};
bool CompraProducto::getEstado()
{
    return enviado;
};

void CompraProducto::setProducto(Producto* _p)
{
    producto = _p;
};
void CompraProducto::setCompra(Compra* _c)
{
    compra = _c;
};
void CompraProducto::setCantMin(int cant)
{
    cantidadMinima = cant;
};
void CompraProducto::setCantidad(int cant)
{
    cantidad = cant;
};
void CompraProducto::setEstado(bool e)
{
    enviado = e;
};