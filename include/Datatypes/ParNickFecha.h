#ifndef PARNICKFECHA
#define PARNICKFECHA

#include "DTFecha.h"
#include <string>

class ParNickFecha{

    private:
        string nickname;
        DTFecha fecha;
    public:
        ParNickFecha();
        ParNickFecha(string _nickname, DTFecha _fecha);
        ~ParNickFecha();

        string getNickname();
        DTFecha getFecha();

};

#endif