#include "../../include/Clases/DataCrearPromocion.h"

DataCrearPromocion::DataCrearPromocion(string _vendedor, DTPromocion _infoP, vector<ParCodigoCantidad> _prodCant): infoP(_infoP){
    vendedor = _vendedor;
    prodCant = _prodCant;
}
DataCrearPromocion::DataCrearPromocion(){
    infoP = DTPromocion();
}

DataCrearPromocion::~DataCrearPromocion(){};

/*======= GETTERS ========*/
string DataCrearPromocion::getVendedor(){
    return vendedor;
}

DTPromocion DataCrearPromocion::getInfoP(){
    return infoP;
}

vector<ParCodigoCantidad> DataCrearPromocion::getProdCant(){
    return prodCant;
}

/*======= SETTERS ========*/

void DataCrearPromocion::setVendedor(string _vendedor){
    vendedor = _vendedor;
}

void DataCrearPromocion::setInfoP(DTPromocion _infoP){
    infoP = _infoP;
}

void DataCrearPromocion::setProdCant(vector<ParCodigoCantidad> _prodCant){
    prodCant = _prodCant;
}

void DataCrearPromocion::agregar(ParCodigoCantidad par){
    prodCant.push_back(par);
}