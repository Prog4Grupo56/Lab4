#ifndef DATAVENDEDOR
#define DATAVENDEDOR

#include "DTUsuario.h"

class DTVendedor : public DTUsuario{

    private:
        string RUT;
    public:
        DTVendedor();
        DTVendedor(string _nickname, string _constrasena, DTFecha _fecha, string _RUT);
        ~DTVendedor();
      
        string getRUT();

        string toString();
};

#endif