#include "../include/DataEliminarSuscripcion.h"

DataEliminarSuscripcion::DataEliminarSuscripcion(){

};

DataEliminarSuscripcion::DataEliminarSuscripcion(string _nickname, set<DataVendedor> _vendedores): vendedores(_vendedores){
    nickname = _nickname;
};

DataEliminarSuscripcion::~DataEliminarSuscripcion(){};

/*======= GETTERS ========*/
string DataEliminarSuscripcion::getNickname(){
    return nickname;
}

set<DataVendedor> DataEliminarSuscripcion::getVendedores(){
    return vendedores;
}

/*======= SETTERS ========*/
void DataEliminarSuscripcion::setNickname(string _nickname){
    nickname = _nickname;
}

void DataEliminarSuscripcion::setVendedores(set<DataVendedor> _vendedores){
    vendedores = _vendedores;
}