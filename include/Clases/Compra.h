#ifndef COMPRA
#define COMPRA

#include <set>
#include "ControladorCompra.h"
#include "CompraProducto.h"
#include "Cliente.h"

#include "../Datatypes/DTFecha.h"



using namespace std;

//Forward
class ControladorCompra;
class CompraProducto;

class Compra
{
    private:
        float montoFinal;
        ControladorCompra* contCompra;
        set<CompraProducto*> SetCompraProducto;
        DTFecha fecha;
        Cliente* cliente;
    public:
        Compra(Cliente* _cliente, float _montoFinal );
        ~Compra(); //Destructor

        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        set<CompraProducto*> getSetCompraProducto(); 
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
        void agregarProducto(Compra* c, int cantidad);
};

#endif