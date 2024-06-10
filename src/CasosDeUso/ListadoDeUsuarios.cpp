#include "../../include/CasosDeUso/CasosDeUso.h"

void ListadoDeUsuarios(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    
    set<DataUsuario> lista = IU->obtenerListadoUsuarios();
    set<DataUsuario>::iterator it;
    for (DataUsuario dataUsuario : lista){ //si hago abstracto a DataUsuario no puedo hacer esto
        cout << dataUsuario.toString() << endl;
    }
}
