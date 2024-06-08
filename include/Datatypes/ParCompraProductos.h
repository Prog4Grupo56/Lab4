#ifndef PARCOMPRAPRODUCTOS
#define PARCOMPRAPRODUCTOS

#include "../Datatypes/DataProducto.h"
#include "DTFecha.h"

#include <set>

using namespace std;

class ParCompraProductos
{
    private:
       DTFecha fechaActual;
       float montoF;
       set<DataProducto> dProductos;
    public:
        ParCompraProductos();
        ParCompraProductos(DTFecha _fechaActual, float _montoF, set<DataProducto> _dProductos); //Constructor
        ~ParCompraProductos(); //Destructor

        //Getters
        DTFecha getFecha();
        float getMontoFinal();
        set<DataProducto> getProductos();

};

#endif