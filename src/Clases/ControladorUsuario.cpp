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
    if(noExiste){
        Cliente* c = new Cliente(cliente); 
        usuarios.insert(pair<string, Usuario*>(nickCliente, c));
        clientes.insert(pair<string, Cliente*>(nickCliente, c));
    }
    return noExiste;
}

bool ControladorUsuario::ingresarVendedor(DataVendedor vendedor){
    bool noExiste = true;
    string nickCliente = vendedor.getNickname();

    map<string, Usuario*>::const_iterator it = usuarios.begin();
    while( it!=usuarios.end() && noExiste){
        noExiste = it->first != nickCliente;
        ++it;
    }
    if(noExiste){
        Vendedor* v = new Vendedor(vendedor); 
        usuarios.insert(pair<string, Usuario*>(nickCliente, v));
        vendedores.insert(pair<string, Vendedor*>(nickCliente, v));
    }
    return noExiste;
}

    //Eliminar Comentario
vector<string> ControladorUsuario::obtenerListaNicknamesUsuarios(){
    vector<string> listaUsuarios;

    for(const pair<string, Usuario*> par : usuarios){
        listaUsuarios.push_back(par.first);
    }
    
    return listaUsuarios;
}

void ControladorUsuario::seleccionarUsuario(string nickname){
    dataElimCom = new DataEliminarComentario();
    dataElimCom->setNickname(nickname);
}

vector<DataComentario> ControladorUsuario::obtenerComentariosUsuario(){
    string nickUsuario = dataElimCom->getNickname();

    vector<DataComentario> comentarios;
    comentarios = (usuarios[nickUsuario])->obtenerComentarios();

    return comentarios;
}

void ControladorUsuario::seleccionarComentario(DataComentario comentario){
    int idComentario = comentario.getIdComentario();
    dataElimCom->setIdComentario(idComentario);
}

void ControladorUsuario::eliminarComentario(){
    string nickUsuario = dataElimCom->getNickname();
    (usuarios[nickUsuario])->eliminarComentario( dataElimCom->getIdComentario() );
    dataElimCom->~DataEliminarComentario();
    dataElimCom = NULL;
} 

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
vector<string> ControladorUsuario::obtenerListaNicknamesClientes(){
    vector<string> nicknameClientes;
    for(const pair<string, Cliente*> par : clientes){  
        nicknameClientes.push_back(par.first);
    }
    return nicknameClientes;
}

Cliente* ControladorUsuario::obtenerClienteCompra(string nickname){
    return clientes[nickname];
}


    //Consultar Notificaciones
vector<DTNotificacion> ControladorUsuario::obtenerListaNotificaciones(string nicknameCliente){
    return clientes[nicknameCliente]->getNotificaciones();
}


    //Suscribirse a Notificaciones
vector<DataVendedor> ControladorUsuario::obtenerListaVendedoresNoSuscritos(string nicknameCliente){
    nicknameC = nicknameCliente;
    vector<DataVendedor> listaVendNoSus;

    DataVendedor dtVend;
    for(const pair<string, Vendedor*> par : vendedores){
        par.second->estaSuscrito(nicknameCliente);
        if(!(par.second->estaSuscrito(nicknameCliente))){
            dtVend = par.second->getDataVendedor();
            listaVendNoSus.push_back(par.second->getDataVendedor());
        }
    }

    return listaVendNoSus;
}

void ControladorUsuario::vendedoresASuscribirse(vector<DataVendedor> _vendedores){
    Cliente* cliente = clientes[nicknameC];

    for(const pair<string, Vendedor*> par : vendedores){
        par.second->agregarSuscriptor(cliente);
        cliente->agregarSuscripcion(par.second);
    }
} 

    //Eliminar Suscripcion
vector<DataVendedor> ControladorUsuario::obtenerListaVendedoresSuscritos(string nicknameCliente){
    dataElimSus = new DataEliminarSuscripcion();
    dataElimSus->setNickname(nicknameCliente);
    return clientes[nicknameCliente]->obtenerSuscripciones();
}

void ControladorUsuario::seleccionarVendedoresAEliminarSuscripciones(vector<DataVendedor> _vendedores){
    dataElimSus->setVendedores(_vendedores);
}

void ControladorUsuario::eliminarSuscripciones(){
    Cliente* cliente = clientes[nicknameC];
    vector<DataVendedor> elimVend = dataElimSus->getVendedores();
    cliente->eliminarSuscripciones(elimVend);

    for(const DataVendedor &vend : elimVend){
        vendedores[vend.getNickname()]->eliminarSuscriptor(cliente);
    }
    dataElimSus->~DataEliminarSuscripcion();
    dataElimSus = NULL;
}

