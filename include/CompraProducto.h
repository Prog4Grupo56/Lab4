#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include <set>
#include "Compra.h"
#include "Producto.h"


using namespace std;

class Producto;
class Compra;

class CompraProducto
{
    private:
        Producto p;
        Compra c;
        int cantidadMinima;
        int cantidad;
        bool enviado;
    public:
        CompraProducto(Producto* _p,Compra* _c, int _cantidadMinima); //Constructor
        ~CompraProducto(); //Destructor

        //Getters
        Producto getProducto();
        Compra getCompra();
        int getCantMin();
        int getCantidad();
        bool getEstado();
        //Setters
        void setProducto();
        void setCompra();
        void sentCantMin();
        void setCantidad();
        void setEstado();
};

#endif