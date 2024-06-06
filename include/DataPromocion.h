#include <iostream>
#ifndef DATAPROMOCION
#define DATAPROMOCION
using namespace std;

#include <string>
#include "DTFecha.h"


class DataPromocion{

    private:
        string nombre, descripcion;
        DTFecha* fechaVenc;
        float descuento;

    public:
        //Constructor
        DataPromocion(string _nombre, string _descripcion, DTFecha* _fechaVenc, float _descuento);

        //Destructor
        ~DataPromocion();

        //Getters
        string getNombre();
        string getDescripcion();
        DTFecha* getFechaVenc();
        float getDescuento();

        //Setters
        void setNombre(string _nombre);
        void setDescripcion(string _descripcion);
        void setFechaVenc(DTFecha* _fechaVenc);
        void setDescuento(float _descuento);
};

#endif