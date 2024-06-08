#include <iostream>
#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

#include <set>
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"


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