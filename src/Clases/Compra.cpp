#include "../../include/Clases/Compra.h"



Compra::Compra(Cliente* _cliente, float _montoFinal )
{
    cliente = _cliente;
    montoFinal = _montoFinal;
    contCompra = ControladorCompra::getInstancia();

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
set<CompraProducto*> Compra::getSetCompraProducto()
{
    return SetCompraProducto;
}; //Este va?

void Compra::setFecha(DTFecha f)
{
    fecha = f;
};

void Compra::agregarProducto(Compra* c, int cantidad)
{
    SetCompraProducto.insert(new CompraProducto(c,cantidad));
};