#ifndef DATAPROMOSELECCIONADA
#define DATAPROMOSELECCIONADA
#include <set>
#include <string>
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DataProducto.h"

class DataPromoSeleccionada {
    private:
        set<DataProducto> productos;
        DataVendedor vendedor;
    public:
        //Constructor
        DataPromoSeleccionada();
        DataPromoSeleccionada(set<DataProducto> _productos, DataVendedor _vendedor);
        //Destructor
        ~DataPromoSeleccionada();

        //Getters   
        set<DataProducto> getProductos();
        DataVendedor getVendedor();

        //Setters
        void setProductos(set<DataProducto> _productos);
        void setVendedor(DataVendedor _vendedor);

};

#endif