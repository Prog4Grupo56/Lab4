#include "../../include/Datatypes/ParCodigoCantidad.h"

ParCodigoCantidad::~ParCodigoCantidad(){}

ParCodigoCantidad::ParCodigoCantidad(string _codigo, int _cantMinima){
    codigo = _codigo;
    cantidadMinima = _cantMinima;
}