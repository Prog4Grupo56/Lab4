#include "../../include/Datatypes/ParCompraProductos.h"

ParCompraProductos::ParCompraProductos(){

}

ParCompraProductos::ParCompraProductos(float _montoF, vector<DataProducto> _dProductos, DTFecha fecha){
    fechaActual = fecha;
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

vector<DataProducto> ParCompraProductos::getProductos(){
    return dProductos;
}