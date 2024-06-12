#include "../../include/DTs/DataComentario.h"

DataComentario::DataComentario(string _comentario, DTFecha* _fecha, int id){
    comentario = _comentario;
    fecha = _fecha;
    idComentario = id;
}

DataComentario::~DataComentario(){};

string DataComentario::getComentario(){
    return comentario;
}
DTFecha* DataComentario::getFecha(){
    return fecha;
}
int DataComentario::getIdComentario(){
    return idComentario;
}