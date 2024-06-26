#include "../../include/Clases/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario :: ControladorUsuario(){
    nicknameC ="";
    dataElimCom = NULL;
    dataCrearP = NULL;
    dataElimSus = NULL;
    cantidadComentarios = 0;
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){
    map<string,Usuario*>::iterator itUsuario;

    for(itUsuario = usuarios.begin(); itUsuario != usuarios.end(); ++itUsuario){ //elimino usuarios (CLIENTES Y VENDEDORES INCLUIDOS)
        delete itUsuario->second;
    }

    //delete dataCrearP;
    //delete dataElimCom;
    //delete dataElimSus;    
};

    //GETTERS
string ControladorUsuario::getNickname(){ return nicknameC;}
DataEliminarComentario* ControladorUsuario::getDataElimCom(){ return dataElimCom;}
DataCrearPromocion* ControladorUsuario::getDataCrearP(){ return dataCrearP;}
DataEliminarSuscripcion* ControladorUsuario::getDataElimSus(){ return dataElimSus;}
int ControladorUsuario::getCantidadComentarios(){ return cantidadComentarios;}

    //SETTERS
void ControladorUsuario::setNickname(string nickCliente){ nicknameC = nickCliente;}
//Recordar agregar la liberacion de memoria del *data anterior
void ControladorUsuario::setDataElimCom(DataEliminarComentario* data){ dataElimCom = data;} 
void ControladorUsuario::setDataCrearP(DataCrearPromocion* data){ dataCrearP = data;}
void ControladorUsuario::setDataElimSus(DataEliminarSuscripcion* data){ dataElimSus = data;}
void ControladorUsuario::setCantidadComentarios(int c){cantidadComentarios = c;}


    //OPERACIONES

    //Alta Usuario
