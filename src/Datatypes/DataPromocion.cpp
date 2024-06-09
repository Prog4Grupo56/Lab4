#include "../../include/Datatypes/DataPromocion.h"

DataPromocion::DataPromocion(string _nombre, string _descripcion, DTFecha _fechaVenc, float _descuento): fechaVenc(_fechaVenc){
    nombre = _nombre;
    descripcion = _descripcion;
    descuento = _descuento;
};

DataPromocion::~DataPromocion(){};

/*======= GETTERS ========*/
string DataPromocion::getNombre(){
    return nombre;
}

string DataPromocion::getDescripcion(){
    return descripcion;
}

DTFecha DataPromocion::getFechaVenc(){
    return fechaVenc;
}

float DataPromocion::getDescuento(){
    return descuento;
}



