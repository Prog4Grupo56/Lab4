#include "../../include/Datatypes/DTCompraProductos.h"

DTCompraProductos::DTCompraProductos(){

}

DTCompraProductos::DTCompraProductos(float _montoF, vector<DTProducto> _dProductos, DTFecha _fecha){
    fechaActual = _fecha;
    dProductos = _dProductos;
    montoF = _montoF;
}

DTCompraProductos::~DTCompraProductos(){}

DTFecha DTCompraProductos::getFecha(){
    return fechaActual;
}

float DTCompraProductos::getMontoFinal(){
    return montoF;
}

vector<DTProducto> DTCompraProductos::getProductos(){
    return dProductos;
}