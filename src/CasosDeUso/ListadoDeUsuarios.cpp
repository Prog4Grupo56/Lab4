#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<DataCliente> listaClientes = IU->obtenerListadoClientes();
    vector<DataVendedor> listaVendedores = IU->obtenerListadoVendedores();

    cout << "Usuarios: " << endl;
    // for (long unsigned int i = 0; i < lista.size(); i++){
    //     cout << lista[i].toString() << endl;
    // }
}