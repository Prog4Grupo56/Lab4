#include "../../include/Clases/DataPromoSeleccionada.h"

DataPromoSeleccionada::DataPromoSeleccionada(){

};

DataPromoSeleccionada::DataPromoSeleccionada(set<DTProducto> _productos, DTVendedor _vendedor): productos(_productos), vendedor(_vendedor){

};

DataPromoSeleccionada::~DataPromoSeleccionada(){};

/*======= GETTERS ========*/
DTVendedor DataPromoSeleccionada::getVendedor(){
    return vendedor;
}

set<DTProducto> DataPromoSeleccionada::getProductos(){
    return productos;
}

/*======= SETTERS ========*/
void DataPromoSeleccionada::setVendedor(DTVendedor _vendedor){
    vendedor = _vendedor;
}

void DataPromoSeleccionada::setProductos(set<DTProducto> _productos){
    productos = _productos;
}