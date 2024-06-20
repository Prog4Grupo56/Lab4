#ifndef DTNICKFECHA
#define DTNICKFECHA

#include "DTFecha.h"
#include <string>

class DTNickFecha{

    private:
        string nickname;
        DTFecha fecha;
    public:
        DTNickFecha();
        DTNickFecha(string _nickname, DTFecha _fecha);
        ~DTNickFecha();

        string getNickname();
        DTFecha getFecha();

};

#endif