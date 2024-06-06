#include "../include/Comentario.h"

Comentario::Comentario(DTFecha* _fecha, string _comentario, int _idComentario, Comentario* _padre, Usuario* _comentador){
    fecha = _fecha;
    comentario = _comentario;
    idComentario = _idComentario;
    //respuestas.empty(); // Ya lo inicializa como set vacio
    padre = _padre;
    comentador = _comentador;
};

Comentario::~Comentario(){
    delete fecha;
};

/*======= GETTERS ========*/
DTFecha* Comentario::getFecha(){
    return fecha;
};
string Comentario::getComentario(){
    return comentario;
};
int Comentario::getIdComentario(){
    return idComentario;
};
set<Comentario*> Comentario::getRespuestas(){
    return respuestas;
};
Comentario* Comentario::getPadre(){
    return padre;
};

/*======= SETTERS ========*/
void Comentario::setComentario(string _comentario){
    comentario = _comentario;
};
void Comentario::setRespuesta(Comentario* respuesta){
    respuestas.insert(respuesta);
};
void Comentario::setPadre(Comentario* p){
    padre = p;
};

/*======= FUNCIONES ========*/
void Comentario::desvincularHijo(Comentario* c){
    respuestas.erase(c);
}

void Comentario::desvincularPadre(){
    if (padre != NULL){ //si c (this) es respuesta de padre
        padre->desvincularHijo(this);
    }
};

void Comentario::eliminarComentario(){
    comentador->desvincularComentario(this); //desvincula al comentario del usuario

    set<Comentario*>::iterator it;
    for (it = respuestas.begin(); it != respuestas.end(); ++it){ //recorro el set
        Comentario* respuesta = *it;
        respuesta->eliminarComentario();
    }
    delete this; //no funca parece
}

//falta setId y setFecha, pero creo que no se usan
