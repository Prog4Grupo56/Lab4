#include "../../include/CasosDeUso/CasosDeUso.h"

void AltaDeProducto(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();

    cout << "Lista de vendedores: " << endl;

    vector<string> lista = IU->obtenerListaNicknameVendedores();
    for (unsigned int i = 0; i < lista.size(); i++){
        cout << "\t" << lista[i] << endl;
    }

    string vendedor;
    cout << "Ingrese un vendedor: ";
    cin >> vendedor;

    string nombreProducto;
    cout << "Ingrese el nombre del producto: ";
    cin >> nombreProducto;

    float precio;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    int stock;
    cout << "Ingrese el stock del producto: ";
    cin >> stock;

    string descripcion;
    cout << "Ingrese la descripcion del producto: ";
    cin >> descripcion;

    int categoria;
    cout << "Ingrese la categoria del producto: ";
    cin >> categoria;

    // IC->confirmarAltaProducto(vendedor, );



    

}