#include "../../include/Clases/CantMin.h"


CantMin::CantMin(){}
CantMin::CantMin(int _cantidadMinima, Producto* _producto){
    cantidadMinima = _cantidadMinima;
    producto = _producto;
}
CantMin::~CantMin(){}

int CantMin::getCantidadMinima(){
    return cantidadMinima;
}

Producto* CantMin::getProducto(){
    return producto;
}

Promocion* CantMin::getPromocion(){
    return promocion;
}

void CantMin::setCantidadMinima(int _cantidadMinima){
    cantidadMinima = _cantidadMinima;
}

void CantMin::setProducto(Producto* _producto){
    producto = _producto;
}

void CantMin::setPromocion(Promocion* _promocion){
    promocion = _promocion;
}

DTFecha CantMin::obtenerFechaPromocion(){
    return promocion->getFechaVenc();
}

bool CantMin::pertenecePromocion(string codigo){
    return false;
}