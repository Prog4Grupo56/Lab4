#ifndef PRODUCTO
#define PRODUCTO

#include <set>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/ParCodigoCantidad.h"

//class ;

class Producto
{
    public:
        string codigo;
        //Categoria categoria;
        string nombre;
        string descripcion;
        int stock;
        float precio;
    
    public:
        //Constructor
        //Promducto();

        //Destructor
        ~Producto();

        string getCodigo();
        //string getCategoria();
        string getNombre();
        string getDescripcion();
        int getStock();
        float getPrecio();
    
        void setCodigo();
        //void setCategoria();
        void setNombre();
        void setDescripcion();
        void setStock();
        void setPrecio();


        //Operaciones:
        
};

#endif
