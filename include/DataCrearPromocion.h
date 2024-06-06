#include <iostream>
#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

#include "DataPromocion.h"
//#include "ParCodigoCantidad.h"


class DataCrearPromocion {
    private:
        string vendedor;
        DataPromocion infoP;
        //set<ParCodigoCantida> prodCant;
    public:
        //Constructor
        DataCrearPromocion(string _vendedor, DataPromocion _infoP/*, set<ParCodigoCantidad> _prodCant*/);
        //Destructor
        ~DataCrearPromocion();

        //Getters   
        string getVendedor();
        DataPromocion getInfoP();
        //set<ParCodigoCantidad> getProdCant();
        
};

#endif