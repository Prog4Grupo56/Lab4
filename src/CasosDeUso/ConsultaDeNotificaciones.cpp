#include "../../include/CasosDeUso/CasosDeUso.h"

void ConsultaDeNotificaciones(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    string nickname;
    cout << "Ingrese su nickname: " << endl;
    cin >> nickname;

    vector<DTNotificacion> notificaciones = IU->obtenerListaNotificaciones(nickname); 

    cout << "Notificaciones de " << nickname << ":" << endl;

    for(long unsigned int i = 0; i < notificaciones.size(); i++){
        cout << notificaciones[i].toString() << endl;
    }
}