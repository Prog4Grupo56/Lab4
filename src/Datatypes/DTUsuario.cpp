#include "../../include/Datatypes/DTUsuario.h"

DTUsuario::DTUsuario(){

}

DTUsuario::DTUsuario(string _nickname, string _contrasena, DTFecha _fecha){
    nickname = _nickname;
    contrasena = _contrasena;
    fecha = _fecha;
}

DTUsuario::~DTUsuario(){
    
};

string DTUsuario::getNickname() const{
    return nickname;
}
DTFecha DTUsuario::getFecha(){
    return fecha;
}
string DTUsuario::getContrasena(){
    return contrasena;
}

