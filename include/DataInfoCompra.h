#include <iostream>
#ifndef DATAINFOCOMPRA
#define DATAINFOCOMPRA
#include <set>

using namespace std;
//#include "ParCodigoCantidad.h"


class DataInfoCompra {
    private:
        string cliente;
        float montoF;
        //set<ParCodigoCantida> prodCant;
    public:
        //Constructor
        DataInfoCompra(string _cliente, float _montoF/*, set<parCodigoCantidad> _prodCant*/);
        //Destructor
        ~DataInfoCompra();

        //Getters   
        string getCliente();
        float getMontoF();
        //set<parCodigoCantidad> _prodCant();

        //CAPAZ TIENE SETTERS

};

#endif