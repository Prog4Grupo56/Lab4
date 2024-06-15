#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<DataCliente> listaClientes = IU->obtenerListadoClientes();
    vector<DataVendedor> listaVendedores = IU->obtenerListadoVendedores();

    cout << "Usuarios: " << endl;
    cout << "\t" << endl;
    cout << "\tClientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << "\t" << listaClientes[i].toString() << endl;
    }
    cout << "\tVendedores: " << endl;
    for (long unsigned int i = 0; i < listaVendedores.size(); i++){
        cout << "\t" << listaVendedores[i].toString() << endl;
    }
    cout << "\n";
}