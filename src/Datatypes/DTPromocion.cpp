#include "../../include/Datatypes/DTPromocion.h"

DTPromocion::DTPromocion(string _nombre, string _descripcion, DTFecha _fechaVenc, float _descuento): fechaVenc(_fechaVenc){
    nombre = _nombre;
    descripcion = _descripcion;
    descuento = _descuento;
};

DTPromocion::DTPromocion(){};

DTPromocion::~DTPromocion(){};

/*======= GETTERS ========*/
string DTPromocion::getNombre(){
    return nombre;
}

string DTPromocion::getDescripcion(){
    return descripcion;
}

DTFecha DTPromocion::getFechaVenc(){
    return fechaVenc;
}

float DTPromocion::getDescuento(){
    return descuento;
}

string DTPromocion::toString(){
    return "Nombre: " + nombre + " | Descripcion: " + descripcion + " | Fecha de vencimiento:  " + fechaVenc.toString() + " | Descuento: " + to_string(descuento);
}

