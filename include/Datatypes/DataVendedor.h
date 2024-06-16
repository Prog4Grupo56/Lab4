#ifndef DATAVENDEDOR
#define DATAVENDEDOR

#include "DataUsuario.h"

class DataVendedor : public DataUsuario{

    private:
        string RUT;
    public:
        DataVendedor();
        DataVendedor(string _nickname, string _constrasena, DTFecha _fecha, string _RUT);
        ~DataVendedor();
      
        string getRUT();

        string toString();
};

#endif