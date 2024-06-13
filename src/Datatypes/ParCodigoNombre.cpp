#include "../../include/Datatypes/ParCodigoNombre.h"

ParCodigoNombre::~ParCodigoNombre(){}

ParCodigoNombre::ParCodigoNombre(string _nombre, string _codigo){
    codigo = _codigo;
    nombre = _nombre;
}

string ParCodigoNombre::getCodigo(){
    return codigo;
}

string ParCodigoNombre::getNombre(){
    return nombre;
}