#include "../../include/Clases/Comentario.h"

Comentario::Comentario(DTFecha _fecha, string _comentario, int _idComentario, Comentario* _padre, Usuario* _comentador, int _codigo){
    fecha = _fecha;
    comentario = _comentario;
    idComentario = _idComentario;
    //respuestas.empty(); // Ya lo inicializa como set vacio
    padre = _padre;
    comentador = _comentador;
    codProducto = _codigo;
};

Comentario::~Comentario(){};

/*======= GETTERS ========*/
DTFecha Comentario::getFecha(){
    return fecha;
};
string Comentario::getComentario(){
    return comentario;
};
int Comentario::getIdComentario(){
    return idComentario;
};
map<int,Comentario*> Comentario::getRespuestas(){
    return respuestas;
};
Comentario* Comentario::getPadre(){
    return padre;
};
int Comentario::getProducto(){
    return codProducto;
}
Usuario* Comentario::getComentador(){
    return comentador;
}
/*======= SETTERS ========*/
//falta setId y setFecha, pero creo que no se usan
void Comentario::setComentario(string _comentario){
    comentario = _comentario;
};
void Comentario::setRespuesta(Comentario* respuesta){
    respuestas[respuesta->getIdComentario()] = respuesta;
};
void Comentario::setPadre(Comentario* p){
    padre = p;
};

/*======= FUNCIONES ========*/
void Comentario::desvincularHijo(Comentario* c){
    respuestas.erase(c->getIdComentario());
}

void Comentario::desvincularPadre(){
    if (padre != NULL){ //si c (this) es respuesta de padre
        padre->desvincularHijo(this);
        padre = NULL;
    }
};

void Comentario::eliminarComentario(){
    comentador->desvincularComentario(this); //desvincula al comentario del usuario

    map<int,Comentario*>::iterator it;
    
    for (it = respuestas.begin(); it != respuestas.end(); ++it){
        Comentario* respuesta = it->second;
        respuesta->eliminarComentario();
    }
    delete this;
}

string Comentario::obtenerNicknameComentador(){
    return comentador->getNickname();
}
int Comentario::obtenerCodigoProdComentado(){
    return codProducto;
}

