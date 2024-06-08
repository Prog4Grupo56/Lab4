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
        Producto* p;
        Compra* c;
        int cantidadMinima;
        int cantidad;
        bool enviado;
    public:
        CompraProducto(Producto* _p,Compra* _c); //Constructor
        ~CompraProducto(); //Destructor

        //Getters
        Producto getProducto();
        Compra getCompra();
        int getCantMin();
        int getCantidad();
        bool getEstado();
        //Setters
        void setProducto(Producto* _p);
        void setCompra(Compra* _c);
        void sentCantMin(int cant);
        void setCantidad(int cant);
        void setEstado(bool e);
};

#endif