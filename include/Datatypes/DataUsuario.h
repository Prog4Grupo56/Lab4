#ifndef DATAUSUARIO
#define DATAUSUARIO

#include <string>
#include "DTFecha.h"
using namespace std;

class DataUsuario{

    private:
        string nickname;
        DTFecha fecha;
        string contrasena;
    public:
        DataUsuario();
        DataUsuario(string _nickname, string _contrasena, DTFecha _fecha);

        virtual ~DataUsuario();

        string getNickname();
        DTFecha getFecha();

        virtual string toString() = 0; 
};

#endif