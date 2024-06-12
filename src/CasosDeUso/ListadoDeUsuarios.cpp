#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    vector<DataUsuario> lista = IU->obtenerListadoUsuarios();

    cout << "Usuarios: " << endl;
    for (long unsigned int i = 0; i < lista.size(); i++){
        cout << lista[i].toString() << endl;
    }
}