#include "../../include/Clases/DataEliminarSuscripcion.h"

DataEliminarSuscripcion::DataEliminarSuscripcion(){

};

DataEliminarSuscripcion::DataEliminarSuscripcion(string _nickname, vector<DTVendedor> _vendedores): vendedores(_vendedores){
    nickname = _nickname;
};

DataEliminarSuscripcion::~DataEliminarSuscripcion(){};

/*======= GETTERS ========*/
string DataEliminarSuscripcion::getNickname(){
    return nickname;
}

vector<DTVendedor> DataEliminarSuscripcion::getVendedores(){
    return vendedores;
}

/*======= SETTERS ========*/
void DataEliminarSuscripcion::setNickname(string _nickname){
    nickname = _nickname;
}

void DataEliminarSuscripcion::setVendedores(vector<DTVendedor> _vendedores){
    vendedores = _vendedores;
}