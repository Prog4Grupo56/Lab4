#include "../include/DataCrearPromocion.h"

DataCrearPromocion::DataCrearPromocion(string _vendedor, DataPromocion _infoP/*, set<ParCodigoCompra> _prodCant*/): infoP(_infoP){
    vendedor = _vendedor;
    //prodCant = _prodCant;
};

DataCrearPromocion::~DataCrearPromocion(){};

/*======= GETTERS ========*/
string DataCrearPromocion::getVendedor(){
    return vendedor;
}

DataPromocion DataCrearPromocion::getInfoP(){
    return infoP;
}

/*set<ParCodigoCompra> DataCrearPromocion::getProdCant(){
    return prodCant;
}*/