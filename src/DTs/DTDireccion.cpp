#include "../../include/DTs/DTDireccion.h"

DTDireccion::DTDireccion(string _calle, int _numPuerta){
    calle = _calle;
    numeroPuerta = _numPuerta;
};

DTDireccion::~DTDireccion(){};

/*======= GETTERS ========*/
string DTDireccion::getCalle(){
    return calle;
}
int DTDireccion::getNumeroPuerta(){
    return numeroPuerta;
}

/*======= SETTERS ========*/
void DTDireccion::setCalle(string _calle){
    calle = _calle;
};
void DTDireccion::setNumeroPuerta(int _numPuerta){
    numeroPuerta = _numPuerta;
}