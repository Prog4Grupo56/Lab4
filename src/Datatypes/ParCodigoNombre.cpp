#include "../../include/Datatypes/ParCodigoNombre.h"

ParCodigoNombre::~ParCodigoNombre(){}

ParCodigoNombre::ParCodigoNombre(string _nombre, int _codigo){
    codigo = _codigo;
    nombre = _nombre;
}

int ParCodigoNombre::getCodigo(){
    return codigo;
}

string ParCodigoNombre::getNombre(){
    return nombre;
}