#ifndef PROMOCION
#define PROMOCION

#include <set>
#include <map>
#include <vector>
#include "../Datatypes/DTFecha.h"
#include "../Clases/CantMin.h"
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"

class CantMin;

class Promocion
{
    public:
        string nombre;
        string descripcion;
        float descuento;
        DTFecha fechaVenc;
    
        vector<CantMin*> cantMinProductos;

    public:
        //Constructor
        Promocion(DTPromocion _promocion);
        Promocion(DTPromocion _promocion, vector<CantMin*> _cantidadesMinimas);

        //Destructor
        ~Promocion();

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DTFecha getFechaVenc();
        vector<CantMin*> getCantidadesMinimas();
    
        void setNombre(string nombre_);
        void setDescripcion(string descripcion_);
        void setDescuento(float descuento_);
        void setFechaVenc(DTFecha fecha_);

        void agregarCantMinProducto(CantMin *cMinProd);

        DTPromocion getDataPromocion();
        vector<ParCodigoCantidad> aplicaEnCompra(vector<ParCodigoCantidad> prodCant);
};

#endif
