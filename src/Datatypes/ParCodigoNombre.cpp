#include "../../include/Datatypes/ParCodigoNombre.h"

ParCodigoNombre::~ParCodigoNombre(){}

ParCodigoNombre::ParCodigoNombre(string codigo_, int nombre_){
    codigo = codigo_;
    nombre = nombre_;
}

string ParCodigoNombre::getCodigo(){
    return codigo;
}

string ParCodigoNombre::getNombre(){
    return nombre;
}