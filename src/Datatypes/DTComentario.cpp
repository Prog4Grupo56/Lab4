#include "../../include/Datatypes/DTComentario.h"

DTComentario::DTComentario(string _comentario, DTFecha _fecha, int id, string _comentador, int _codigoProducto){
    comentario = _comentario;
    fecha = _fecha;
    idComentario = id;
    comentador = _comentador;
    codigoProducto = _codigoProducto;
}

DTComentario::~DTComentario(){};

string DTComentario::getComentario(){
    return comentario;
}
DTFecha DTComentario::getFecha(){
    return fecha;
}
int DTComentario::getIdComentario(){
    return idComentario;
}
int DTComentario::getCodigoProducto(){
    return codigoProducto;
}
string DTComentario::getComentador(){
    return comentador;
}

string DTComentario::toString(){
    return "Comentario: " + comentario + " | Fecha: " + fecha.toString() + " | Id: " + to_string(idComentario);
};