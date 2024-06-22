#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include <map>
#include <vector>
#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DTNotificacion.h"
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/DTCliente.h"
#include "../Datatypes/DTComentario.h"
#include "../Datatypes/DTCodigoCantidad.h"
#include "../Datatypes/DTCodigoNombre.h"
#include "../Datatypes/DTNickFecha.h"
#include "../Datatypes/DTExpedienteCliente.h"
#include "../Datatypes/DTExpedienteVendedor.h"

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

        int cantidadComentarios;

        string nicknameC;
        DataEliminarComentario* dataElimCom;
        DataCrearPromocion* dataCrearP;
        DataEliminarSuscripcion* dataElimSus;

        map<string, Usuario*> usuarios;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        map<string, Comentario*> comentarios;

    public:
        static ControladorUsuario * getInstancia();
        ~ControladorUsuario();
        
        string getNickname();
        DataEliminarComentario* getDataElimCom();
        DataCrearPromocion* getDataCrearP();
        DataEliminarSuscripcion* getDataElimSus();
        int getCantidadComentarios();
    
        void setNickname(string nickCliente);
        void setDataElimCom(DataEliminarComentario* data);
        void setDataCrearP(DataCrearPromocion* data);
        void setDataElimSus(DataEliminarSuscripcion* data);
        void setCantidadComentarios(int c);

        //Alta Usuario
        bool ingresarCliente(DTCliente cliente);
        bool ingresarVendedor(DTVendedor vendedor);

        //Listado de Usuarios
        vector<DTCliente> obtenerListadoClientes();
        vector<DTVendedor> obtenerListadoVendedores();

        //Eliminar Comentario
        vector<string> obtenerListaNicknamesUsuarios();
        void seleccionarUsuario(string nickname); 
        vector<DTComentario> obtenerComentariosUsuario();
        void seleccionarComentario(int idComentario); 
        void eliminarComentario();
        
        //Crear Promocion
        void ingresarDatosPromocion(DTPromocion data);
        vector<string> obtenerListaNicknameVendedores();
        void seleccionarVendedor(string nickname);
        vector<DTCodigoNombre> obtenerListaProductosVendedor();
        void agregarProductoCantidad(DTCodigoCantidad parCodCant);  
        void confirmarAltaPromocion();

        //Realizar Compra
        vector<string> obtenerListaNicknamesClientes();
        Cliente* obtenerClienteCompra(string nickname);

        //Dejar comentario
        vector<DTComentario> obtenerListaComentariosProducto(int codigoProducto);
        void ingresarComentarioNuevo(string nickname, int codigoProducto, string comentario, DTFecha _fecha);
        void ingresarComentarioRespuesta(string nickname, int codigoProducto, string comentario, DTFecha _fecha, int idPadre);
 
        //Consultar Notificaciones
        vector<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente);

        //Suscribirse a Notificaciones
        vector<DTVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente);
        void vendedoresASuscribirse(vector<DTVendedor> vendedores); 

        //Eliminar Suscripcion 
        vector<DTVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente);
        void seleccionarVendedoresAEliminarSuscripciones(vector<DTVendedor> vendedores);
        void eliminarSuscripciones();

        //Expediente de usuario
        DTExpedienteCliente obtenerInfoCliente(string nickname);
        DTExpedienteVendedor obtenerInfoVendedor(string nickname);

        //Enviar Producto
        vector<DTCodigoNombre> obtenerProductosVendedorEnvio(string nickVendedor);

        //Alta Producto
        Vendedor* obtenerVendedor(string vendedor);

};  

#endif