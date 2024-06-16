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

}

void ControladorCompra::crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP){
    vector<ParCodigoCantidad> parCodCant = dataCrearP->getProdCant();
    vector<DataProducto> dProductos;
    vector<CantMin*> cantidadesMinimas;
    for(unsigned int i = 0; i < parCodCant.size(); i++){
        Producto* productoActual = productos[parCodCant[i].getCodigo()];
        dProductos.push_back(productoActual->getDataProducto());
        CantMin* cantMin = new CantMin(parCodCant[i].getCantidad(), productoActual);
        cantidadesMinimas.push_back(cantMin);
    }
    Promocion* promo = new Promocion(dataCrearP->getInfoP(), cantidadesMinimas);
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

vector<DataProducto> ControladorCompra::obtenerListaProductos(){
    vector<DataProducto> dataProductos;
    for (std::map<int, Producto*>::iterator it = productos.begin(); it != productos.end(); ++it) {
        dataProductos.push_back(it->second->getDataProducto());
    }
    return dataProductos;
}

void ControladorCompra::agregarProductoCantidad(ParCodigoCantidad parCodCant){
    vector<ParCodigoCantidad> lista = dataInfoC->getProdCant();
    bool existe = false;
    for(unsigned int i = 0; i < lista.size(); i++){
        existe = existe || lista[i].getCodigo()==parCodCant.getCodigo();
    }
    if (!existe){
        lista.push_back(parCodCant);
        dataInfoC->setProdCant(lista);
    }
}

ParCompraProductos ControladorCompra::obtenerInfoCompra(){
    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();
    DTFecha fechaActual = IF->getFechaActual();
    float montoFinal = 0;
    vector<DataProducto> dProductos;
    vector<ParCodigoCantidad> productosCompra = dataInfoC->getProdCant();

    for(unsigned int i = 0; i < productosCompra.size(); i++){
        Producto* productoActual = productos[productosCompra[i].getCodigo()];
        if (productoActual!=NULL){
            dProductos.push_back(productoActual->getDataProducto());
            montoFinal += productoActual->getPrecio(); // Para cada producto que este dentro de dataInfoC sumo el precio al total
        }
    }

    for (std::map<string, Promocion*>::iterator it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion* promocionActual = it->second;
        vector<ParCodigoCantidad> productosPromocion = promocionActual->aplicaEnCompra(dataInfoC->getProdCant());
        
        if(!productosPromocion.empty()){

            float descuento = promocionActual->getDescuento();
            for(unsigned int i = 0; i < productosPromocion.size(); i++){
                ParCodigoCantidad parCodCantActual = productosPromocion[i];
                Producto* productoActual = productos[parCodCantActual.getCodigo()];
                montoFinal -= productoActual->getPrecio() * ((descuento/100)); // Para cada producto que aplica le resto al monto final el descuento aplicado a ese producto
            }

        }

    }

    dataInfoC->setMontoF(montoFinal);
    return ParCompraProductos(montoFinal, dProductos, fechaActual);
}

void ControladorCompra::confirmarCompra(){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* CU = f->getIUsuario();
    Cliente* cliente = CU->obtenerClienteCompra(dataInfoC->getCliente());
    Compra* compra = new Compra(cliente, dataInfoC->getMontoF());
    vector<ParCodigoCantidad> productosCompra = dataInfoC->getProdCant();

    for(unsigned int i = 0; i < productosCompra.size(); i++){
        Producto* productoActual = productos[productosCompra[i].getCodigo()];
        if (productoActual!=NULL){
            productoActual->crearEnvio(compra, productosCompra[i].getCantidad());
            productoActual->setStock(productoActual->getStock() - productosCompra[i].getCantidad());
        }
    }

    compras.push_back(compra);
    delete dataInfoC;
    dataInfoC = NULL;
}

void ControladorCompra::confirmarCompraCargaDeDatos(DataInfoCompra* dataInfoCompra){
    Fabrica* f = Fabrica::getInstance();
    IUsuario* CU = f->getIUsuario();
    Cliente* cliente = CU->obtenerClienteCompra(dataInfoCompra->getCliente());
    Compra* compra = new Compra(cliente, dataInfoCompra->getMontoF());
    vector<ParCodigoCantidad> productosCompra = dataInfoCompra->getProdCant();

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
    delete dataInfoCompra;
    dataInfoCompra = NULL;
}

Producto* ControladorCompra::obtenerProducto(int _codigoProducto){
    return productos[_codigoProducto];
}

vector<DataPromocion> ControladorCompra::obtenerInfoPromociones(DTFecha _fecha){
    vector<DataPromocion> dPromociones;
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
    info += "Productos: ";
    for(unsigned int i = 0 ; promocion->getCantidadesMinimas().size(); i++){
        info += "\n\t" + promocion->getCantidadesMinimas()[i]->getProducto()->getDataProducto().toString();
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


