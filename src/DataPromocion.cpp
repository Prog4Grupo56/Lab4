#include "../include/DataPromocion.h"

DataPromocion::DataPromocion(string _nombre, string _descripcion, DTFecha* _fechaVenc, float _descuento){
    nombre = _nombre;
    descripcion = _descripcion;
    fechaVenc = _fechaVenc;
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

DTFecha* DataPromocion::getFechaVenc(){
    return fechaVenc;
}

float DataPromocion::getDescuento(){
    return descuento;
}

/*======= SETTERS ========*/
void DataPromocion::setNombre(string _nombre){
    nombre = _nombre;
}

void DataPromocion::setDescripcion(string _descripcion){
    descripcion = _descripcion;
}

void DataPromocion::setFechaVenc(DTFecha* _fechaVenc){
    fechaVenc = _fechaVenc;
}

void DataPromocion::setDescuento(float _descuento){
    descuento = _descuento;
}



