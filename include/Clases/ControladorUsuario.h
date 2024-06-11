#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../Datatypes/DTDireccion.h"
#include "../Datatypes/DTNotificacion.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DataCliente.h"
#include "../Datatypes/DataComentario.h"
//#include "../Datatypes/dataEliminarComentario.h"
#include "../Datatypes/ParCodigoCantidad.h"

#include "DataCrearPromocion.h"
#include "DataEliminarSuscripcion.h"

#include "Vendedor.h"

class Usuario;

//class ;

class ControladorUsuario
{
    private:
        static ControladorUsuario* instancia;
        ControladorUsuario();

        string nicknameC;
        //dataEliminarComentario dataElimCom;
        //DataCrearPromocion dataCrearP;
        DataEliminarSuscripcion dataElimSus;
        set<Usuario*> usuarios;
        set<Cliente*> clientes;
        set<Vendedor*> vendedores;

    public:
        static ControladorUsuario * getInstancia();

        //dataEliminarComentario getDataElimCom();
        DataCrearPromocion getDataCrearP();
        DataEliminarSuscripcion getDataElimSus();
    
        void setDataElimCom();
        void setDataCrearP();
        void setDataElimSus();

        //Eliminar Comentario
        bool ingresarCliente(DataCliente cliente);
        bool ingresarVendedor(DataVendedor vendedor);
        set<string> obtenerListaNicknamesUsuarios(); 
        set<DataComentario> obtenerComentariosUsuario();
        void seleccionarComentario(DataComentario comentario); 
        
        //Alta Promocion
        set<string> obtenerListaNicknameVendedores();
        void seleccionarVendedor(string nickname);
        void obtenerListaProductosVendedor();
        void agregarProductoCantidad(ParCodigoCantidad parCodCant);  
        void confirmarAltaPromocion();

        //Realizar Compra
        set<string> obtenerListaNicknamesClientes();
        void obtenerClienteCompra(string nickname);

        //Consultar Notificaciones
        set<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente);

        //Suscribirse a Notificaciones
        set<DataVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente);
        void vendedoresASuscribirse(set<DataVendedor> vendedores); 

        //Eliminar Suscripcion
        set<DataVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente);
        void seleccionarVendedoresAEliminarSuscripciones(set<DataVendedor> vendedores);
        void eliminarSuscripciones();
};

#endif