#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <string>
#include <set>
#include "ParCodigoCantidad.h"
#include "DataCrearPromocion.h" // está el .h pero no esta implementado
#include "DataProducto.h"       // está el .h pero no esta implementado
#include "DataVendedor.h"
#include "ParCompraProductos.h"

class ICompra {
public:

    //virtual void crearPromocion(Vendedor v, DataCrearPromocion dataCrearP) = 0;   // está el .h pero no esta implementado
    //virtual set<DataProducto> obtenerListaProductos() = 0;                        // está el .h pero no esta implementado
    virtual void agregarProducto(ParCodigoCantidad parCodCant) = 0;
    virtual ParCompraProductos obtenerInfoCompra() = 0;
    virtual set<string> obtenerListaNicknamesClientes() = 0;
    virtual void seleccionarCliente(string nickname) = 0;
    virtual void confirmarCompra() = 0;
    
};

#endif
