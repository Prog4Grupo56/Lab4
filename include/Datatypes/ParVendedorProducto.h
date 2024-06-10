#ifndef PARVENDEDORPRODUCTO
#define PARVENDEDORPRODUCTO

#include "DataProducto.h"
#include <string>

class ParVendedorProducto{

    private:
        string nickname;
        DataProducto producto;
    public:
        ParVendedorProducto();
        ParVendedorProducto(string _nickname, DataProducto prod);
        ~ParVendedorProducto();

        string getNickname();
        DataProducto getProducto();

};

#endif