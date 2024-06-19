#ifndef DATAELIMINARSUSCRIPCION
#define DATAELIMINARSUSCRIPCION
#include <vector>
#include <string>
#include "../Datatypes/DTVendedor.h"

class DataEliminarSuscripcion {
    private:
        string nickname;
        vector<DTVendedor> vendedores;
    public:
        //Constructor
        DataEliminarSuscripcion();
        DataEliminarSuscripcion(string _nickname, vector<DTVendedor> _vendedores);
        //Destructor
        ~DataEliminarSuscripcion();

        //Getters   
        string getNickname();
        vector<DTVendedor> getVendedores();

        //Setters
        void setNickname(string _nickname);
        void setVendedores(vector<DTVendedor> _vendedores);

};

#endif