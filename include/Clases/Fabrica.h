#ifndef FABRICA_H
#define FABRICA_H

#include "IFecha.h"
#include "IUsuario.h"
#include "ICompra.h"
#include "ControladorCompra.h"
#include "ControladorUsuario.h"
#include "ControladorFecha.h"

class ControladorCompra;
class ControladorUsuario;

class Fabrica {
private:
    Fabrica();
    IUsuario* instanciaContorladorUsuario;
    ICompra* instanciaControladorCompra;
    IFecha* instanciaControladorFecha;
    static Fabrica* instancia;
public:
    IUsuario* getIUsuario();
    ICompra* getICompra();
    IFecha* getIFecha();
    static Fabrica* getInstance();
};

#endif
