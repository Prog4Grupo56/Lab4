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
        set<CompraProducto*> paresCompraProducto;
        DTFecha fecha;
    public:
        Compra(); //Aca adentro habria que calcular monto final? no, creo
        ~Compra(); //Destructor
        
        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        set<CompraProducto*> getParesCompraProducto(); //Este va?
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
};

#endif