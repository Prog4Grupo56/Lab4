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
        CantMin();
        CantMin(int _cantidadMinima, Producto* _producto);
        ~CantMin();

        int getCantidadMinima();
        Producto* getProducto();
        Promocion* getPromocion();

        void setCantidadMinima(int _cantidadMinima);
        void setProducto(Producto* _producto);
        void setPromocion(Promocion* _promocion);

        DTFecha obtenerFechaPromocion();
        bool pertenecePromocion(int codigo);
        

};

#endif