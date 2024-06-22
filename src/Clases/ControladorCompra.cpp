#include "../../include/Clases/ControladorCompra.h"

ControladorCompra* ControladorCompra::instancia = nullptr;

ControladorCompra::ControladorCompra(){
    cantidadProductos = 0;
}

ControladorCompra* ControladorCompra::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorCompra();
    }
    return instancia;
}

ControladorCompra::~ControladorCompra(){
    for (unsigned int i = 0; i < compras.size(); i++){
        delete compras[i];
    }

    map<string, Promocion*>::iterator itP;
    for (itP = promociones.begin(); itP != promociones.end(); ++itP){
        delete itP->second;
    }
    
    map<int, Producto*>::iterator it;
    for (it = productos.begin(); it != productos.end(); ++it){
        delete it->second;
    }

}

void ControladorCompra::crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP){
    vector<DTCodigoCantidad> parCodCant = dataCrearP->getProdCant();
    vector<DTProducto> dProductos;
    vector<CantMin*> cantidadesMinimas;
    Promocion* promo = new Promocion(dataCrearP->getInfoP());
    for(unsigned int i = 0; i < parCodCant.size(); i++){
        Producto* productoActual = productos[parCodCant[i].getCodigo()];
        dProductos.push_back(productoActual->getDataProducto());
        CantMin* cantMin = new CantMin(parCodCant[i].getCantidad(), productoActual);
        promo->agregarCantMinProducto(cantMin);
        productoActual->setCantMin(cantMin);
        cantMin->setPromocion(promo);
    }
    promociones[promo->getNombre()] = promo;
    v->agregarPromocionYNotificar(dProductos, promo->getNombre(), promo);
}

vector<string> ControladorCompra::obtenerListaNicknamesClientes(){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* CU = f->getIUsuario();
    return CU->obtenerListaNicknamesClientes();
}

void ControladorCompra::seleccionarCliente(string nickname){
    dataInfoC = new DataInfoCompra(nickname);
}

vector<DTProducto> ControladorCompra::obtenerListaProductos(){
    vector<DTProducto> dataProductos;
    for (std::map<int, Producto*>::iterator it = productos.begin(); it != productos.end(); ++it) {
        dataProductos.push_back(it->second->getDataProducto());
    }
    return dataProductos;
}

void ControladorCompra::agregarProductoCantidad(DTCodigoCantidad parCodCant){
    vector<DTCodigoCantidad> lista = dataInfoC->getProdCant();
    bool existe = false;
    for(unsigned int i = 0; i < lista.size(); i++){
        existe = existe || lista[i].getCodigo()==parCodCant.getCodigo();
    }
    if (!existe){
        lista.push_back(parCodCant);
        dataInfoC->setProdCant(lista);
    }
}

DTCompraProductos ControladorCompra::obtenerInfoCompra(){
    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();
    DTFecha fechaActual = IF->getFechaActual();
    float montoFinal = 0;
    vector<DTProducto> dProductos;
    vector<DTCodigoCantidad> productosCompra = dataInfoC->getProdCant();

    for(unsigned int i = 0; i < productosCompra.size(); i++){
        Producto* productoActual = productos[productosCompra[i].getCodigo()];
        if (productoActual!=NULL){
            dProductos.push_back(productoActual->getDataProducto());
            montoFinal += productoActual->getPrecio() * productosCompra[i].getCantidad(); // Para cada producto que este dentro de dataInfoC sumo el precio al total
        }
    }
    for (std::map<string, Promocion*>::iterator it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion* promocionActual = it->second;
        if ( !(promocionActual->getFechaVenc()<=fechaActual)){
            vector<DTCodigoCantidad> productosPromocion = promocionActual->aplicaEnCompra(dataInfoC->getProdCant());
            if(!productosPromocion.empty()){
                float descuento = promocionActual->getDescuento();
                for(unsigned int i = 0; i < productosPromocion.size(); i++){
                    DTCodigoCantidad parCodCantActual = productosPromocion[i];
                    Producto* productoActual = productos[parCodCantActual.getCodigo()];
                    montoFinal -= productoActual->getPrecio() * ((descuento/100)) * productosPromocion[i].getCantidad(); // Para cada producto que aplica le resto al monto final el descuento aplicado a ese producto
                }
             }
        }
    }
    dataInfoC->setMontoF(montoFinal);
    return DTCompraProductos(montoFinal, dProductos, fechaActual);
}

