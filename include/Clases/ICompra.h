#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <string>
#include <set>
#include "../Datatypes/ParCodigoCantidad.h"
#include "DataCrearPromocion.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/ParCompraProductos.h"

class ICompra {
public:

    virtual void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP) = 0;
    virtual set<DataProducto> obtenerListaProductos() = 0;
    virtual void agregarProducto(ParCodigoCantidad parCodCant) = 0;
    virtual ParCompraProductos obtenerInfoCompra() = 0;
    virtual set<string> obtenerListaNicknamesClientes() = 0;
    virtual void seleccionarCliente(string nickname) = 0;
    virtual void confirmarCompra() = 0;
    
};

#endif
