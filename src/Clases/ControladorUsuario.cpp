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
DataCrearPromocion ControladorUsuario::getDataCrearP(){ return DataCrearPromocion();}

DataEliminarSuscripcion ControladorUsuario::getDataElimSus(){return DataEliminarSuscripcion();}

void ControladorUsuario::setDataElimCom(){}
void ControladorUsuario::setDataCrearP(){}
void ControladorUsuario::setDataElimSus(){}


    //Eliminar Comentario
bool ControladorUsuario::ingresarCliente(DataCliente cliente){return true;}

bool ControladorUsuario::ingresarVendedor(DataVendedor vendedor){return true;}

set<string> ControladorUsuario::obtenerListaNicknamesUsuarios(){return {};}

set<DataComentario> ControladorUsuario::obtenerComentariosUsuario(){return {};}

void ControladorUsuario::seleccionarComentario(DataComentario comentario){} 


    //Alta Promocion
set<string> ControladorUsuario::obtenerListaNicknameVendedores(){return {};}

void ControladorUsuario::seleccionarVendedor(string nickname){}

void ControladorUsuario::obtenerListaProductosVendedor(){}

void ControladorUsuario::agregarProductoCantidad(ParCodigoCantidad parCodCant){}  

void ControladorUsuario::confirmarAltaPromocion(){}


    //Realizar Compra
set<string> ControladorUsuario::obtenerListaNicknamesClientes(){return {};}

void ControladorUsuario::obtenerClienteCompra(string nickname){}


    //Consultar Notificaciones
set<DTNotificacion> ControladorUsuario::obtenerListaNotificaciones(string nicknameCliente){return {};}


    //Suscribirse a Notificaciones
set<DataVendedor> ControladorUsuario::obtenerListaVendedoresNoSuscritos(string nicknameCliente){return {};}

void ControladorUsuario::vendedoresASuscribirse(set<DataVendedor> vendedores){} 


    //Eliminar Suscripcion
set<DataVendedor> ControladorUsuario::obtenerListaVendedoresSuscritos(string nicknameCliente){return {};}

void ControladorUsuario::seleccionarVendedoresAEliminarSuscripciones(set<DataVendedor> vendedores){}

void ControladorUsuario::eliminarSuscripciones(){}

