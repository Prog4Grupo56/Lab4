#include "../../include/Datatypes/ParCodigoCantidad.h"

ParCodigoCantidad::~ParCodigoCantidad(){}

ParCodigoCantidad::ParCodigoCantidad(string _codigo, int _cantMinima){
    codigo = _codigo;
    cantidad = _cantMinima;
}

string ParCodigoCantidad::getCodigo() {
    return codigo;
}

int ParCodigoCantidad::getCantidad() {
    return cantidad;
}