#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<DataCliente> listaClientes = IU->obtenerListadoClientes();
    vector<DataVendedor> listaVendedores = IU->obtenerListadoVendedores();

    cout << "Usuarios: " << endl;
    cout << "========" << endl;
    cout << "Clientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << listaClientes[i].toString() << endl;
    }
    cout << "========" << endl;
    cout << "Vendedores: " << endl;
     for (long unsigned int i = 0; i < listaVendedores.size(); i++){
        cout << listaVendedores[i].toString() << endl;
    }
}