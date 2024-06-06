#include <iostream>
#ifndef DTDIRECCION
#define DTDIRECCION
using namespace std;

class DTDireccion {
    private:
        string calle;
        int numeroPuerta;
    public:
        // Constructor
        DTDireccion(string _calle, int _numPuerta);
        // Destructor
        ~DTDireccion();
        // Getters
        string getCalle();
        int getNumeroPuerta();
        // Setters
        void setCalle(string _calle);
        void setNumeroPuerta(int _numPuerta);
};

#endif