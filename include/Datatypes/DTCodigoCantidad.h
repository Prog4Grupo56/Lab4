#ifndef DTCODIGOCANTIDAD
#define DTCODIGOCANTIDAD

#include <string>

using namespace std;

//Forward


class DTCodigoCantidad
{
    private:
        int codigo;
        int cantidad;
    public:
    
        DTCodigoCantidad(int _codigo, int _cantMinima); //Constructor

        ~DTCodigoCantidad(); //Destructor

        //Getters
        int getCodigo();
        int getCantidad();

};

#endif