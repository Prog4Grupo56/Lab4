#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <vector>
#include "../Datatypes/DataCliente.h"
#include "../Datatypes/DataVendedor.h"
#include "../Datatypes/DataComentario.h"
#include "../Datatypes/ParCodigoCantidad.h"
#include "../Datatypes/DataPromocion.h"
#include "../Datatypes/ParCodigoNombre.h"
#include "../Datatypes/DTNotificacion.h"

class Cliente;

class IUsuario {
public:

    //Alta Usuario
    virtual bool ingresarCliente(DataCliente cliente) = 0;
    virtual bool ingresarVendedor(DataVendedor vendedor) = 0;

    //Eliminar Comentario
    virtual vector<string> obtenerListaNicknamesUsuarios() = 0;
    virtual void seleccionarUsuario(string nickname) = 0;
    virtual vector<DataComentario> obtenerComentariosUsuario() = 0;
    virtual void seleccionarComentario(int idComentario) = 0;
    virtual void eliminarComentario() = 0;

    //Crear Promocion
    virtual void ingresarDatosPromocion(DataPromocion data) = 0;
    virtual vector<string> obtenerListaNicknameVendedores() = 0;
    virtual void seleccionarVendedor(string nickname) = 0;
    virtual vector<ParCodigoNombre> obtenerListaProductosVendedor() = 0;
    virtual void agregarProductoCantidad(ParCodigoCantidad parCodCant) = 0;
    virtual void confirmarAltaPromocion() = 0;

    //Eliminar Suscripcion
    virtual vector<string> obtenerListaNicknamesClientes() = 0;
    virtual Cliente* obtenerClienteCompra(string nickname) = 0;
    virtual void seleccionarVendedoresAEliminarSuscripciones(vector<DataVendedor> vendedores) = 0;
    virtual vector<DataVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente) = 0;
    virtual void eliminarSuscripciones() = 0;

    //Suscribirse a Notificaciones
    virtual vector<DataVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente) = 0;
    virtual void vendedoresASuscribirse(vector<DataVendedor> vendedores) = 0;

    //Consultar Notificaiones
    virtual vector<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente) = 0;

    //Listado Usuarios
    virtual vector<DataCliente> obtenerListadoClientes() = 0;
    virtual vector<DataVendedor> obtenerListadoVendedores() = 0;

    //Dejar Comentario
    virtual vector<DataComentario> obtenerListaComentariosProducto(int producto) = 0;
    virtual void ingresarComentarioNuevo(string nickname, int codigoProducto, string comentario, DTFecha _fecha) = 0;
    virtual void ingresarComentarioRespuesta(string nickname, int codigoProducto, string comentario, DTFecha _fecha, int idPadre) = 0;

    virtual string obtenerInfoUsuario(string nickname) = 0;

    //Enviar Producto
    virtual vector<ParCodigoNombre> obtenerProductosVendedorEnvio(string nickVendedor) = 0;

    //Alta Producto
    virtual Vendedor* obtenerVendedor(string vendedor) = 0;
};

#endif
