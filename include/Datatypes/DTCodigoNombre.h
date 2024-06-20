#ifndef PARCODIGONOMBRE
#define PARCODIGONOMBRE

#include <string>

using namespace std;

//Forward


class DTCodigoNombre
{
    private:
        int codigo;
        string nombre;
    public:
        DTCodigoNombre(string _nombre, int _codigo); //Constructor
        ~DTCodigoNombre(); //Destructor

        //Getters
        int getCodigo();
        string getNombre();
        
};

#endif