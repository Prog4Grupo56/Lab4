#ifndef PARCODIGOCANTIDAD
#define PARCODIGOCANTIDAD

#include <string>

using namespace std;

//Forward


class ParCodigoCantidad
{
    private:
        int codigo;
        int cantidad;
    public:
    
        ParCodigoCantidad(int _codigo, int _cantMinima); //Constructor

        ~ParCodigoCantidad(); //Destructor

        //Getters
        int getCodigo();
        int getCantidad();

};

#endif