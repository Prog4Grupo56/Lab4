#include "../../include/CasosDeUso/CasosDeUso.h"

void ConsultaDeNotificaciones(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    vector<DTCliente> listaClientes = IU->obtenerListadoClientes();
    cout << "Clientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << "\t" << listaClientes[i].toString() << endl;
    }

    string nickname;
    cout << "\nIngrese su nickname: ";
    cin >> nickname;

    vector<DTNotificacion> notificaciones = IU->obtenerListaNotificaciones(nickname); 

    cout << "\nNotificaciones de " << nickname << ":" << endl;

    for(long unsigned int i = 0; i < notificaciones.size(); i++){
        cout << "\t" << notificaciones[i].toString() << endl;
    }
}