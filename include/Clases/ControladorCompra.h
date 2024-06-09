#ifndef CONTROLADOR_COMPRA
#define CONTROLADOR_COMPRA

#include <set>
#include <string>

#include "Compra.h"
#include "CompraProducto.h"
#include "Vendedor.h"
#include "Producto.h"
#include "Promocion.h"
#include "CantMin.h"
#include "DataCrearPromocion.h"
#include "DataInfoCompra.h"
#include "ICompra.h"
#include "Fabrica.h"

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/ParCompraProductos.h"

using namespace std;

class ControladorCompra : public ICompra
{
    private:
        static ControladorCompra * instancia;
        DataInfoCompra * dataInfoC;
        set<Compra*> compras;
        set<Producto*> productos;
        set<Promocion*> promociones;
        ControladorCompra();
    public:
        ~ControladorCompra();
        static ControladorCompra* getInstancia();
        void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP);
        set<DataProducto> obtenerListaProductos();
        void agregarProducto(ParCodigoCantidad parCodCant);
        ParCompraProductos obtenerInfoCompra();
        set<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra();
};

#endif