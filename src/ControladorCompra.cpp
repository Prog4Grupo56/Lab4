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
    /*
    set<Producto*>::iterator it;
    set<DataProducto> dps;
    for(it = productos.begin();it != productos.end(); it++)
    {
        Producto * prod = *it;
        int s = prod -> getStock();
        DataProducto dp = new DataProducto(...);
        dps.insert(dp);
    };
    return dps;
    */
};
void ControladorCompra::agregarProducto(ParCodigoCantidad* parCodCant)
{
    
};
ParCompraProductos ControladorCompra::obtenerInfoCompra()
{
};
set<string> ControladorCompra::obtenerListaNicknamesClientes()
{
    //Preciso controlador usuario
};
void ControladorCompra::seleccionarCliente(string nickname)
{
    //Preciso data info compra
};
void ControladorCompra::confirmarCompra()
{

};