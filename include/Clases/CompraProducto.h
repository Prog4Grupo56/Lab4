#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include <set>
#include "Compra.h"
#include "Producto.h"
#include "../Datatypes/DTNickFecha.h"


using namespace std;

class Compra;
class Producto;

class CompraProducto
{
    private:
        Compra* compra;
        int cantidad;
        bool enviado;
        Producto* producto;
    public:
        CompraProducto(Compra* _c, int _cantidad, Producto* _producto); //Constructor
        ~CompraProducto(); //Destructor

        //Getters
        Compra* getCompra();
        int getCantidad();
        bool getEstado()const;
        Producto* getProducto();
        //Setters
        void setCompra(Compra* _c);
        void setCantidad(int cant);
        void setEstado(bool e);
        void setProducto(Producto* _producto);

        DTNickFecha obtenerClienteFecha()const;
        bool esCompraDeCliente(string _cliente)const;
};

#endif