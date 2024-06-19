#ifndef VENDEDOR
#define VENDEDOR

#include "Cliente.h"
#include "../Datatypes/ParCodigoNombre.h"


#include "Usuario.h"
#include "Producto.h"
#include "../Datatypes/DataProducto.h"
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/ParCodigoNombre.h"

class ParCodigoNombre;
class Usuario;
class Cliente;
class Promocion;
class ParCodigoNombre;

class Vendedor : public Usuario{
    private:
        string RUT;
        map<string,Cliente*> suscriptores;
        void notificarClientes(vector<DataProducto> dtProductos, string nombrePromocion);
        map<int,Producto*> productos;
        map<string,Promocion*> promociones;
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, string _RUT);
        Vendedor(DTVendedor vendedor);
        ~Vendedor();
      
        string getRUT();
        vector<ParCodigoNombre> obtenerProductos(DTFecha _fecha);
        DTVendedor getDataVendedor();

        void setRUT(string _RUT);
        void agregarSuscriptor(Cliente* c);
        void setProducto(Producto* producto);

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

        void agregarPromocionYNotificar(vector<DataProducto> dtProductos, string nombrePromocion, Promocion* pr);

        vector<DataPromocion> obtenerInfoPromocionesVigentes(DTFecha _fecha);
        vector<DataProducto> obtenerInfoProductos();

        vector<ParCodigoNombre> obtenerProductosPendientesEnvio();

};

#endif