#include "../include/DataUsuario.h"

DataUsuario::DataUsuario(string _nickname, DTFecha _fecha){
    nickname = _nickname;
    fecha = _fecha;
}
DataUsuario::~DataUsuario(){
    
};

string DataUsuario::getNickname(){
    return nickname;
}
DTFecha DataUsuario::getFecha(){
    return fecha;
}
