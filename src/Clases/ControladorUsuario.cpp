#include "../../include/Clases/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario :: ControladorUsuario(){
    nicknameC ="";
    //dataElimCom = DataEliminarComentario();
    //dataCrearP = DataCrearPromocion();
    dataElimSus = DataEliminarSuscripcion();
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}


//dataEliminarComentario ControladorUsuario::getDataElimCom(){}
DataCrearPromocion ControladorUsuario::getDataCrearP(){}

DataEliminarSuscripcion ControladorUsuario::getDataElimSus(){}

void ControladorUsuario::setDataElimCom(){}
void ControladorUsuario::setDataCrearP(){}
void ControladorUsuario::setDataElimSus(){}


    //Eliminar Comentario
bool ControladorUsuario::ingresarCliente(DataCliente cliente){}

bool ControladorUsuario::ingresarVendedor(DataVendedor vendedor){}

set<string> ControladorUsuario::obtenerListaNicknamesUsuarios(){}

set<DataComentario> ControladorUsuario::obtenerComentariosUsuario(){}

void ControladorUsuario::seleccionarComentario(DataComentario comentario){} 


    //Alta Promocion
set<string> ControladorUsuario::obtenerListaNicknameVendedores(){}

void ControladorUsuario::seleccionarVendedor(string nickname){}

void ControladorUsuario::obtenerListaProductosVendedor(){}

void ControladorUsuario::agregarProductoCantidad(ParCodigoCantidad parCodCant){}  

void ControladorUsuario::confirmarAltaPromocion(){}


    //Realizar Compra
set<string> ControladorUsuario::obtenerListaNicknamesClientes(){}

void ControladorUsuario::obtenerClienteCompra(string nickname){}


    //Consultar Notificaciones
set<DTNotificacion> ControladorUsuario::obtenerListaNotificaciones(string nicknameCliente){}


    //Suscribirse a Notificaciones
set<DataVendedor> ControladorUsuario::obtenerListaVendedoresNoSuscritos(string nicknameCliente){}

void ControladorUsuario::vendedoresASuscribirse(set<DataVendedor> vendedores){} 


    //Eliminar Suscripcion
set<DataVendedor> ControladorUsuario::obtenerListaVendedoresSuscritos(string nicknameCliente){}

void ControladorUsuario::seleccionarVendedoresAEliminarSuscripciones(set<DataVendedor> vendedores){}

void ControladorUsuario::eliminarSuscripciones(){}

