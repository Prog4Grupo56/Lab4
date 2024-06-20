#include "../../include/CasosDeUso/CasosDeUso.h"

void ExpedienteDeUsuario(){

    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    ListadoDeUsuarios();

    string nickname;

    cout << "\nIngrese un nickname: ";
    cin >> nickname;

    string info = IU->obtenerInfoUsuario(nickname);

    cout << "\n" << info << "\n";

}