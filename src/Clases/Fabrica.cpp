#include "../../include/Clases/Fabrica.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() { }

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IUsuario* Fabrica::getIUsuario() {
    return ControladorUsuario::getInstancia();
}

ICompra* Fabrica::getICompra() {
    return ControladorCompra::getInstancia(); 
}

IFecha* Fabrica::getIFecha(){
    return ControladorFecha::getInstancia();
}