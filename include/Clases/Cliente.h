#ifndef CLIENTE
#define CLIENTE

#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/DTCliente.h"
#include "../Datatypes/DTNotificacion.h"
#include "Usuario.h"
#include "Vendedor.h"

class Vendedor;
class Usuario;
class Compra;

class Cliente : public Usuario{

    private:
        DTDireccion direccion;
        string ciudad;
        map<string,Vendedor*> suscripciones;
        vector<DTNotificacion> notificaciones;
        vector<Compra*> compras;
    public:
        //Constructor
        Cliente(string _nickname, string _contrasenia, DTFecha _fecha, DTDireccion _direccion, string _ciudad);
        Cliente(DTCliente cliente);
        //Destructor
        ~Cliente();
       
        DTDireccion getDireccion();
        string getCiudad();
        vector<DTNotificacion> getNotificaciones();
        vector<DTVendedor> obtenerSuscripciones();
        DTCliente getDataCliente();
        vector<Compra*> getCompras();

        void setDireccion(DTDireccion _direccion);
        void setCiudad(string _ciudad);
        void setCompras(vector<Compra*> _compras);

        void agregarSuscripcion(Vendedor* vendedor);
        void agregarCompra(Compra* _compra);

        void notificar(string nombreVendedor, vector<DataProducto> dtProductos, string nombrePromocion);

        void eliminarSuscripciones(vector<DTVendedor>);
        void eliminarSuscripcion(Vendedor* v);
};

#endif