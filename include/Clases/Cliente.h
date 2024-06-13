#ifndef CLIENTE
#define CLIENTE

#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DataCliente.h"
#include "../Datatypes/DTNotificacion.h"
#include "Usuario.h"
#include "Vendedor.h"

class Vendedor;
class Usuario;

class Cliente : public Usuario{

    private:
        DTDireccion direccion;
        string ciudad;
        map<string,Vendedor*> suscripciones;
        vector<DTNotificacion> notificaciones;
    public:
        //Constructor
        Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad);
        Cliente(DataCliente cliente);
        //Destructor
        ~Cliente();
       
        DTDireccion getDireccion();
        string getCiudad();
        vector<DTNotificacion> getNotificaciones();
        vector<DataVendedor> obtenerSuscripciones();

        void setDireccion(DTDireccion _direccion);
        void setCiudad(string _ciudad);
        void agregarSuscripcion(Vendedor* vendedor);

        void notificar(string nombreVendedor, vector<DataProducto> dtProductos, string nombrePromocion);

        void eliminarSuscripciones(vector<DataVendedor>);
        void eliminarSuscripcion(Vendedor* v);
};

#endif