void ControladorCompra::confirmarCompra(DTFecha _fecha){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* CU = f->getIUsuario();
    Cliente* cliente = CU->obtenerClienteCompra(dataInfoC->getCliente());
    Compra* compra = new Compra(cliente, dataInfoC->getMontoF());
    compra->setFecha(_fecha);
    vector<DTCodigoCantidad> productosCompra = dataInfoC->getProdCant();

    for(unsigned int i = 0; i < productosCompra.size(); i++){
        Producto* productoActual = productos[productosCompra[i].getCodigo()];
        if (productoActual!=NULL){
            productoActual->crearEnvio(compra, productosCompra[i].getCantidad());
            productoActual->setStock(productoActual->getStock() - productosCompra[i].getCantidad());
        }
    }
    vector<Compra*> comprasCliente = cliente->getCompras();
    comprasCliente.push_back(compra);
    cliente->setCompras(comprasCliente);
    compras.push_back(compra);
    delete dataInfoC;
    dataInfoC = NULL;
}

    //Enviar Producto
vector<DTCodigoNombre> ControladorCompra::obtenerProductosPendientesEnvio(string nickVendedor){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* IU = f->getIUsuario();
    vector<DTCodigoNombre> prodPend = IU->obtenerProductosVendedorEnvio(nickVendedor);
    return prodPend;
}

vector<DTNickFecha> ControladorCompra::obtenerParNickFechaEnvio(int producto){
    return productos[producto]->obtenerClienteFecha();
} 

void ControladorCompra::enviarProducto(int _producto, string _cliente){
    vector<CompraProducto*> comprasProducto = productos[_producto]->getCompraProducto();
    
    for(CompraProducto* cp : comprasProducto){
        if(cp->esCompraDeCliente(_cliente) && !cp->getEstado()){
            cp->setEstado(true);
            break;
        }
    }
}

vector<string> ControladorCompra::obtenerListaNicknameVendedores(){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* IU = f->getIUsuario();
    return IU->obtenerListaNicknameVendedores();
} 

//Algun caso de uso
Producto* ControladorCompra::obtenerProducto(int _codigoProducto){
    return productos[_codigoProducto];
}

vector<DTPromocion> ControladorCompra::obtenerInfoPromociones(DTFecha _fecha){
    vector<DTPromocion> dPromociones;
    for (std::map<string, Promocion*>::iterator it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion* promocionsActual = it->second;
        if (_fecha<=promocionsActual->getFechaVenc()){
            dPromociones.push_back(it->second->getDataPromocion());
        }
    }
    return dPromociones;
}

string ControladorCompra::obtenerInfoPromocion(string nombre){
    Promocion* promocion = promociones[nombre];
    string info = "Vendedor: " + promocion->getCantidadesMinimas()[0]->getProducto()->getVendedor()->getNickname();
    info += "\nProductos: ";
    for(unsigned int i = 0 ; i < promocion->getCantidadesMinimas().size(); i++){
        info += "\n\t" + promocion->getCantidadesMinimas()[i]->getProducto()->getDataProducto().toString() + " | Cantidad minima: " + to_string(promocion->getCantidadesMinimas()[i]->getCantidadMinima());
    }
    return info;
}

    //Alta de Producto
void ControladorCompra::confirmarAltaProducto(Categoria categoria, string nombre, string descripcion, int stock, float precio, Vendedor* vendedor){

    cantidadProductos++; //codigo
    Producto* productoNuevo = new Producto(cantidadProductos, categoria, nombre, descripcion, stock, precio, vendedor);
    productos[cantidadProductos] = productoNuevo;

    vendedor->setProducto(productoNuevo);

}


void ControladorCompra::cancelarCompra(){
    delete dataInfoC;
    dataInfoC = NULL;
}
