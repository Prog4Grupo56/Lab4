#include "../../include/CasosDeUso/CasosDeUso.h"

void ConsultarProducto(){
    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    string codigo;
    vector<DataProducto> listadoDeProductos = IC->obtenerListaProductos();

    cout << "Nombres y códigos de los productos: " << endl;
    for(long unsigned int i = 0; i < listadoDeProductos.size(); i++){
        cout << "Nombre: " << listadoDeProductos[i].getNombre()  << " || Código: " << listadoDeProductos[i].getCodigo() << endl;
    }

    cout << "Introducir el código del producto a seleccionar: " << endl;
    cin >> codigo;

    Producto* productoSeleccionado = IC->obtenerProducto(codigo);
    string nicknameVendedor = productoSeleccionado->getVendedor()->getNickname();

    cout << "Información del producto:" << endl;
    cout << "Nombre: " << productoSeleccionado->getNombre() << endl;
    cout << "Precio: $" << productoSeleccionado->getPrecio() << endl;
    cout << "Cantidad: " << productoSeleccionado->getStock() << endl;
    cout << "Descripción: " << productoSeleccionado->getDescripcion() << endl;
    cout << "Categoría: " << productoSeleccionado->getCategoria() << endl;
    cout << "Vendedor: " << nicknameVendedor << endl;

}