#include "../include/ControladorCompra.h"

ControladorCompra* ControladorCompra::instancia = NULL;

ControladorCompra::ControladorCompra()
{

};
ControladorCompra::~ControladorCompra()
{

};


ControladorCompra * ControladorCompra::getInstancia()
{
    if(instancia == NULL)
        instancia = new ControladorCompra();
    return instancia;
};
void ControladorCompra::crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP)
{
};
set<DataProducto> ControladorCompra::obtenerListaProductos()
{
};
void ControladorCompra::agregarProducto(ParCodigoCantidad* parCodCant)
{
};
ParCompraProductos ControladorCompra::obtenerInfoCompra()
{
};
set<string> ControladorCompra::obtenerListaNicknamesClientes()
{
};
void ControladorCompra::seleccionarCliente(string nickname)
{
};
void ControladorCompra::confirmarCompra()
{
};