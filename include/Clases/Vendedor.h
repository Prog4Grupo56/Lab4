#ifndef VENDEDOR
#define VENDEDOR

#include "Usuario.h"
#include "Cliente.h"
#include "../Datatypes/ParCodigoNombre.h"

class Cliente; //fwd declaration
class ParCodigoNombre;

class Vendedor : public Usuario{
    private:
        int RUT;
        set<Cliente*> suscriptores;
        void notificarClientes(); // privado porque asi esta en el template
        //lista productos
        //lista promociones
    public:
        Vendedor(string _nickname, string _contrasenia, DTFecha _fecha, int _RUT);
        ~Vendedor();
      
        int getRUT();
        vector<ParCodigoNombre> obtenerProductos();  //implementaaaar
        //DataVendedor* getDataVendedor();
    
        //obtener suscriptores y promociones?

        void setRUT(int _RUT);
        void agregarSuscriptor(Cliente* c);
        //set productos y promociones?

        bool estaSuscrito(string nicknameCliente);
        void eliminarSuscriptor(Cliente* c);

};

#endif