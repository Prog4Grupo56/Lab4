#ifndef PRODUCTO
#define PRODUCTO

#include <set>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "CantMin.h"
#include "CompraProducto.h"

class CompraProducto;
class CantMin;
class Compra;

class Producto
{
    public:
        string codigo;
        Categoria categoria;
        string nombre;
        string descripcion;
        int stock;
        float precio;
        CantMin* cantMin;
        set<CompraProducto*> compraProducto;
    
    public:
        //Constructor
        Producto();

        //Destructor
        ~Producto();

        string getCodigo();
        string getCategoria();
        string getNombre();
        string getDescripcion();
        int getStock();
        float getPrecio();
    
        void setCodigo(string _codigo);
        void setCategoria(Categoria _categoria);
        void setNombre(string _nombre);
        void setDescripcion(string _descripcion);
        void setStock(int _stock);
        void setPrecio(float _precio);

        //Operaciones:
        DataProducto getDataProducto();
        bool pertenecePromoVigente();
        void crearEnvio(Compra* c, int cantidad);
        
};

#endif
