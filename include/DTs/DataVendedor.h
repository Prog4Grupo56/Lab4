#ifndef DATAVENDEDOR
#define DATAVENDEDOR

#include "DataUsuario.h"

class DataVendedor : public DataUsuario{

    private:
        int RUT;
    public:
        DataVendedor(string _nickname, DTFecha* _fecha, int _RUT);
        ~DataVendedor();
      
        int getRUT();

        void setRUT();
};

#endif