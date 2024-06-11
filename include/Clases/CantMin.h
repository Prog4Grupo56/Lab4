#ifndef CANTMIN
#define CANTMIN

#include "Promocion.h"
#include "Producto.h"
#include "../Datatypes/DTFecha.h"

#include <string>

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

        int getCantidadMinima();

        DTFecha obtenerFechaPromocion();

};

#endif