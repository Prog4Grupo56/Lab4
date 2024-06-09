#ifndef CLIENTE
#define CLIENTE

#include "DTDireccion.h"
#include "DataVendedor.h"
#include "Vendedor.h"
#include "DTNotificacion.h"

class Vendedor;

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
        //set<DataVendedor*> obtenerSuscripciones();

        void setDireccion(DTDireccion _direccion);
        void setCiudad(string _ciudad);
        void agregarSuscripcion(Vendedor* vendedor);

        //void notificar(cosasssssssssssssss);

        void eliminarSuscripciones(set<DataVendedor*>);
        void eliminarSuscripcion(Vendedor* v);
};

#endif