#include <iostream>
#ifndef DTPROMOCION
#define DTPROMOCION
using namespace std;

#include <string>
#include "DTFecha.h"


class DTPromocion{

    private:
        string nombre, descripcion;
        DTFecha fechaVenc;
        float descuento;

    public:
        //Constructor
        DTPromocion(string _nombre, string _descripcion, DTFecha _fechaVenc, float _descuento);
        DTPromocion();

        //Destructor
        ~DTPromocion();

        //Getters
        string getNombre();
        string getDescripcion();
        DTFecha getFechaVenc();
        float getDescuento();

        string toString();

};

#endif