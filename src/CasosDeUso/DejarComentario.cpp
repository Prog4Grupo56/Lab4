#include "../../include/CasosDeUso/CasosDeUso.h"

void DejarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << listaNicknames[i] << endl;
    }

    cout << "========";
    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;

    cout << "========";

    vector<DataProducto> listaProductos = IC->obtenerListaProductos();
    for (long unsigned int i = 0; i < listaProductos.size(); i++){
        cout << listaProductos[i].getNombre() << endl;
    }

}