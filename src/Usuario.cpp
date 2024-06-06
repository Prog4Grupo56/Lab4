#include "../include/Usuario.h"

Usuario::Usuario(string _nickname, string _contrasenia, DTFecha* _fecha){
    nickname = _nickname;
    contrasenia = _contrasenia;
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
DTFecha* Usuario::getFecha(){
    return fecha;
};

/*======= SETTERS ========*/
void Usuario::setNickname(string _nickname){
    nickname = _nickname;
};
void Usuario::setFecha(DTFecha* _fecha){
    fecha = _fecha;
};
void Usuario::setComentario(Comentario* c){
    comentarios.insert(c);
}

/*======= FUNCIONES ========*/
void Usuario::desvincularComentario(Comentario* c){
    comentarios.erase(c);
}



