#ifndef PARCOMPRAPRODUCTOS
#define PARCOMPRAPRODUCTOS

#include "Compra.h"
#include "Producto.h"
#include "DTFecha.h"

#include <set>

using namespace std;

//Forward
class Producto;
class Compra;
class DTFecha;

class ParCompraProductos
{
    private:
       Compra* compra;
       set<Producto*> productos;
    public:
        ParCompraProductos(Compra* _compra, Producto* _productos); //Constructor
        ~ParCompraProductos(); //Destructor

        //Getters
        DTFecha getFecha();
        float getMontoFinal();
        set<Producto*> getProductos();
        //Setters
        //Precisa setters?

};

#endif