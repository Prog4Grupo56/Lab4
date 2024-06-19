#ifndef DATACLIENTE
#define DATACLIENTE

#include "DTUsuario.h"
#include "DTDireccion.h"

class DTCliente : public DTUsuario{

    private:
        DTDireccion direccion;
        string ciudad;

    public:
        DTCliente(string _nickname, string _contrasena, DTFecha _fecha, DTDireccion _direccion, string _ciudad);

        ~DTCliente();
       
        DTDireccion getDireccion();
        string getCiudad();

        string toString();
};

#endif