#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <string>
#include <set>
#include <vector>
#include "Vendedor.h"
#include "../Datatypes/DTCodigoCantidad.h"
#include "DataCrearPromocion.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/ParCompraProductos.h"
#include "DataInfoCompra.h"
#include "../Datatypes/DTNickFecha.h"

class Vendedor;

class ICompra {
public:

    virtual void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP) = 0;
    virtual vector<DTProducto> obtenerListaProductos() = 0;
    virtual void agregarProductoCantidad(DTCodigoCantidad parCodCant) = 0;
    virtual ParCompraProductos obtenerInfoCompra() = 0;
    virtual vector<string> obtenerListaNicknamesClientes() = 0;
    virtual void seleccionarCliente(string nickname) = 0;
    virtual void confirmarCompra(DTFecha _fecha) = 0;
    virtual void cancelarCompra() = 0;
    
    
    //Enviar Producto
    virtual vector<DTCodigoNombre> obtenerProductosPendientesEnvio(string nickVendedor) = 0; 
    virtual vector<DTNickFecha> obtenerParNickFechaEnvio(int producto) = 0; 
    virtual void enviarProducto(int producto, string cliente) = 0; 
    virtual vector<string> obtenerListaNicknameVendedores() = 0;

    //virtual Producto* obtenerProducto(string _codigoProducto) = 0;
    virtual Producto* obtenerProducto(int _codigoProducto) = 0;
    virtual vector<DTPromocion> obtenerInfoPromociones(DTFecha _fecha) = 0;
    virtual string obtenerInfoPromocion(string nombre) = 0;
    virtual void confirmarAltaProducto(Categoria categoria, string nombre, string descripcion, int stock, float precio, Vendedor* vendedor) = 0;
};

#endif
