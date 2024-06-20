#ifndef DTCOMPRAPRODUCTOS
#define DTCOMPRAPRODUCTOS

#include "../Datatypes/DTProducto.h"
#include "DTFecha.h"

#include <vector>

using namespace std;

class DTCompraProductos
{
    private:
       DTFecha fechaActual;
       float montoF;
       vector<DTProducto> dProductos;
    public:
        DTCompraProductos();
        DTCompraProductos(float _montoF, vector<DTProducto> _dProductos, DTFecha fecha); //Constructor
        ~DTCompraProductos(); //Destructor

        //Getters
        DTFecha getFecha();
        float getMontoFinal();
        vector<DTProducto> getProductos();

};

#endif