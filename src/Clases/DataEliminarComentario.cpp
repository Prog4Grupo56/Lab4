#include "../../include/Clases/DataEliminarComentario.h"

DataEliminarComentario::DataEliminarComentario(string _nickname, int _idComentario){
    nickname = _nickname;
    idComentario = _idComentario;
}

DataEliminarComentario::~DataEliminarComentario(){}

string DataEliminarComentario::getNickname(){
    return nickname;
}

int DataEliminarComentario::getIdComentario(){
    return idComentario;
}

void DataEliminarComentario::setNickname(string _nickname){
    nickname = _nickname;
}

void DataEliminarComentario::setIdComentario(int id){
    idComentario = id;
}