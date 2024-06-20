#ifndef DATACREARPROMOCION
#define DATACREARPROMOCION

#include <iostream>
#include <vector>
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/DTCodigoCantidad.h"


class DataCrearPromocion {
    private:
        string vendedor;
        DTPromocion infoP;
        vector<DTCodigoCantidad> prodCant;
    public:
        //Constructor
        DataCrearPromocion();
        DataCrearPromocion(string _vendedor, DTPromocion _infoP, vector<DTCodigoCantidad> _prodCant);
        //Destructor
        ~DataCrearPromocion();

        //Getters   
        string getVendedor();
        DTPromocion getInfoP();
        vector<DTCodigoCantidad> getProdCant();

        //Setters
        void setVendedor(string _vendedor);
        void setInfoP(DTPromocion _infoP);
        void setProdCant(vector<DTCodigoCantidad> _prodCant);

        void agregar(DTCodigoCantidad par);
};

#endif