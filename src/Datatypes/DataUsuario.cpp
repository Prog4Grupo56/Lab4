#include "../../include/Datatypes/DataUsuario.h"

DataUsuario::DataUsuario(){

}

DataUsuario::DataUsuario(string _nickname, string _contrasena, DTFecha _fecha){
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

string DataUsuario::toString(){
    return "";
}

