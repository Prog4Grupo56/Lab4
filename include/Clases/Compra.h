#ifndef COMPRA
#define COMPRA

#include <set>
#include "ControladorCompra.h"
#include "CompraProducto.h"
#include "Cliente.h"

#include "../Datatypes/DTFecha.h"



using namespace std;

//Forward
class controladorCompra;
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
        set<CompraProducto*> getSetCompraProducto(); //Este va?
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
        void agregarProducto(Producto* p, Compra* c);
};

#endif