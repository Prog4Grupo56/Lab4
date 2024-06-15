#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <string>
#include <set>
#include <vector>
#include "Vendedor.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "DataCrearPromocion.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/ParCompraProductos.h"
#include "../Datatypes/ParNickFecha.h"

class Vendedor;

class ICompra {
public:

    virtual void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP) = 0;
    virtual vector<DataProducto> obtenerListaProductos() = 0;
    virtual void agregarProductoCantidad(ParCodigoCantidad parCodCant) = 0;
    virtual ParCompraProductos obtenerInfoCompra() = 0;
    virtual vector<string> obtenerListaNicknamesClientes() = 0;
    virtual void seleccionarCliente(string nickname) = 0;
    virtual void confirmarCompra() = 0;
    
    //Enviar Producto
    virtual vector<ParCodigoNombre> obtenerProductosPendientesEnvio(string nickVendedor) = 0; //Implementar
    virtual vector<ParNickFecha> obtenerParNickFechaEnvio(string producto) = 0; //Implementar
    virtual void enviarProducto() = 0; //Implementar
    
    virtual Producto* obtenerProducto(string _codigoProducto) = 0;
};

#endif
