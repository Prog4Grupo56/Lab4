#include "../../include/CasosDeUso/CasosDeUso.h"

void ConsultarProducto(){
    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    int codigo;
    vector<DataProducto> listadoDeProductos = IC->obtenerListaProductos();

    cout << "Nombres y códigos de los productos: " << endl;
    for(long unsigned int i = 0; i < listadoDeProductos.size(); i++){
        cout << "\tNombre: " << listadoDeProductos[i].getNombre() << "  |  Código: " << listadoDeProductos[i].getCodigo() << endl;
    }

    cout << "\nIntroducir el código del producto a seleccionar: ";
    cin >> codigo;

    Producto* productoSeleccionado = IC->obtenerProducto(codigo);
    string nicknameVendedor = productoSeleccionado->getVendedor()->getNickname();

    cout << "\nInformación del producto:" << endl;
    cout << "\t" << "Nombre: " << productoSeleccionado->getNombre() << endl;
    cout << "\t" << "Precio: $" << productoSeleccionado->getPrecio() << endl;
    cout << "\t" << "Cantidad: " << productoSeleccionado->getStock() << endl;
    cout << "\t" << "Descripción: " << productoSeleccionado->getDescripcion() << endl;
    string categ = productoSeleccionado->getCategoria() == Ropa ? "Ropa" : 
                   productoSeleccionado->getCategoria() == Electrodomesticos ? "Electrodomesticos" :
                   "Otros";
    cout << "\t" << "Categoría: " << categ << endl;
    cout << "\t" << "Vendedor: " << nicknameVendedor << endl;
}