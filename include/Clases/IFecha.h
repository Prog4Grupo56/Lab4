#ifndef IFECHA
#define IFECHA

#include "../Datatypes/DTFecha.h"

class Vendedor;

class IFecha {
public:
    virtual void limpiarCF() = 0;
    virtual DTFecha getFechaActual() = 0;
    virtual void setFechaActual(DTFecha _fecha) = 0;
    
};

#endif
