#ifndef CANTMIN
#define CANTMIN

#include "Promocion.h"
#include "Producto.h"

#include "DTFecha.h"

#include <string>

class DTFecha;
class Producto;
class Promocion;


using namespace std;

class CantMin
{
    private:
       int cantidadMinima;
       Producto* producto;
       Promocion* promocion;
    public:
        CantMin(); //Constructor
        ~CantMin(); //Destructor

        DTFecha obtenerFechaPromocion();
        bool pertenecePromocion(string codigo);
};

#endif