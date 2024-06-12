#include "../include/Vendedor.h"

Vendedor::Vendedor(string _nickname, string _contrasenia, DTFecha* _fecha, int _RUT):
Usuario(_nickname, _contrasenia, _fecha), RUT(_RUT){};

Vendedor::~Vendedor(){
    /*set<Cliente*>::iterator it;
    for (it=suscriptores.begin();it!=suscriptores.end();++it){
        Cliente* c = *it;
        c->eliminarSuscripcion(this);
    }*/
};

/*======= GETTERS ========*/
int Vendedor::getRUT(){
    return RUT;
};

/*======= SETTERS ========*/
void Vendedor::setRUT(int _RUT){
    RUT = _RUT;
};

void Vendedor::agregarSuscriptor(Cliente* c){
    suscriptores.insert(c);
}

/*void Vendedor::eliminarSuscriptor(Cliente* c){
    suscriptores.erase(c);
}*/

bool Vendedor::estaSuscrito(string nicknameCliente){
    set<Cliente*>::iterator it;
    for(it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Cliente* c = *it;
        if (c->getNickname() == nicknameCliente){
            return true;
        }
    }
    return false;
}
