#ifndef PARCODIGOCANTIDAD
#define PARCODIGOCANTIDAD

#include <string>

using namespace std;

//Forward


class ParCodigoCantidad
{
    private:
        string codigo;
        int cantidadMinima;
    public:
        ParCodigoCantidad(string _codigo, int _cantMinima); //Constructor
        ~ParCodigoCantidad(); //Destructor

        //Getters
        string getCodigo();
        int getCantidadMinima();
        //Setters
        void setCodigo(string s);
        void setCantidadMinima(int c);
};

#endif