#include "../../include/Datatypes/ParCodigoCantidad.h"

ParCodigoCantidad::~ParCodigoCantidad(){}

ParCodigoCantidad::ParCodigoCantidad(int _codigo, int _cantMinima){
    codigo = _codigo;
    cantidad = _cantMinima;
}

int ParCodigoCantidad::getCodigo() {
    return codigo;
}

int ParCodigoCantidad::getCantidad() {
    return cantidad;
}