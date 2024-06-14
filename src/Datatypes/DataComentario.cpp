#include "../../include/Datatypes/DataComentario.h"

DataComentario::DataComentario(string _comentario, DTFecha _fecha, int id, string _comentador, string _codigoProducto){
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
string DataComentario::getCodigoProducto(){
    return codigoProducto;
}
string DataComentario::getComentador(){
    return comentador;
}

string DataComentario::toString(){
    return comentario + ", " + fecha.toString() + ", " + to_string(idComentario) + ", " + comentador + ", " + codigoProducto;
};