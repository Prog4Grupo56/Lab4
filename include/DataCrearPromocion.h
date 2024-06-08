#include <iostream>
#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

<<<<<<< HEAD:include/Clases/DataCrearPromocion.h
#include "../Datatypes/DataPromocion.h"
//#include "../Datatypes/ParCodigoCantidad.h"
=======
#include <set>
#include "DataPromocion.h"
#include "ParCodigoCantidad.h"
>>>>>>> c6fad72dd8fb7f6e0a0c0a82d5156d2f452c8bd0:include/DataCrearPromocion.h


class DataCrearPromocion {
    private:
        string vendedor;
        DataPromocion infoP;
        set<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataCrearPromocion(string _vendedor, DataPromocion _infoP, set<ParCodigoCantidad> _prodCant);
        //Destructor
        ~DataCrearPromocion();

        //Getters   
        string getVendedor();
        DataPromocion getInfoP();
        set<ParCodigoCantidad> getProdCant();

        //Setters
        void setVendedor(string _vendedor);
        void setInfoP(DataPromocion _infoP);
        void setProdCant(set<ParCodigoCantidad> _prodCant);

};

#endif