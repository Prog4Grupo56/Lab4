#include "../../include/Clases/ControladorFecha.h"

ControladorFecha* ControladorFecha::instancia = nullptr;

ControladorFecha::ControladorFecha(){
    
}

ControladorFecha* ControladorFecha::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorFecha();
    }
    return instancia;
}

ControladorFecha::~ControladorFecha(){

}

DTFecha ControladorFecha::getFechaActual(){
    return fechaActual;
}

void ControladorFecha::setFechaActual(DTFecha _fecha){
    fechaActual = _fecha;
}