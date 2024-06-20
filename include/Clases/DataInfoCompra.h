#include <iostream>
#ifndef DATAINFOCOMPRA
#define DATAINFOCOMPRA
#include <vector>

using namespace std;
#include "../Datatypes/DTCodigoCantidad.h"


class DataInfoCompra {
    private:
        string cliente;
        float montoF;
        vector<DTCodigoCantidad> prodCant;
    public:
        //Constructor
        DataInfoCompra(string _cliente);
        DataInfoCompra(string _cliente, float _montoF, vector<DTCodigoCantidad> _prodCant);
        //Destructor
        ~DataInfoCompra();

        //Getters   
        string getCliente();
        float getMontoF();
        vector<DTCodigoCantidad> getProdCant();

        //Setters
        void setCliente(string _cliente);
        void setMontoF(float _montoF);
        void setProdCant(vector<DTCodigoCantidad> _prodCant);

};

#endif