#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

#include <iostream>
#include <vector>
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/ParCodigoCantidad.h"


class DataCrearPromocion {
    private:
        string vendedor;
        DTPromocion infoP;
        vector<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataCrearPromocion();
        DataCrearPromocion(string _vendedor, DTPromocion _infoP, vector<ParCodigoCantidad> _prodCant);
        //Destructor
        ~DataCrearPromocion();

        //Getters   
        string getVendedor();
        DTPromocion getInfoP();
        vector<ParCodigoCantidad> getProdCant();

        //Setters
        void setVendedor(string _vendedor);
        void setInfoP(DTPromocion _infoP);
        void setProdCant(vector<ParCodigoCantidad> _prodCant);

        void agregar(ParCodigoCantidad par);
};

#endif