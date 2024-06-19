#ifndef DATAPROMOSELECCIONADA
#define DATAPROMOSELECCIONADA
#include <set>
#include <string>
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/DataProducto.h"

class DataPromoSeleccionada {
    private:
        set<DataProducto> productos;
        DTVendedor vendedor;
    public:
        //Constructor
        DataPromoSeleccionada();
        DataPromoSeleccionada(set<DataProducto> _productos, DTVendedor _vendedor);
        //Destructor
        ~DataPromoSeleccionada();

        //Getters   
        set<DataProducto> getProductos();
        DTVendedor getVendedor();

        //Setters
        void setProductos(set<DataProducto> _productos);
        void setVendedor(DTVendedor _vendedor);

};

#endif