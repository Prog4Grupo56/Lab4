#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include <map>
#include <vector>
#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DTNotificacion.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DataCliente.h"
#include "../Datatypes/DataComentario.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/ParCodigoNombre.h"

#include "Fabrica.h"
#include "Vendedor.h"
#include "Cliente.h"
#include "DataEliminarComentario.h"
#include "DataCrearPromocion.h"
#include "DataEliminarSuscripcion.h"


class Usuario;

//class ;

class ControladorUsuario : public IUsuario{
    private:
        static ControladorUsuario* instancia;
        ControladorUsuario();

        string nicknameC;
        DataEliminarComentario* dataElimCom;
        DataCrearPromocion* dataCrearP;
        DataEliminarSuscripcion* dataElimSus;

        map<string, Usuario*> usuarios;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;      //id RUT? xd

    public:
        static ControladorUsuario * getInstancia();

        string getNickname();
        DataEliminarComentario* getDataElimCom();
        DataCrearPromocion* getDataCrearP();
        DataEliminarSuscripcion* getDataElimSus();
    
        void setNickname(string nickCliente);
        void setDataElimCom(DataEliminarComentario* data);
        void setDataCrearP(DataCrearPromocion* data);
        void setDataElimSus(DataEliminarSuscripcion* data);

        //Alta Usuario
        bool ingresarCliente(DataCliente cliente);
        bool ingresarVendedor(DataVendedor vendedor);

        //Listado de Usuarios
        vector<DataCliente> obtenerListadoClientes();
        vector<DataVendedor> obtenerListadoVendedores();

        //Eliminar Comentario
        vector<string> obtenerListaNicknamesUsuarios();
        void seleccionarUsuario(string nickname); 
        vector<DataComentario> obtenerComentariosUsuario();
        void seleccionarComentario(int idComentario); 
        void eliminarComentario();
        
        //Crear Promocion
        void ingresarDatosPromocion(DataPromocion data);
        vector<string> obtenerListaNicknameVendedores();
        void seleccionarVendedor(string nickname);
        vector<ParCodigoNombre> obtenerListaProductosVendedor();
        void agregarProductoCantidad(ParCodigoCantidad parCodCant);  
        void confirmarAltaPromocion();

        //Realizar Compra
        vector<string> obtenerListaNicknamesClientes();
        Cliente* obtenerClienteCompra(string nickname);

        //Consultar Notificaciones
        vector<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente);

        //Suscribirse a Notificaciones
        vector<DataVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente);
        void vendedoresASuscribirse(vector<DataVendedor> vendedores); 

        //Eliminar Suscripcion 
        vector<DataVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente);
        void seleccionarVendedoresAEliminarSuscripciones(vector<DataVendedor> vendedores);
        void eliminarSuscripciones();
};

#endif