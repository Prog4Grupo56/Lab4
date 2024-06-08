#ifndef PROMOCION
#define PROMOCION

#include <set>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"

//class ;

class Promocion
{
    public:
        string nombre;
        string descripcion;
        float descuento;
        DTFecha fechaVenc;
    
    public:
        //Constructor
        Promocion(DataPromocion promocion);

        //Destructor
        ~Promocion();

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DTFecha getFechaVenc();
    
        void setNombre();
        void setDescripcion();
        void setDescuento();
        void setFechaVenc();

        DataPromocion getDataPromocion();
        set<ParCodigoCantidad> aplicaEnCompra(set<ParCodigoCantidad> prodCant);
};

#endif
