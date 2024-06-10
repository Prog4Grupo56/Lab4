#include "../../include/Datatypes/ParNickFecha.h"

ParNickFecha::ParNickFecha(): fecha(DTFecha(0,0,0)){
    
}

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