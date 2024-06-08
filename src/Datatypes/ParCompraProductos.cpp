#include "../../include/Datatypes/ParCompraProductos.h"

ParCompraProductos::ParCompraProductos(){

}

ParCompraProductos::ParCompraProductos(DTFecha _fechaActual, float _montoF, set<DataProducto> _dProductos){
    fechaActual = _fechaActual;
    dProductos = _dProductos;
    montoF = montoF;
}

ParCompraProductos::~ParCompraProductos(){
    
}

DTFecha ParCompraProductos::getFecha(){
    return fechaActual;
}

float ParCompraProductos::getMontoFinal(){
    return montoF;
}

set<DataProducto> ParCompraProductos::getProductos(){
    return dProductos;
}