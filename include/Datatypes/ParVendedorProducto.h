#ifndef PARVENDEDORPRODUCTO
#define PARVENDEDORPRODUCTO

#include "DTProducto.h"
#include <string>

class ParVendedorProducto{

    private:
        string nickname;
        DTProducto producto;
    public:
        ParVendedorProducto();
        ParVendedorProducto(string _nickname, DTProducto prod);
        ~ParVendedorProducto();

        string getNickname();
        DTProducto getProducto();

};

#endif