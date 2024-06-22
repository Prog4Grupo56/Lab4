#ifndef DTEXPEDIENTEVENDEDOR
#define DTEXPEDIENTEVENDEDOR

#include "DTFecha.h"
#include "DTVendedor.h"
#include "DTPromocion.h"
#include "DTProducto.h"
#include <vector>
#include <string>

class DTExpedienteVendedor{

    private:
        DTVendedor dtVendedor;
        vector<DTProducto> vDTProd;
        vector<DTPromocion> vDTProm;
    public:
        DTExpedienteVendedor();
        DTExpedienteVendedor(DTVendedor vendedor, vector<DTProducto> productos, vector<DTPromocion> promos);
        ~DTExpedienteVendedor();
        DTVendedor getDTVendedor();
        vector<DTProducto> getDTProductos();
        vector<DTPromocion> getDTPromociones();

};

#endif