#ifndef CONTROLADOR_COMPRA
#define CONTROLADOR_COMPRA

#include <set>
#include <vector>
#include <string>
#include "Compra.h"
#include "DataInfoCompra.h"
#include "Producto.h"
#include "Promocion.h"
#include "Vendedor.h"
#include "ICompra.h"
#include "DataCrearPromocion.h"
#include "Fabrica.h"

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/ParCompraProductos.h"

class Compra;

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
        vector<DataProducto> obtenerListaProductos();
        void agregarProducto(ParCodigoCantidad parCodCant);
        ParCompraProductos obtenerInfoCompra();
        set<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra();
};

#endif