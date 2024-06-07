#include "../include/DataInfoCompra.h"

DataInfoCompra::DataInfoCompra(string _cliente, float _montoF/*, set<ParCodigoCantidad> prodCant*/)/*: prodCant(_prodCant)*/{
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

/*set<ParCodigoCantidad> DataInfoCompra::getProdCant(){
    return _prodCant;
}*/

//CAPAZ TIENE SETTERS