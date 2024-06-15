#ifndef CONTROLADOR_COMPRA
#define CONTROLADOR_COMPRA

#include <map>
#include <vector>
#include <string>

#include "Producto.h"
#include "Promocion.h"
#include "ICompra.h"
#include "DataInfoCompra.h"
#include "DataCrearPromocion.h"
#include "Fabrica.h"

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/ParCompraProductos.h"

class Compra;
class Vendedor;
class Fabrica;


using namespace std;

class ControladorCompra : public ICompra{
    private:
        static ControladorCompra * instancia;
        DataInfoCompra * dataInfoC;
        vector<Compra*> compras;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
        ControladorCompra();
    public:
        ~ControladorCompra();
        static ControladorCompra* getInstancia();
        void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP);
        vector<DataProducto> obtenerListaProductos();
        void agregarProductoCantidad(ParCodigoCantidad parCodCant);
        ParCompraProductos obtenerInfoCompra();
        vector<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra();
        Producto* obtenerProducto(string _codigoProducto);
};

#endif