bool ControladorUsuario::ingresarCliente(DTCliente cliente){
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

bool ControladorUsuario::ingresarVendedor(DTVendedor vendedor){
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

    //Listado de Usuarios
vector<DTVendedor> ControladorUsuario::obtenerListadoVendedores(){
    vector<DTVendedor> v;
    for(const pair<string, Vendedor*> par : vendedores){  
        v.push_back(par.second->getDataVendedor());
    }
    return v;
};
vector<DTCliente> ControladorUsuario::obtenerListadoClientes(){
    vector<DTCliente> c;
    for(const pair<string, Cliente*> par : clientes){  
        c.push_back(par.second->getDataCliente());
    }
    return c;
};

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

vector<DTComentario> ControladorUsuario::obtenerComentariosUsuario(){
    string nickUsuario = dataElimCom->getNickname();

    vector<DTComentario> comentarios;
    comentarios = (usuarios[nickUsuario])->obtenerComentarios();

    return comentarios;
}

void ControladorUsuario::seleccionarComentario(int _idComentario){
    dataElimCom->setIdComentario(_idComentario);
}

void ControladorUsuario::eliminarComentario(){
    string nickUsuario = dataElimCom->getNickname();
    (usuarios[nickUsuario])->eliminarComentario( dataElimCom->getIdComentario() );
    delete dataElimCom;;
    dataElimCom = NULL;
} 

    //Crear Promocion
void ControladorUsuario::ingresarDatosPromocion(DTPromocion data){ 
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

vector<DTCodigoNombre> ControladorUsuario::obtenerListaProductosVendedor(){
    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();
    
    string vendedor = dataCrearP->getVendedor();

    vector<DTCodigoNombre> productos;
    productos = (vendedores[vendedor])->obtenerProductos(IF->getFechaActual());

    return productos;
}

void ControladorUsuario::agregarProductoCantidad(DTCodigoCantidad parCodCant){
    vector<DTCodigoCantidad> prodCant = dataCrearP->getProdCant();
    long unsigned int tamanio = prodCant.size();
    bool fueAgregado = false;

    long unsigned int it = 0;
    while( it < tamanio && !fueAgregado){
        fueAgregado = (prodCant[it].getCodigo() == parCodCant.getCodigo());
        ++it;
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

    delete dataCrearP;
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

    //Dejar comentario
vector<DTComentario> ControladorUsuario::obtenerListaComentariosProducto(int codigoProducto){

    vector<DTComentario> lista;

    map<string,Usuario*>::iterator itU;

    for(itU = usuarios.begin(); itU != usuarios.end(); ++itU){
        Usuario* u = itU->second;
        vector<DTComentario> comentariosUsuario = u->obtenerComentarios();
        for (unsigned int i = 0; i < comentariosUsuario.size(); i++){
            if (comentariosUsuario[i].getCodigoProducto() == codigoProducto){
                lista.push_back(comentariosUsuario[i]);
            }
        }
    }
    return lista;
}

void ControladorUsuario::ingresarComentarioNuevo(string nickname, int codigoProducto, string comentario, DTFecha _fecha){

    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    Producto* pr = IC->obtenerProducto(codigoProducto);

    Usuario* u = usuarios[nickname];
    cantidadComentarios++;
    u->agregarComentarioNuevo(comentario, pr->getCodigo(), _fecha, cantidadComentarios);
}

void ControladorUsuario::ingresarComentarioRespuesta(string nickname, int codigoProducto, string comentario, DTFecha _fecha, int idPadre){
    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    Producto* pr = IC->obtenerProducto(codigoProducto);

    Usuario* u = usuarios[nickname];

    map<string,Usuario*>::iterator it;
    Comentario* comentarioPadre = NULL;
    for(it = usuarios.begin(); it != usuarios.end(); ++it){
        comentarioPadre = it->second->buscarComentario(idPadre);
        if (comentarioPadre != NULL){
            break;
        }
    }

    cantidadComentarios++;
    u->agregarComentarioRespuesta(comentario, pr->getCodigo(), _fecha, cantidadComentarios, comentarioPadre); 
};

    //Consultar Notificaciones
vector<DTNotificacion> ControladorUsuario::obtenerListaNotificaciones(string nicknameCliente){
    return clientes[nicknameCliente]->getNotificaciones();
}


    //Suscribirse a Notificaciones
vector<DTVendedor> ControladorUsuario::obtenerListaVendedoresNoSuscritos(string nicknameCliente){
    nicknameC = nicknameCliente;
    vector<DTVendedor> listaVendNoSus;

    DTVendedor dtVend;
    for(const pair<string, Vendedor*> par : vendedores){
        par.second->estaSuscrito(nicknameCliente);
        if(!(par.second->estaSuscrito(nicknameCliente))){
            dtVend = par.second->getDataVendedor();
            listaVendNoSus.push_back(par.second->getDataVendedor());
        }
    }

    return listaVendNoSus;
}

void ControladorUsuario::vendedoresASuscribirse(vector<DTVendedor> _vendedores){
    Cliente* cliente = clientes[nicknameC];

    for(unsigned int i = 0; i<_vendedores.size(); i++){
        Vendedor* vendedor = vendedores[_vendedores[i].getNickname()];
        vendedor->agregarSuscriptor(cliente);
        cliente->agregarSuscripcion(vendedor);
    }
} 

    //Eliminar Suscripcion
vector<DTVendedor> ControladorUsuario::obtenerListaVendedoresSuscritos(string nicknameCliente){
    dataElimSus = new DataEliminarSuscripcion();
    dataElimSus->setNickname(nicknameCliente);
    return clientes[nicknameCliente]->obtenerSuscripciones();
}

void ControladorUsuario::seleccionarVendedoresAEliminarSuscripciones(vector<DTVendedor> _vendedores){
    dataElimSus->setVendedores(_vendedores);
}

void ControladorUsuario::eliminarSuscripciones(){
    Cliente* cliente = clientes[nicknameC];
    vector<DTVendedor> elimVend = dataElimSus->getVendedores();
    cliente->eliminarSuscripciones(elimVend);

    for(const DTVendedor &vend : elimVend){
        vendedores[vend.getNickname()]->eliminarSuscriptor(cliente);
    }
    delete dataElimSus;;
    dataElimSus = NULL;
}

//Enviar Producto
vector<DTCodigoNombre> ControladorUsuario::obtenerProductosVendedorEnvio(string nickVendedor){
    vector<DTCodigoNombre> res;
    res = vendedores[nickVendedor]->obtenerProductosPendientesEnvio();
    return res;
}

//Algun caso de uso
DTExpedienteCliente ControladorUsuario::obtenerInfoCliente(string nickname){
    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();
    DTFecha fechaActual = IF->getFechaActual();
    map<string,Cliente*>::iterator itC;
    itC = clientes.find(nickname);
    if(itC != clientes.end()){
        vector<Compra*> compras = itC->second->getCompras();
        vector<DTCompraProductos> vCompraProductos;
        for(unsigned int i = 0; i<compras.size(); i++){
            vector<CompraProducto*> compraProductos = compras[i]->obtenerCompraProductos();
            vector<DTProducto> vDTProd;
            for(unsigned int j = 0; j < compraProductos.size(); j++){
                DTProducto dProd = compraProductos[j]->getProducto()->getDataProducto();
                vDTProd.push_back(dProd);
            }
            vCompraProductos.push_back(DTCompraProductos(compras[i]->getMontoFinal(), vDTProd, compras[i]->getFecha()));
        }
        return DTExpedienteCliente(vCompraProductos, itC->second->getDataCliente());
    }
    return DTExpedienteCliente();
}
DTExpedienteVendedor ControladorUsuario::obtenerInfoVendedor(string nickname){

    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();
    DTFecha fechaActual = IF->getFechaActual();

    map<string,Vendedor*>::iterator itV;
    itV = vendedores.find(nickname);

    if(itV!=vendedores.end()){
        return DTExpedienteVendedor(itV->second->getDataVendedor(), itV->second->obtenerInfoProductos(), itV->second->obtenerInfoPromocionesVigentes(fechaActual));
    }
    return DTExpedienteVendedor();
}




//Alta Producto

Vendedor* ControladorUsuario::obtenerVendedor(string vendedor){
    map<string,Vendedor*>::iterator itV;
    itV = vendedores.find(vendedor);
    return itV == vendedores.end() ? NULL : vendedores[vendedor];
}
