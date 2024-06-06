#ifndef DATAUSUARIO
#define DATAUSUARIO

#include <string>
#include "DTFecha.h"
using namespace std;

class DataUsuario{

    private:
        string nickname;
        DTFecha* fecha;
    public:
        DataUsuario(string _nickname, DTFecha* _fecha);
        ~DataUsuario();

        string getNickname();
        DTFecha* getFecha();

        void setNickname();
        void setFecha();
};

#endif