#include "../include/ParNickFecha.h"

ParNickFecha::ParNickFecha(string _nickname, DTFecha _fecha): fecha(_fecha){
    nickname = _nickname;
}

ParNickFecha::~ParNickFecha(){};

string ParNickFecha::getNickname(){
    return nickname;
}

DTFecha ParNickFecha::getFecha(){
    return fecha;
}