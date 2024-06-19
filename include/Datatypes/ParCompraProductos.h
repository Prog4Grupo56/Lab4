#ifndef PARCOMPRAPRODUCTOS
#define PARCOMPRAPRODUCTOS

#include "../Datatypes/DTProducto.h"
#include "DTFecha.h"

#include <vector>

using namespace std;

class ParCompraProductos
{
    private:
       DTFecha fechaActual;
       float montoF;
       vector<DTProducto> dProductos;
    public:
        ParCompraProductos();
        ParCompraProductos(float _montoF, vector<DTProducto> _dProductos, DTFecha fecha); //Constructor
        ~ParCompraProductos(); //Destructor

        //Getters
        DTFecha getFecha();
        float getMontoFinal();
        vector<DTProducto> getProductos();

};

#endif