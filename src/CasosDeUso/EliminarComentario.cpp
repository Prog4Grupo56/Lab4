#include "../../include/CasosDeUso/CasosDeUso.h"

void EliminarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\t" << listaNicknames[i] << endl;
    }

    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;
    IU->seleccionarUsuario(nickname);
    
    vector<DTComentario> listaComentarios = IU->obtenerComentariosUsuario();

    cout << "Comentarios de " << nickname << ":" << endl;
    for (long unsigned int i = 0; i < listaComentarios.size(); i++){
        string id = to_string(listaComentarios[i].getIdComentario()).append("-");
        string fecha = listaComentarios[i].getFecha().toString().append(":");
        string c = listaComentarios[i].getComentario();

        cout << id.append(fecha) << endl;
        cout << "\t" << c << endl;
    }

    cout << "========" << endl;
    cout << "Seleccione uno: ";
    int idComentario;
    cin >> idComentario;
    IU->seleccionarComentario(idComentario);
    cout << "========" << endl;

    IU->eliminarComentario();

    cout << "Comentario y respuestas eliminadas exitosamente.";
}