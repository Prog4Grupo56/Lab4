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

#include "DTs/DataInfoCompra.h"
#include "DTs/DTFecha.h"
#include "DTs/DataCrearPromocion.h"
#include "DTs/DataProducto.h"
#include "DTs/ParCodigoCantidad.h"
#include "DTs/ParCompraProductos.h"



using namespace std;

/*======= Forward ========*/
//Clases
class Cliente;
class Vendedor;
class Vendedor;
class Producto;
class CompraProducto;
class Promocion;
//Datatypes
class DataInfoCompra;
class DataCrearPromocion;
class DataProducto;
class ParCodigoCantidad;
class ParCompraProductos;

class ControladorCompra
{
    private:
        ControladorCompra * instancia;
        DataInfoCompra * dataInfoC;
        set<Compra> compras;
        set<Producto> productos;
        set<Promocion> promociones;
    public:
        ControladorCompra(); //Constructor
        ~ControladorCompra(); //Destructor

        /*======= Operaciones ========*/
        ControladorCompra getInstancia(); //Obtener instancia (singleton)
        void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP);
        set<DataProducto> obtenerListaProductos();
        void agregarProducto(ParCodigoCantidad* parCodCant);
        ParCompraProductos obtenerInfoCompra();
        set<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra();
};

#endif