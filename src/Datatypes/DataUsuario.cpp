#include "../../include/Datatypes/DataUsuario.h"

DataUsuario::DataUsuario(){

}

DataUsuario::DataUsuario(string _nickname, string _contrasena, DTFecha _fecha){
    nickname = _nickname;
    contrasena = _contrasena;
    fecha = _fecha;
}

DataUsuario::~DataUsuario(){
    
};

string DataUsuario::getNickname() const{
    return nickname;
}
DTFecha DataUsuario::getFecha(){
    return fecha;
}
string DataUsuario::getContrasena(){
    return contrasena;
}