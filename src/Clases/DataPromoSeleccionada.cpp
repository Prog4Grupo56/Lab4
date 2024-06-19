#include "../../include/Clases/DataPromoSeleccionada.h"

DataPromoSeleccionada::DataPromoSeleccionada(){

};

DataPromoSeleccionada::DataPromoSeleccionada(set<DataProducto> _productos, DTVendedor _vendedor): productos(_productos), vendedor(_vendedor){

};

DataPromoSeleccionada::~DataPromoSeleccionada(){};

/*======= GETTERS ========*/
DTVendedor DataPromoSeleccionada::getVendedor(){
    return vendedor;
}

set<DataProducto> DataPromoSeleccionada::getProductos(){
    return productos;
}

/*======= SETTERS ========*/
void DataPromoSeleccionada::setVendedor(DTVendedor _vendedor){
    vendedor = _vendedor;
}

void DataPromoSeleccionada::setProductos(set<DataProducto> _productos){
    productos = _productos;
}