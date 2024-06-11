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
    public:
        Compra(); //Aca adentro habria que calcular monto final? no, creo
        ~Compra(); //Destructor
        
        /*======= GETTERS ========*/
        float getMontoFinal();
        DTFecha getFecha();
        /*======= SETTERS ========*/
        void setFecha(DTFecha f);
};

#endif