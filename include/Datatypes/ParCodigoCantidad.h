#ifndef PARCODIGOCANTIDAD
#define PARCODIGOCANTIDAD

#include <string>

using namespace std;

//Forward


class ParCodigoCantidad
{
    private:
        string codigo;
        int cantidad;
    public:
        ParCodigoCantidad(); //Constructor
        ParCodigoCantidad(string _codigo, int _cantMinima); //Constructor
        ~ParCodigoCantidad(); //Destructor

        //Getters
        string getCodigo() const;
        int getCantidad() const;
        //Setters
        void setCodigo(string _codigo);
        void setCantidadMinima(int _cantMinima);
};

#endif