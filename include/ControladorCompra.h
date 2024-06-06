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

#include "DataInfoCompra.h"
#include "DTFecha.h"
#include "DataCrearPromocion.h"
#include "DataProducto.h"
#include "ParCodigoCantidad.h"
#include "ParCompraProductos.h"



using namespace std;

/*======= Forward ========*/
//Clases
class Compra;
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
        static  ControladorCompra * instancia;
        //DataInfoCompra  dataInfoC;
        set<Compra> compras;
        set<Producto> productos;
        set<Promocion> promociones;

        ControladorCompra(); //Constructor
        ~ControladorCompra(); //Destructor. Privado??
    public:
        /*======= Operaciones ========*/
        ControladorCompra* getInstancia(); //Obtener instancia (singleton)
        void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP);
        set<DataProducto> obtenerListaProductos();
        void agregarProducto(ParCodigoCantidad* parCodCant);
        ParCompraProductos obtenerInfoCompra();
        set<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra();
};

#endif