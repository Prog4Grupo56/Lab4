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
        string getContrasena();

        void setNickname();
        void setFecha();

        virtual string toString(); 
};

#endif