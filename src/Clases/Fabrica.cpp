#include "../../include/Clases/Fabrica.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() { }

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

// Tanto para IUsuario como para ICompra hace falta hacer cambios en los .h y .cpp

IUsuario* Fabrica::getIUsuario() {
    //return ControladorUsuario::getInstancia();
    return NULL;
}

ICompra* Fabrica::getICompra() {
    //return ControladorCompra::getInstancia(); 
    return NULL;
}
