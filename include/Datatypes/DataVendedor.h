#ifndef DATAVENDEDOR
#define DATAVENDEDOR

#include "DataUsuario.h"

class DataVendedor : public DataUsuario{

    private:
        int RUT;
    public:
        DataVendedor();
        DataVendedor(string _nickname, string _constrasena, DTFecha _fecha, int _RUT);
        ~DataVendedor();
      
        int getRUT();

        string toString();
};

#endif