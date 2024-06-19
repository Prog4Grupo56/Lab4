#include "../../include/Datatypes/ParCompraProductos.h"

ParCompraProductos::ParCompraProductos(){

}

ParCompraProductos::ParCompraProductos(float _montoF, vector<DTProducto> _dProductos, DTFecha _fecha){
    fechaActual = _fecha;
    dProductos = _dProductos;
    montoF = _montoF;
}

ParCompraProductos::~ParCompraProductos(){}

DTFecha ParCompraProductos::getFecha(){
    return fechaActual;
}

float ParCompraProductos::getMontoFinal(){
    return montoF;
}

vector<DTProducto> ParCompraProductos::getProductos(){
    return dProductos;
}