#include "../../include/Clases/CantMin.h"


CantMin::CantMin(){}
CantMin::~CantMin(){}

int CantMin::getCantidadMinima(){
    return cantidadMinima;
}

DTFecha CantMin::obtenerFechaPromocion(){
    return promocion->getFechaVenc();
}