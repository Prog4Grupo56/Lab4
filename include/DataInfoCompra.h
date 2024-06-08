#include <iostream>
#ifndef DATAINFOCOMPRA
#define DATAINFOCOMPRA
#include <set>

using namespace std;
<<<<<<< HEAD:include/Clases/DataInfoCompra.h
//#include "../Datatypes/ParCodigoCantidad.h"
=======
#include "ParCodigoCantidad.h"
>>>>>>> c6fad72dd8fb7f6e0a0c0a82d5156d2f452c8bd0:include/DataInfoCompra.h


class DataInfoCompra {
    private:
        string cliente;
        float montoF;
        set<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataInfoCompra(string _cliente, float _montoF, set<ParCodigoCantidad> _prodCant);
        //Destructor
        ~DataInfoCompra();

        //Getters   
        string getCliente();
        float getMontoF();
        set<ParCodigoCantidad> getProdCant();

        //Setters
        void setCliente(string _cliente);
        void setMontoF(float _montoF);
        void setProdCant(set<ParCodigoCantidad> _prodCant);

};

#endif