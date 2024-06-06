#ifndef COMPRA
#define COMPRA

#include <set>
#include "ControladorCompra.h"
#include "CompraProducto.h"
#include "Cliente.h"

#include "DTFecha.h"



using namespace std;

//Forward
class controladorCompra;
class CompraProducto;
class Cliente;

class Compra
{
    private:
        float montoFinal;
        ControladorCompra* contCompra;
        set<CompraProducto*> paresCompraProducto;
        DTFecha fecha;
        Cliente * cliente;
    public:
        Compra(Cliente * _cliente); //Aca adentro habria que calcular monto final?
        ~Compra(); //Destructor

        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        set<CompraProducto*> getParesCompraProducto(); //Este va?
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
};

#endif