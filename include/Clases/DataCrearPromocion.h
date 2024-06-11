#include <iostream>
#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

#include <vector>
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"


class DataCrearPromocion {
    private:
        string vendedor;
        DataPromocion infoP;
        vector<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataCrearPromocion();
        DataCrearPromocion(string _vendedor, DataPromocion _infoP, vector<ParCodigoCantidad> _prodCant);
        //Destructor
        ~DataCrearPromocion();

        //Getters   
        string getVendedor();
        DataPromocion getInfoP();
        vector<ParCodigoCantidad> getProdCant();

        //Setters
        void setVendedor(string _vendedor);
        void setInfoP(DataPromocion _infoP);
        void setProdCant(vector<ParCodigoCantidad> _prodCant);

};

#endif