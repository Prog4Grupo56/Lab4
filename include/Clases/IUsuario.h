#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <vector>
#include "../Datatypes/DTCliente.h"
#include "../Datatypes/DTVendedor.h"
#include "../Datatypes/DTComentario.h"
#include "../Datatypes/DTCodigoCantidad.h"
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/DTCodigoNombre.h"
#include "../Datatypes/DTNotificacion.h"

class Cliente;

class IUsuario {
public:
    //Alta Usuario
    virtual bool ingresarCliente(DTCliente cliente) = 0;
    virtual bool ingresarVendedor(DTVendedor vendedor) = 0;

    //Eliminar Comentario
    virtual vector<string> obtenerListaNicknamesUsuarios() = 0;
    virtual void seleccionarUsuario(string nickname) = 0;
    virtual vector<DTComentario> obtenerComentariosUsuario() = 0;
    virtual void seleccionarComentario(int idComentario) = 0;
    virtual void eliminarComentario() = 0;

    //Crear Promocion
    virtual void ingresarDatosPromocion(DTPromocion data) = 0;
    virtual vector<string> obtenerListaNicknameVendedores() = 0;
    virtual void seleccionarVendedor(string nickname) = 0;
    virtual vector<DTCodigoNombre> obtenerListaProductosVendedor() = 0;
    virtual void agregarProductoCantidad(DTCodigoCantidad parCodCant) = 0;
    virtual void confirmarAltaPromocion() = 0;

    //Eliminar Suscripcion
    virtual vector<string> obtenerListaNicknamesClientes() = 0;
    virtual Cliente* obtenerClienteCompra(string nickname) = 0;
    virtual void seleccionarVendedoresAEliminarSuscripciones(vector<DTVendedor> vendedores) = 0;
    virtual vector<DTVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente) = 0;
    virtual void eliminarSuscripciones() = 0;

    //Suscribirse a Notificaciones
    virtual vector<DTVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente) = 0;
    virtual void vendedoresASuscribirse(vector<DTVendedor> vendedores) = 0;

    //Consultar Notificaiones
    virtual vector<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente) = 0;

    //Listado Usuarios
    virtual vector<DTCliente> obtenerListadoClientes() = 0;
    virtual vector<DTVendedor> obtenerListadoVendedores() = 0;

    //Dejar Comentario
    virtual vector<DTComentario> obtenerListaComentariosProducto(int producto) = 0;
    virtual void ingresarComentarioNuevo(string nickname, int codigoProducto, string comentario, DTFecha _fecha) = 0;
    virtual void ingresarComentarioRespuesta(string nickname, int codigoProducto, string comentario, DTFecha _fecha, int idPadre) = 0;

    virtual string obtenerInfoUsuario(string nickname) = 0;

    //Enviar Producto
    virtual vector<DTCodigoNombre> obtenerProductosVendedorEnvio(string nickVendedor) = 0;

    //Alta Producto
    virtual Vendedor* obtenerVendedor(string vendedor) = 0;
};

#endif
