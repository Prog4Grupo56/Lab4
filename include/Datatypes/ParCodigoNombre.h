#ifndef PARCODIGONOMBRE
#define PARCODIGONOMBRE

#include <string>

using namespace std;

//Forward


class ParCodigoNombre
{
    private:
        string codigo;
        string nombre;
    public:
        ParCodigoNombre(string _nombre, string _codigo); //Constructor
        ~ParCodigoNombre(); //Destructor

        //Getters
        string getCodigo();
        string getNombre();
        
};

#endif