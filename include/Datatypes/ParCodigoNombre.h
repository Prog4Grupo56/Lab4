#ifndef PARCODIGONOMBRE
#define PARCODIGONOMBRE

#include <string>

using namespace std;

//Forward


class ParCodigoNombre
{
    private:
        int codigo;
        string nombre;
    public:
        ParCodigoNombre(string _nombre, int _codigo); //Constructor
        ~ParCodigoNombre(); //Destructor

        //Getters
        int getCodigo();
        string getNombre();
        
};

#endif