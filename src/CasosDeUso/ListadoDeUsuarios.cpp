#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    set<DataUsuario> lista = IU->obtenerListadoUsuarios();
    for (DataUsuario dataUsuario : lista){ //si hago abstracto a DataUsuario no puedo hacer esto
        cout << dataUsuario.toString() << endl;
    }
}
