#ifndef DATAELIMINARSUSCRIPCION
#define DATAELIMINARSUSCRIPCION
#include <vector>
#include <string>
#include "../Datatypes/DataVendedor.h"

class DataEliminarSuscripcion {
    private:
        string nickname;
        vector<DataVendedor> vendedores;
    public:
        //Constructor
        DataEliminarSuscripcion();
        DataEliminarSuscripcion(string _nickname, vector<DataVendedor> _vendedores);
        //Destructor
        ~DataEliminarSuscripcion();

        //Getters   
        string getNickname();
        vector<DataVendedor> getVendedores();

        //Setters
        void setNickname(string _nickname);
        void setVendedores(vector<DataVendedor> _vendedores);

};

#endif