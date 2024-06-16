#include "../../include/Datatypes/ParCompraProductos.h"

ParCompraProductos::ParCompraProductos(){

}

ParCompraProductos::ParCompraProductos(float _montoF, vector<DataProducto> _dProductos, DTFecha _fecha){
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

vector<DataProducto> ParCompraProductos::getProductos(){
    return dProductos;
}