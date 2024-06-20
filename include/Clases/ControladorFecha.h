#ifndef CONTROLADORFECHA
#define CONTROLADORFECHA

#include "IFecha.h"

using namespace std;

class ControladorFecha : public IFecha{
    private:
        static ControladorFecha * instancia;
        DTFecha fechaActual;
        ControladorFecha();
    public:
        ~ControladorFecha();
        static ControladorFecha* getInstancia();
        DTFecha getFechaActual();
        void setFechaActual(DTFecha _fecha);
};

#endif