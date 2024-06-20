#include "../../include/Datatypes/DTCodigoCantidad.h"

DTCodigoCantidad::~DTCodigoCantidad(){}

DTCodigoCantidad::DTCodigoCantidad(int _codigo, int _cantMinima){
    codigo = _codigo;
    cantidad = _cantMinima;
}

int DTCodigoCantidad::getCodigo() {
    return codigo;
}

int DTCodigoCantidad::getCantidad() {
    return cantidad;
}