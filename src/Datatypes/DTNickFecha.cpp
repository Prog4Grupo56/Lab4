#include "../../include/Datatypes/DTNickFecha.h"

DTNickFecha::DTNickFecha(): fecha(DTFecha(0,0,0)){
    
}

DTNickFecha::DTNickFecha(string _nickname, DTFecha _fecha): fecha(_fecha){
    nickname = _nickname;
}

DTNickFecha::~DTNickFecha(){};

string DTNickFecha::getNickname(){
    return nickname;
}

DTFecha DTNickFecha::getFecha(){
    return fecha;
}