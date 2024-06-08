#ifndef DATACLIENTE
#define DATACLIENTE

#include "DataUsuario.h"
#include "DTDireccion.h"

class DataCliente : public DataUsuario{

    private:
        DTDireccion direccion;
        string ciudad;
        string contrasena;

    public:
        DataCliente(string _nickname, string _contrasena, DTFecha _fecha, DTDireccion _direccion, string _ciudad);

        ~DataCliente();
       
        DTDireccion getDireccion();
        string getCiudad();
  
        void setDireccion(DTDireccion _direccion);
        void setCiudad(string _ciudad);
};

#endif