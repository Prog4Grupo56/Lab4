#ifndef PRODUCTO
#define PRODUCTO

#include <set>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/ParNickFecha.h"
#include "CantMin.h"
#include "CompraProducto.h"

class Vendedor;
class CompraProducto;
class CantMin;
class Compra;

class Producto
{ 
    public:
        int codigo;
        Categoria categoria;
        string nombre;
        string descripcion;
        int stock;
        float precio;
        CantMin* cantMin;
        vector<CompraProducto*> compraProducto;
        Vendedor* vendedor;
    
    public:
        //Constructor
        Producto(int codigo, Categoria categoria, string nombre, string descripcion, int stock, float precio, Vendedor* vendedor);

        //Destructor
        ~Producto();

        int getCodigo();
        string getCategoria();
        string getNombre();
        string getDescripcion();
        int getStock();
        float getPrecio();
        CantMin* getCantMin();
        vector<CompraProducto*> getCompraProducto();
        Vendedor* getVendedor();
    
        void setCodigo(int _codigo);
        void setCategoria(Categoria _categoria);
        void setNombre(string _nombre);
        void setDescripcion(string _descripcion);
        void setStock(int _stock);
        void setPrecio(float _precio);
        void setCantMin(CantMin* _cantMin);
        void setCompraProducto(vector<CompraProducto*> _compraProducto);
        void setVendedor(Vendedor* _vendedor);

        //Operaciones:
        DataProducto getDataProducto();
        bool pertenecePromoVigente();
        void crearEnvio(Compra* c, int cantidad);
        vector<ParNickFecha> obtenerClienteFecha();
        
};

#endif