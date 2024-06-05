#include "../include/Vendedor.h"

Vendedor::Vendedor(string _nickname, string _contrasenia, DTFecha* _fecha, int _RUT):
Usuario(_nickname, _contrasenia, _fecha), RUT(_RUT){};

Vendedor::~Vendedor(){};

/*======= GETTERS ========*/
int Vendedor::getRUT(){
    return RUT;
};

/*======= SETTERS ========*/
void Vendedor::setRUT(int _RUT){
    RUT = _RUT;
};

