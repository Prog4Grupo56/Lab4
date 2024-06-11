#include <iostream>
#ifndef DTNOTIFICACION
#define DTNOTIFICACION
using namespace std;
#include <vector>

#include "DataProducto.h"


class DTNotificacion {
    private:
        string nombreVendedor, nombrePromocion;
        vector<DataProducto> productos;
    public:
        // Constructor
        DTNotificacion(string _nombreVendedor, string _nombrePromocion, vector<DataProducto> _productos);
        // Destructor
        ~DTNotificacion();

        // Getters
        string getNombreVendedor();
        string getNombrePromocion();
        vector<DataProducto> getProductos();
        
};

#endif