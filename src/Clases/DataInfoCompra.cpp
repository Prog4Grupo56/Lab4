#include "../../include/Clases/DataInfoCompra.h"

DataInfoCompra::DataInfoCompra(string _cliente){
    cliente = _cliente;
}

DataInfoCompra::DataInfoCompra(string _cliente, float _montoF, vector<ParCodigoCantidad> _prodCant): prodCant(_prodCant){
    cliente = _cliente;
    montoF = _montoF;
};

DataInfoCompra::~DataInfoCompra(){};

/*======= GETTERS ========*/
string DataInfoCompra::getCliente(){
    return cliente;
}

float DataInfoCompra::getMontoF(){
    return montoF;
}

vector<ParCodigoCantidad> DataInfoCompra::getProdCant(){
    return prodCant;
}

/*======= SETTERS ========*/

void DataInfoCompra::setCliente(string _cliente){
    cliente = _cliente;
}

void DataInfoCompra::setMontoF(float _montoF){
    montoF = _montoF;
}

void DataInfoCompra::setProdCant(vector<ParCodigoCantidad> _prodCant){
    prodCant = _prodCant;
}