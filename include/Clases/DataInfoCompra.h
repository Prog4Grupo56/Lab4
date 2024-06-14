#include <iostream>
#ifndef DATAINFOCOMPRA
#define DATAINFOCOMPRA
#include <vector>

using namespace std;
#include "../Datatypes/ParCodigoCantidad.h"


class DataInfoCompra {
    private:
        string cliente;
        float montoF;
        vector<ParCodigoCantidad> prodCant;
    public:
        //Constructor
        DataInfoCompra(string _cliente);
        DataInfoCompra(string _cliente, float _montoF, vector<ParCodigoCantidad> _prodCant);
        //Destructor
        ~DataInfoCompra();

        //Getters   
        string getCliente();
        float getMontoF();
        vector<ParCodigoCantidad> getProdCant();

        //Setters
        void setCliente(string _cliente);
        void setMontoF(float _montoF);
        void setProdCant(vector<ParCodigoCantidad> _prodCant);

};

#endif