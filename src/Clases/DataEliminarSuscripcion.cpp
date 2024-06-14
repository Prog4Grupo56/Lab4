#include "../../include/Clases/DataEliminarSuscripcion.h"

DataEliminarSuscripcion::DataEliminarSuscripcion(){

};

DataEliminarSuscripcion::DataEliminarSuscripcion(string _nickname, vector<DataVendedor> _vendedores): vendedores(_vendedores){
    nickname = _nickname;
};

DataEliminarSuscripcion::~DataEliminarSuscripcion(){};

/*======= GETTERS ========*/
string DataEliminarSuscripcion::getNickname(){
    return nickname;
}

vector<DataVendedor> DataEliminarSuscripcion::getVendedores(){
    return vendedores;
}

/*======= SETTERS ========*/
void DataEliminarSuscripcion::setNickname(string _nickname){
    nickname = _nickname;
}

void DataEliminarSuscripcion::setVendedores(vector<DataVendedor> _vendedores){
    vendedores = _vendedores;
}