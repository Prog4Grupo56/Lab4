#include "../../include/CasosDeUso/CasosDeUso.h"

void EliminarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << listaNicknames[i] << endl;
    }

    cout << "========";
    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;
    IU->seleccionarUsuario(nickname);
    cout << "========";
    
    vector<DataComentario> listaComentarios = IU->obtenerComentariosUsuario();

    std::string comentarios = "Comentarios de ";
    comentarios.append(nickname.append(":"));
    cout << comentarios << endl;
    for (long unsigned int i = 0; i < listaComentarios.size(); i++){
        string id = to_string(listaComentarios[i].getIdComentario()).append("-");
        string fecha = listaComentarios[i].getFecha().toString().append(":");
        string c = listaComentarios[i].getComentario();

        cout << id.append(fecha) << endl;
        cout << c << endl;
    }

    cout << "========";
    cout << "Seleccione uno: ";
    int idComentario;
    cin >> idComentario;
    IU->seleccionarComentario(idComentario);
    cout << "========";

    IU->eliminarComentario();
}