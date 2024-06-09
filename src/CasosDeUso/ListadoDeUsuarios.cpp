#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    set<DataUsuario> lista = IU->obtenerListadoUsuarios();

    for (DataUsuario dataUsuario : lista){
        cout << dataUsuario.toString() << endl;
    }
}
