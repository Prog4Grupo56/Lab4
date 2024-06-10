#ifndef PROMOCION
#define PROMOCION

#include <set>
#include "../Datatypes/DTFecha.h"
#include "../Clases/CantMin.h"
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"

class CantMin;

class Promocion
{
    public:
        string nombre;
        string descripcion;
        float descuento;
        DTFecha fechaVenc;
    
        set<CantMin*> cantMinProductos;

    public:
        //Constructor
        Promocion(DataPromocion promocion);

        //Destructor
        ~Promocion();

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DTFecha getFechaVenc();
        set<CantMin*> getCantidadesMinimas();
    
        void setNombre(string nombre_);
        void setDescripcion(string descripcion_);
        void setDescuento(float descuento_);
        void setFechaVenc(DTFecha fecha_);

        void agregarCantMinProducto(CantMin *cMinProd);

        DataPromocion getDataPromocion();
        set<ParCodigoCantidad> aplicaEnCompra(set<ParCodigoCantidad> prodCant);
};

#endif
