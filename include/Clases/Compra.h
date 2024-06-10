#ifndef COMPRA
#define COMPRA

#include <set>
#include "../Datatypes/DTFecha.h"

using namespace std;

//Forward

class Cliente;

class Compra
{
    private:
        float montoFinal;
        DTFecha fecha;
        Cliente* clienteDeCompra;
    public:
        Compra();
        Compra(Cliente* _clienteDeCompra, int _montoFinal);
        ~Compra(); //Destructor

        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        Cliente* getCliente();
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
        void setMontoFinal(int _montoFinal);
        void setCliente(Cliente* _cliente);
};

#endif