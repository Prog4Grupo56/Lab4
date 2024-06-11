#ifndef VENDEDOR
#define VENDEDOR

#include "Cliente.h"
#include "Usuario.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/ParCodigoNombre.h"

class Usuario;
class Cliente;
class Usuario;
class Promocion;

class Vendedor : public Usuario{
    private:
        int RUT;
        map<string,Cliente*> suscriptores;
        void notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion); // privado porque asi esta en el template
        map<string,Producto*> productos;
        map<string,Promocion*> promociones;
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT);
        ~Vendedor();
      
        int getRUT();
        vector<ParCodigoNombre> obtenerProductos();
        DataVendedor getDataVendedor();
    
        //obtener suscriptores y promociones?

        void setRUT(int _RUT);
        void agregarSuscriptor(Cliente* c);
        void setProducto(Producto* producto);

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

        void agregarPromocionYNotificar(vector<DataProducto> dtProductos, string nombrePromocion, Promocion* pr);

};

#endif