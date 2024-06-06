#include "../include/Compra.h"

Compra::Compra()
{

};
Compra::~Compra()
{

};


float Compra::getMontoFinal()
{
    return montoFinal;
};
DTFecha Compra::getFecha()
{
    return fecha;
};
set<CompraProducto*> Compra::getParesCompraProducto()
{
    return paresCompraProducto;
}; //Este va?

void Compra::setFecha(DTFecha f)
{
    fecha = f;
};