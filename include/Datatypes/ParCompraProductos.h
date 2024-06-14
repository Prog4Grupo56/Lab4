#ifndef PARCOMPRAPRODUCTOS
#define PARCOMPRAPRODUCTOS

#include "../Datatypes/DataProducto.h"
#include "DTFecha.h"

#include <vector>

using namespace std;

class ParCompraProductos
{
    private:
       DTFecha fechaActual;
       float montoF;
       vector<DataProducto> dProductos;
    public:
        ParCompraProductos();
        ParCompraProductos(float _montoF, vector<DataProducto> _dProductos, DTFecha fecha); //Constructor
        ~ParCompraProductos(); //Destructor

        //Getters
        DTFecha getFecha();
        float getMontoFinal();
        vector<DataProducto> getProductos();

};

#endif