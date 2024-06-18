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
    cout << "Ingrese la categoria del producto: " << endl;
    cout << "\t" << "1. Ropa" << endl;
    cout << "\t" << "2. Electrodomesticos" << endl;
    cout << "\t" << "3. Otros" << endl;
    cin >> categoria;
    
    Categoria categ;

    if (categoria == 1){
        categ = Ropa; 
    }
    else if (categoria == 2){
        categ = Electrodomesticos;
    }
    else{
        categ = Otros;
    }
    
    Vendedor* v = IU->obtenerVendedor(vendedor);
    IC->confirmarAltaProducto(categ, nombreProducto, descripcion, stock, precio, v);

    cout << "Producto ingresado exitosamente." << endl;

}