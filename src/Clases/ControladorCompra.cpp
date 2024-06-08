#include "../../include/Clases/ControladorCompra.h"

ControladorCompra* ControladorCompra::instancia = nullptr;

Fabrica* f = Fabrica::getInstance();
IUsuario* CU = f->getIUsuario();

ControladorCompra* ControladorCompra::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorCompra();
    }
    return instancia;
}

ControladorCompra::~ControladorCompra(){
    // oof
}

void ControladorCompra::crearPromocion(Vendedor* v, DataCrearPromocion* dataCrearP){}

set<DataProducto> ControladorCompra::obtenerListaProductos(){
    set<DataProducto> dataProductos;
    for (const Producto* producto : productos) {
        //if (producto.getStock()>0)
            //dataProductos.insert(producto.getDataProducto());
    }
    return dataProductos;
}

void ControladorCompra::agregarProducto(ParCodigoCantidad parCodCant){
    set<ParCodigoCantidad> lista = dataInfoC->getProdCant();
    bool existe = false;
    for (ParCodigoCantidad item : lista) {
        existe = existe || item.getCodigo() == parCodCant.getCodigo();
    }
    if (!existe){
        lista.insert(parCodCant);
        dataInfoC->setProdCant(lista);
    }
}

// Sirve para obtenerInfoCompra
DataProducto obtenerDataProducto(set<Producto*> &productos, string codigo){
    DataProducto res;
    for (auto* producto : productos) {
        // if (producto->getCodigo() == codigo) {
        //     res = producto->getDataProducto();;
        // }
    }
    return res;
}

ParCompraProductos ControladorCompra::obtenerInfoCompra(){
    set<ParCodigoCantidad> lista = dataInfoC->getProdCant();
    set<DataProducto> productosCompra;
    for (ParCodigoCantidad item : lista) {
        productosCompra.insert(obtenerDataProducto(productos, item.getCodigo()));
    }
    // Calcular Monto Final
    return ParCompraProductos(DTFecha(8,06,2024), 0, productosCompra); // Aca iria la fecha actual, como?
}

set<string> ControladorCompra::obtenerListaNicknamesClientes(){
    CU->obtenerListaNicknamesClientes();
}

void ControladorCompra::seleccionarCliente(string nickname){
    dataInfoC = new DataInfoCompra(nickname);
}

void ControladorCompra::confirmarCompra(){
    // oof
}

