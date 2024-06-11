#ifndef CLIENTE
#define CLIENTE

#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DTNotificacion.h"
#include "Usuario.h"
#include "Vendedor.h"

class Vendedor;
class Usuario;

class Cliente : public Usuario{

    private:
        DTDireccion direccion;
        string ciudad;
        set<Vendedor*> suscripciones;
        set<DTNotificacion> notificaciones;
    public:
        //Constructor
        Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad);
        //Destructor
        ~Cliente();
       
        DTDireccion getDireccion();
        string getCiudad();
        set<DTNotificacion> getNotificaciones();
        set<DataVendedor> obtenerSuscripciones();

        void setDireccion(DTDireccion _direccion);
        void setCiudad(string _ciudad);
        void agregarSuscripcion(Vendedor* vendedor);

        void notificar(string nombreVendedor, set<DataProducto> dtProductos, string nombrePromocion);

        void eliminarSuscripciones(set<DataVendedor>);
        void eliminarSuscripcion(Vendedor* v);
};

#endif