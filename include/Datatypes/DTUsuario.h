#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include "DTFecha.h"
using namespace std;

class DTUsuario{

    private:
        string nickname;
        DTFecha fecha;
        string contrasena;
    public:
        DTUsuario();
        DTUsuario(string _nickname, string _contrasena, DTFecha _fecha);

        virtual ~DTUsuario();

        string getNickname() const;
        DTFecha getFecha();
        string getContrasena();

        virtual string toString() = 0; 
};

#endif