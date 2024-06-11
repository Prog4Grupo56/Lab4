#include "../../include/Clases/DataCrearPromocion.h"

DataCrearPromocion::DataCrearPromocion(string _vendedor, DataPromocion _infoP, vector<ParCodigoCantidad> _prodCant): infoP(_infoP){
    vendedor = _vendedor;
    prodCant = _prodCant;
}
DataCrearPromocion::DataCrearPromocion(){
    infoP = DataPromocion();
}

DataCrearPromocion::~DataCrearPromocion(){};

/*======= GETTERS ========*/
string DataCrearPromocion::getVendedor(){
    return vendedor;
}

DataPromocion DataCrearPromocion::getInfoP(){
    return infoP;
}

vector<ParCodigoCantidad> DataCrearPromocion::getProdCant(){
    return prodCant;
}

/*======= SETTERS ========*/

void DataCrearPromocion::setVendedor(string _vendedor){
    vendedor = _vendedor;
}

void DataCrearPromocion::setInfoP(DataPromocion _infoP){
    infoP = _infoP;
}

void DataCrearPromocion::setProdCant(vector<ParCodigoCantidad> _prodCant){
    prodCant = _prodCant;
}