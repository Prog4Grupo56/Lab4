#include "../../include/Datatypes/DTExpedienteVendedor.h"

DTExpedienteVendedor::DTExpedienteVendedor(){

}

DTExpedienteVendedor::DTExpedienteVendedor(DTVendedor vendedor, vector<DTProducto> productos, vector<DTPromocion> promos){
    dtVendedor = vendedor;
    vDTProd = productos;
    vDTProm = promos;
}

DTExpedienteVendedor::~DTExpedienteVendedor(){

}

DTVendedor DTExpedienteVendedor::getDTVendedor(){
    return dtVendedor;
}

vector<DTProducto> DTExpedienteVendedor::getDTProductos(){
    return vDTProd;
}

vector<DTPromocion> DTExpedienteVendedor::getDTPromociones(){
    return vDTProm;
}

