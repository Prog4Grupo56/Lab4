#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<string> lista = IU->obtenerListadoUsuarios();
    for (long unsigned int i = 0; i < lista.size(); i++){
        cout << lista[i] << endl;
    }
}