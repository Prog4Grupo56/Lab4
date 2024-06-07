#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>
#include "DataCliente.h"
#include "DataVendedor.h"
#include "DataComentario.h"
#include "Cliente.h"
#include "ParCodigoCantidad.h"
//#include "DataPromocion.h"
//#include "ParCodigoNombre.h"
//#include "DTNotificacion.h"

class IUsuario {
public:

    virtual bool ingresarCliente(DataCliente cliente) = 0;
    virtual bool ingresarVendedor(DataVendedor vendedor) = 0;
    virtual set<string> obtenerListaNicknamesUsuarios() = 0;
    virtual void seleccionarUsuario(string nickname) = 0;
    virtual set<DataComentario> obtenerComentariosUsuario() = 0;
    virtual void seleccionarComentario(DataComentario comentario) = 0;
    virtual void eliminarComentario() = 0;
    // virtual vector<string> ingresarDatosPromocion(DataPromocion data) = 0;
    virtual set<string> obtenerListaNicknameVendedores() = 0;
    virtual void seleccionarVendedor(string nickname) = 0;
    // virtual set<ParCodigoNombre> obtenerListaProductosVendedor(string nickname) = 0;
    virtual void agregarProductoCantidad(ParCodigoCantidad parCodCant) = 0;
    virtual void confirmarAltaPromocion() = 0;
    virtual set<string> obtenerListaNicknamesClientes() = 0;
    virtual Cliente obtenerClienteCompra(string nickname) = 0;
    virtual void seleccionarVendedoresAEliminarSuscripciones(set<DataVendedor> vendedores) = 0;
    virtual set<DataVendedor> obtenerListaVendedoresSuscritos(string nicknameCliente) = 0;
    virtual void eliminarSuscripciones() = 0;
    virtual set<DataVendedor> obtenerListaVendedoresNoSuscritos(string nicknameCliente) = 0;
    virtual void vendedoresASuscribirse(set<DataVendedor> vendedores) = 0;
    //virtual set<DTNotificacion> obtenerListaNotificaciones(string nicknameCliente) = 0;
    
};

#endif
