#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<DTCliente> listaClientes = IU->obtenerListadoClientes();
    vector<DTVendedor> listaVendedores = IU->obtenerListadoVendedores();

    cout << "Usuarios: " << endl;
    cout << "\t" << endl;
    cout << "\tClientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << "\t" << "\t"<< listaClientes[i].toString() << endl;
    }
    cout << "\tVendedores: " << endl;
    for (long unsigned int i = 0; i < listaVendedores.size(); i++){
        cout << "\t" << "\t" << listaVendedores[i].toString() << endl;
    }
}