#ifndef COMPRA
#define COMPRA

#include <set>
#include "../Datatypes/DTFecha.h"
#include "Cliente.h"
#include "CompraProducto.h"

using namespace std;

//Forward

class Cliente;
class CompraProducto;

class Compra
{
    private:
        float montoFinal;
        DTFecha fecha;
        Cliente* clienteDeCompra;
        vector<CompraProducto*> compraProductos;
    public:
        Compra();
        Compra(Cliente* _clienteDeCompra, float _montoFinal);
        ~Compra(); //Destructor


        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        Cliente* getCliente();
        string getNickCliente();
        vector<CompraProducto*> obtenerCompraProductos();
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
        void setMontoFinal(float _montoFinal);
        void setCliente(Cliente* _cliente);

        void agregarCompraProducto(CompraProducto* compraProducto);

};

#endif