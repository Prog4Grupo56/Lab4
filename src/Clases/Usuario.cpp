#include "../../include/Clases/Usuario.h"

Usuario::Usuario(string _nickname, string _contrasenia, DTFecha _fecha){
    nickname = _nickname;
    contrasena = _contrasenia;
    fecha = _fecha;
};

Usuario::~Usuario(){
    /*deslinkearme de ControladorUsuario*/

    //delete fecha;
    //eliminar mis comentarios

};

/*======= GETTERS ========*/
string Usuario::getNickname(){
    return nickname;
};
DTFecha Usuario::getFecha(){
    return fecha;
};
string Usuario::getContrasena(){
    return contrasena;
}
vector<DataComentario> Usuario::obtenerComentarios(){
    vector<DataComentario> lista;
    map<int, Comentario*>::iterator it;

    for (it = comentarios.begin(); it != comentarios.end(); ++it){
        string comentario = it->second->getComentario();
        DTFecha fecha = it->second->getFecha();
        int id = it->second->getIdComentario();
        string comentador = it->second->getComentador()->getNickname();
        int codigoProd = it->second->getProducto()->getCodigo();
        DataComentario dataC = DataComentario(comentario, fecha, id, comentador, codigoProd);
        lista.push_back(dataC);
    }

    return lista;
}

/*======= SETTERS ========*/
void Usuario::setNickname(string _nickname){
    nickname = _nickname;
};
void Usuario::setFecha(DTFecha _fecha){
    fecha = _fecha;
};
void Usuario::setComentario(Comentario* c){
    comentarios[c->getIdComentario()] = c;
}

/*======= FUNCIONES ========*/
void Usuario::desvincularComentario(Comentario* c){
    comentarios.erase(c->getIdComentario());
}

void Usuario::eliminarComentario(int idComentario){
    Comentario* comentario = comentarios[idComentario];
    comentario->desvincularPadre();
    comentario->eliminarComentario();
}


void Usuario::agregarComentarioNuevo(string comentario, Producto* pr, DTFecha _fecha, int idComentario){
    Comentario* comentarioNuevo = new Comentario(_fecha, comentario, idComentario, NULL, this, pr);
    comentarios[idComentario] = comentarioNuevo;
}

void Usuario::agregarComentarioRespuesta(string comentario, Producto* pr, DTFecha _fecha, int idComentario, Comentario* padre){
    Comentario* comentarioNuevo = new Comentario(_fecha, comentario, idComentario, padre, this, pr);
    comentarios[idComentario] = comentarioNuevo;
}

Comentario* Usuario::buscarComentario(int id){
    map<int,Comentario*>::iterator it;
    Comentario* res = NULL;
    for(it = comentarios.begin(); it != comentarios.end(); ++it){
        if (it->first == id){
            res = it->second;
        }
    }

    return res;
}