#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include <set>
#include "Compra.h"


using namespace std;

class Compra;

class CompraProducto
{
    private:
        Compra* c;
        int cantidad;
        bool enviado;
    public:
        CompraProducto(Compra* _c, int _cantidad); //Constructor
        ~CompraProducto(); //Destructor

        //Getters
        Compra* getCompra();
        int getCantidad();
        bool getEstado();
        //Setters
        void setCompra(Compra* _c);
        void setCantidad(int cant);
        void setEstado(bool e);
};

#endif