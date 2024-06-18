#include "../../include/Datatypes/DataComentario.h"

DataComentario::DataComentario(string _comentario, DTFecha _fecha, int id, string _comentador, int _codigoProducto){
    comentario = _comentario;
    fecha = _fecha;
    idComentario = id;
    comentador = _comentador;
    codigoProducto = _codigoProducto;
}

DataComentario::~DataComentario(){};

string DataComentario::getComentario(){
    return comentario;
}
DTFecha DataComentario::getFecha(){
    return fecha;
}
int DataComentario::getIdComentario(){
    return idComentario;
}
int DataComentario::getCodigoProducto(){
    return codigoProducto;
}
string DataComentario::getComentador(){
    return comentador;
}

string DataComentario::toString(){
    return "Comentario: " + comentario + " | Fecha: " + fecha.toString() + " | Id: " + to_string(idComentario);
};