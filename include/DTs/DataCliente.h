#ifndef DATACLIENTE
#define DATACLIENTE

#include "DataUsuario.h"
#include "DTs/DTDireccion.h"

class DataCliente : public DataUsuario{

    private:
        DTDireccion* direccion;
        string ciudad;

    public:
        DataCliente(string _nickname, DTFecha* _fecha, DTDireccion* _direccion, string _ciudad);

        ~DataCliente();
       
        DTDireccion* getDireccion();
        string getCiudad();
  
        void setDireccion(DTDireccion* _direccion);
        void setCiudad(string _ciudad);
};

#endif