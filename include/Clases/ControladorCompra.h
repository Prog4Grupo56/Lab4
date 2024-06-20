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
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/DTCodigoCantidad.h"
#include "../Datatypes/ParCompraProductos.h"
#include "../Datatypes/DTNickFecha.h"

class Compra;
class Vendedor;
class Fabrica;


using namespace std;

class ControladorCompra : public ICompra{
    private:
        static ControladorCompra * instancia;
        DataInfoCompra * dataInfoC;
        vector<Compra*> compras;
        map<int, Producto*> productos;
        map<string, Promocion*> promociones;
        ControladorCompra();
        int cantidadProductos;
    public:
        ~ControladorCompra();
        static ControladorCompra* getInstancia();
        void crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP);
        vector<DTProducto> obtenerListaProductos();
        void agregarProductoCantidad(DTCodigoCantidad parCodCant);
        ParCompraProductos obtenerInfoCompra();
        vector<string> obtenerListaNicknamesClientes();
        void seleccionarCliente(string nickname);
        void confirmarCompra(DTFecha _fecha);
        void cancelarCompra();

        void limpiarCC();

        //Enviar Producto
        vector<DTCodigoNombre> obtenerProductosPendientesEnvio(string nickVendedor);
        vector<DTNickFecha> obtenerParNickFechaEnvio(int producto); 
        void enviarProducto(int producto, string cliente);
        vector<string> obtenerListaNicknameVendedores(); 

        //Producto* obtenerProducto(string _codigoProducto);
        Producto* obtenerProducto(int _codigoProducto);
        vector<DTPromocion> obtenerInfoPromociones(DTFecha _fecha);
        string obtenerInfoPromocion(string nombre);

        void confirmarAltaProducto(Categoria categoria, string nombre, string descripcion, int stock, float precio, Vendedor* vendedor);

        
};

#endif