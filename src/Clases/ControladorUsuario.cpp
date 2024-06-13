#include "../../include/Clases/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario :: ControladorUsuario(){
    nicknameC ="";
    dataElimCom = NULL;
    dataCrearP = NULL;
    dataElimSus = NULL;
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

    //GETTERS
string ControladorUsuario::getNickname(){ return nicknameC;}
DataEliminarComentario* ControladorUsuario::getDataElimCom(){ return dataElimCom;}
DataCrearPromocion* ControladorUsuario::getDataCrearP(){ return dataCrearP;}
DataEliminarSuscripcion* ControladorUsuario::getDataElimSus(){ return dataElimSus;}

    //SETTERS
void ControladorUsuario::setNickname(string nickCliente){ nicknameC = nickCliente;}
//Recordar agregar la liberacion de memoria del *data anterior
void ControladorUsuario::setDataElimCom(DataEliminarComentario* data){ dataElimCom = data;} 
void ControladorUsuario::setDataCrearP(DataCrearPromocion* data){ dataCrearP = data;}
void ControladorUsuario::setDataElimSus(DataEliminarSuscripcion* data){ dataElimSus = data;}


    //OPERACIONES

    //Alta Usuario
bool ControladorUsuario::ingresarCliente(DataCliente cliente){
    bool noExiste = true;
    string nickCliente = cliente.getNickname();

    map<string, Usuario*>::const_iterator it = usuarios.begin();
    while( it!=usuarios.end() && noExiste){
        noExiste = it->first != nickCliente;
        ++it;
    }

    Cliente* c = new Cliente(cliente); 
    usuarios.insert(pair<string, Usuario*>(nickCliente, c) );
    return noExiste;
}

bool ControladorUsuario::ingresarVendedor(DataVendedor vendedor){return true;}

    //Eliminar Comentario
set<string> ControladorUsuario::obtenerListaNicknamesUsuarios(){return {};}

set<DataComentario> ControladorUsuario::obtenerComentariosUsuario(){return {};}

void ControladorUsuario::seleccionarComentario(DataComentario comentario){} 


    //Crear Promocion
void ControladorUsuario::ingresarDatosPromocion(DataPromocion data){ 
    dataCrearP = new DataCrearPromocion();
    dataCrearP->setInfoP(data);
}

vector<string> ControladorUsuario::obtenerListaNicknameVendedores(){ 
    vector<string> nicknameVendedores;
    for(const pair<string, Vendedor*> par : vendedores){  
        nicknameVendedores.push_back(par.first);
    }
    return nicknameVendedores;
}

void ControladorUsuario::seleccionarVendedor(string nickname){
    dataCrearP->setVendedor(nickname);
}

vector<ParCodigoNombre> ControladorUsuario::obtenerListaProductosVendedor(){
    string vendedor = dataCrearP->getVendedor();
    vector<ParCodigoNombre> productos;
    productos = (vendedores[vendedor])->obtenerProductos();
    return productos;
}

void ControladorUsuario::agregarProductoCantidad(ParCodigoCantidad parCodCant){
    vector<ParCodigoCantidad> prodCant = dataCrearP->getProdCant();
    long unsigned int tamanio = prodCant.size();
    bool fueAgregado = false;

    long unsigned int it = 0;
    while( it < tamanio || !fueAgregado){
        fueAgregado = (prodCant[it].getCodigo() == parCodCant.getCodigo());
    }
    if(!fueAgregado){
        dataCrearP->agregar(parCodCant);
    }
}  

void ControladorUsuario::confirmarAltaPromocion(){
    string nickVendedor = dataCrearP->getVendedor();
    Vendedor* v = (vendedores[nickVendedor]); 
    
    Fabrica* f = Fabrica::getInstance();
    ICompra* c = f->getICompra();

    c->crearPromocion(v, dataCrearP);

    dataCrearP->~DataCrearPromocion();
    dataCrearP = NULL;
}


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

