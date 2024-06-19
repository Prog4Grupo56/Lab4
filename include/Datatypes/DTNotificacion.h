#ifndef DTNOTIFICACION
#define DTNOTIFICACION

using namespace std;
#include <vector>

#include "DTProducto.h"


class DTNotificacion {
    private:
        string nombreVendedor, nombrePromocion;
        vector<DTProducto> productos;
    public:
        // Constructor
        DTNotificacion(string _nombreVendedor, string _nombrePromocion, vector<DTProducto> _productos);
        // Destructor
        ~DTNotificacion();

        // Getters
        string getNombreVendedor();
        string getNombrePromocion();
        vector<DTProducto> getProductos();

        string toString();
};

#endif