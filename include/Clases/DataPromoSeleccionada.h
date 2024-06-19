#ifndef DATAPROMOSELECCIONADA
#define DATAPROMOSELECCIONADA
#include <set>
#include <string>
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/DTProducto.h"

class DataPromoSeleccionada {
    private:
        set<DTProducto> productos;
        DTVendedor vendedor;
    public:
        //Constructor
        DataPromoSeleccionada();
        DataPromoSeleccionada(set<DTProducto> _productos, DTVendedor _vendedor);
        //Destructor
        ~DataPromoSeleccionada();

        //Getters   
        set<DTProducto> getProductos();
        DTVendedor getVendedor();

        //Setters
        void setProductos(set<DTProducto> _productos);
        void setVendedor(DTVendedor _vendedor);

};

#endif