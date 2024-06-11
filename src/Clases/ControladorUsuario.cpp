#include "../../include/Clases/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario :: ControladorUsuario(){
    nicknameC ="";
    //dataElimCom = DataEliminarComentario();
    dataCrearP = DataCrearPromocion();
    dataElimSus = DataEliminarSuscripcion();
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

    //GETTERS
string ControladorUsuario::getNickname(){ return nicknameC;}
//dataEliminarComentario ControladorUsuario::getDataElimCom(){ return dataElimCom}
DataCrearPromocion ControladorUsuario::getDataCrearP(){ return dataCrearP;}
DataEliminarSuscripcion ControladorUsuario::getDataElimSus(){ return dataElimSus;}

    //SETTERS
void ControladorUsuario::setNickname(string nickCliente){ nicknameC = nickCliente;}
//void ControladorUsuario::setDataElimCom(dataEliminarComentario data){ dataElimCom = data;}
void ControladorUsuario::setDataCrearP(DataCrearPromocion data){ dataCrearP = data;}
void ControladorUsuario::setDataElimSus(DataEliminarSuscripcion data){ dataElimSus = data;}


    //OPERACIONES

    //Eliminar Comentario
bool ControladorUsuario::ingresarCliente(DataCliente cliente){return true;}

bool ControladorUsuario::ingresarVendedor(DataVendedor vendedor){return true;}

set<string> ControladorUsuario::obtenerListaNicknamesUsuarios(){return {};}

set<DataComentario> ControladorUsuario::obtenerComentariosUsuario(){return {};}

void ControladorUsuario::seleccionarComentario(DataComentario comentario){} 


    //Crear Promocion

void ControladorUsuario::ingresarDatosPromocion(DataPromocion data){ 
    dataCrearP.setInfoP(data);
}

vector<string> ControladorUsuario::obtenerListaNicknameVendedores(){ 
    vector<string> nicknameVendedores;

    for(const auto& par : vendedores){  //auto o map<string, Vendedor*>::iterator?
        nicknameVendedores.push_back(par.first);
    }
    
    return nicknameVendedores;
}

void ControladorUsuario::seleccionarVendedor(string nickname){
    dataCrearP.setVendedor(nickname);
}

vector<ParCodigoNombre> ControladorUsuario::obtenerListaProductosVendedor(){
    string vendedor = dataCrearP.getVendedor();

    vector<ParCodigoNombre> productos;
    productos = (vendedores[vendedor])->obtenerProductos();

    return productos;
}

void ControladorUsuario::agregarProductoCantidad(ParCodigoCantidad parCodCant){

}  

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

