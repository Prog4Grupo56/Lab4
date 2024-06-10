#include "../../include/Datatypes/ParCompraProductos.h"

ParCompraProductos::ParCompraProductos(float _montoF, set<DataProducto> _dProductos){
    fechaActual = DTFecha(0,0,0);
    dProductos = _dProductos;
    montoF = montoF;
}

ParCompraProductos::~ParCompraProductos(){}

DTFecha ParCompraProductos::getFecha(){
    return fechaActual;
}

float ParCompraProductos::getMontoFinal(){
    return montoF;
}

set<DataProducto> ParCompraProductos::getProductos(){
    return dProductos;
}