#ifndef DTEXPEDIENTECLIENTE
#define DTEXPEDIENTECLIENTE

#include "DTFecha.h"
#include "DTCliente.h"
#include "DTCompraProductos.h"
#include <string>

class DTExpedienteCliente{

    private:
        DTCliente dtCliente;
        vector<DTCompraProductos> vDTCompraProductos;
    public:
        DTExpedienteCliente();
        DTExpedienteCliente(vector<DTCompraProductos> _vDTCompraProductos, DTCliente _cliente );
        ~DTExpedienteCliente();
        DTCliente getDTCliente();
        vector<DTCompraProductos> getVDTCompraProductos();

};

#endif