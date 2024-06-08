#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "ICompra.h"
#include "ControladorCompra.h"


class Fabrica {
private:
    Fabrica();
    IUsuario* instanciaContorladorUsuario;
    ICompra* instanciaControladorCompra;
    static Fabrica* instancia;
public:
    IUsuario* getIUsuario();
    ICompra* getICompra();
    static Fabrica* getInstance();
};

#endif
