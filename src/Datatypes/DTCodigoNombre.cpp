#include "../../include/Datatypes/DTCodigoNombre.h"

DTCodigoNombre::~DTCodigoNombre(){}

DTCodigoNombre::DTCodigoNombre(string _nombre, int _codigo){
    codigo = _codigo;
    nombre = _nombre;
}

int DTCodigoNombre::getCodigo(){
    return codigo;
}

string DTCodigoNombre::getNombre(){
    return nombre;
}