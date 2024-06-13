#ifndef VENDEDOR
#define VENDEDOR

#include "Cliente.h"
#include "../Datatypes/ParCodigoNombre.h"

class Cliente; //fwd declaration
class ParCodigoNombre;
#include "Usuario.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"

class Usuario;
class Cliente;
class Promocion;

class Vendedor : public Usuario{
    private:
        int RUT;
        set<Cliente*> suscriptores;
        void notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion); // privado porque asi esta en el template
        set<Producto*> productos;
        set<Promocion*> promociones;
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT);
        Vendedor(DataVendedor vendedor);
        ~Vendedor();
      
        int getRUT();
        vector<ParCodigoNombre> obtenerProductos();  //implementaaaar
        DataVendedor getDataVendedor();
    
        //obtener suscriptores y promociones?

        void setRUT(int _RUT);
        void agregarSuscriptor(Cliente* c);
        void setProducto(Producto* producto);

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

        void agregarPromocionYNotificar(set<DataProducto> dtProductos, string nombrePromocion, Promocion* pr);

};

#endif