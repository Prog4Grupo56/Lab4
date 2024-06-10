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
        Producto* producto;
        Compra* compra;
        int cantidadMinima;
        int cantidad;
        bool enviado;
    public:
        CompraProducto(Compra* _compra, int cant); //Constructor
        ~CompraProducto(); //Destructor

        //Getters
        Producto* getProducto();
        Compra* getCompra();
        int getCantMin();
        int getCantidad();
        bool getEstado();
        //Setters
        void setProducto(Producto* _p);
        void setCompra(Compra* _c);
        void setCantMin(int cant);
        void setCantidad(int cant);
        void setEstado(bool e);
};

#endif