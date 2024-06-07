#ifndef DATAELIMINARSUSCRIPCION
#define DATAELIMINARSUSCRIPCION
#include <set>
#include <string>
#include <DataVendedor.h>

class DataEliminarSuscripcion {
    private:
        string nickname;
        set<DataVendedor> vendedores;
    public:
        //Constructor
        DataEliminarSuscripcion();
        DataEliminarSuscripcion(string _nickname, set<DataVendedor> _vendedores);
        //Destructor
        ~DataEliminarSuscripcion();

        //Getters   
        string getNickname();
        set<DataVendedor> getVendedores();

        //Setters
        void setNickname(string _nickname);
        void setVendedores(set<DataVendedor> _vendedores);

};

#endif