#ifndef VENDEDOR
#define VENDEDOR

#include "Usuario.h"
#include "Promocion.h"
#include "Producto.h"
#include "Cliente.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"

class Cliente; //fwd declaration

class Vendedor : public Usuario{
    private:
        int RUT;
        set<Cliente*> suscriptores;
        void notificarClientes(set<DataProducto> dtProductos, string nombrePromocion); // privado porque asi esta en el template
        //set<Producto*> productos;
       // set<Promocion*> promociones;
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT);
        ~Vendedor();
      
        int getRUT();
        set<DataProducto> obtenerProductos();
        DataVendedor getDataVendedor();
    
        //obtener suscriptores y promociones?

        void setRUT(int _RUT);
        void agregarSuscriptor(Cliente* c);
        //set productos y promociones?

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

        //void agregarPromocionYNotificar(set<DataProducto> dtProductos, string nombrePromocion, Promocion* pr);

};

#endif