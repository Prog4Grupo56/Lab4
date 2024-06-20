#include "../../include/CasosDeUso/CasosDeUso.h"

void AltaDeProducto(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();

    cout << "Lista de vendedores: " << endl;

    vector<string> lista = IU->obtenerListaNicknameVendedores();
    for (unsigned int i = 0; i < lista.size(); i++){
        cout << "\tNickname: " << lista[i] << endl;
    }

    string vendedor;
    cout << "\nIngrese un nickname: ";
    cin >> vendedor;

    string nombreProducto;
    cout << "\nIngrese el nombre del producto: ";
    cin >> nombreProducto;

    float precio;
    cout << "\nIngrese el precio del producto: ";
    cin >> precio;

    int stock;
    cout << "\nIngrese el stock del producto: ";
    cin >> stock;

    string descripcion;
    cout << "\nIngrese la descripcion del producto: ";
    cin >> descripcion;

    int categoria;
    cout << "\nIngrese la categoria del producto: " << endl;
    cout << "\t" << "1. Ropa" << endl;
    cout << "\t" << "2. Electrodomesticos" << endl;
    cout << "\t" << "3. Otros" << endl;
    cout << "Ingrese una opcion: ";
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

    cout << "\nProducto ingresado exitosamente." << endl;

}