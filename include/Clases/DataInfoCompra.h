#include <iostream>
#ifndef DATAINFOCOMPRA
#define DATAINFOCOMPRA
#include <set>

using namespace std;
#include "../Datatypes/ParCodigoCantidad.h"


class DataInfoCompra {
    private:
        string cliente;
        float montoF;
        set<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataInfoCompra(string _cliente);
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