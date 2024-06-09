#include <iostream>
#ifndef DTNOTIFICACION
#define DTNOTIFICACION
using namespace std;
#include <set>

#include "DataProducto.h"


class DTNotificacion {
    private:
        string nombreVendedor, nombrePromocion;
        set<DataProducto> productos;
    public:
        // Constructor
        DTNotificacion(string _nombreVendedor, string _nombrePromocion, set<DataProducto> _productos);
        // Destructor
        ~DTNotificacion();

        // Getters
        string getNombreVendedor();
        string getNombrePromocion();
        set<DataProducto> getProductos();
        
};

#endif