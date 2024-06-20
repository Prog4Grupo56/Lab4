#include "../../include/CasosDeUso/CasosDeUso.h"

void EliminarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\tNickname: " << listaNicknames[i] << endl;
    }

    cout << "\nIngrese un nickname: ";
    string nickname;
    cin >> nickname;
    IU->seleccionarUsuario(nickname);
    
    vector<DTComentario> listaComentarios = IU->obtenerComentariosUsuario();

    cout << "\nComentarios de " << nickname << ":" << endl;
    for (long unsigned int i = 0; i < listaComentarios.size(); i++){
        string id = to_string(listaComentarios[i].getIdComentario()).append("-");
        string fecha = listaComentarios[i].getFecha().toString().append(":");
        string c = listaComentarios[i].getComentario();

        cout << "\nId: " << to_string(listaComentarios[i].getIdComentario()) << " | Fecha: " << listaComentarios[i].getFecha().toString() << endl;
        cout << "\tComentario: " << c << endl;
    }

    cout << "\nIngrese un Id: ";
    int idComentario;
    cin >> idComentario;
    IU->seleccionarComentario(idComentario);

    IU->eliminarComentario();

    cout << "\nComentario y respuestas eliminadas exitosamente.\n";
}