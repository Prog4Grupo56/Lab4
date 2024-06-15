#ifndef VENDEDOR
#define VENDEDOR

#include "Cliente.h"
#include "../Datatypes/ParCodigoNombre.h"
#include "Usuario.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/ParCodigoNombre.h"

class ParCodigoNombre;
class Usuario;
class Cliente;
class Promocion;

class Vendedor : public Usuario{
    private:
        int RUT;
        map<string,Cliente*> suscriptores;
        void notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion);
        map<string,Producto*> productos;
        map<string,Promocion*> promociones;
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT);
        Vendedor(DataVendedor vendedor);
        ~Vendedor();
      
        int getRUT();
        vector<ParCodigoNombre> obtenerProductos();
        DataVendedor getDataVendedor();

        void setRUT(int _RUT);
        void agregarSuscriptor(Cliente* c);
        void setProducto(Producto* producto);

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

        void agregarPromocionYNotificar(vector<DataProducto> dtProductos, string nombrePromocion, Promocion* pr);

        vector<DataPromocion> obtenerInfoPromocionesVigentes(DTFecha _fecha);
        vector<DataProducto> obtenerInfoProductos();

};

#endif