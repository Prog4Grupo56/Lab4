#include "../../include/Datatypes/DTExpedienteCliente.h"

DTExpedienteCliente::DTExpedienteCliente(){

}

DTExpedienteCliente::DTExpedienteCliente(vector<DTCompraProductos> _vDTCompraProductos, DTCliente _cliente): dtCliente(_cliente) {
    vDTCompraProductos = _vDTCompraProductos;
}

DTExpedienteCliente::~DTExpedienteCliente(){};

DTCliente DTExpedienteCliente::getDTCliente(){
    return dtCliente;
}

vector<DTCompraProductos> DTExpedienteCliente::getVDTCompraProductos(){
    return vDTCompraProductos;
}