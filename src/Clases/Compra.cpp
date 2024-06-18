#include "../../include/Clases/Compra.h"

Compra::Compra(){

}

Compra::Compra(Cliente* _clienteDeCompra, float _montoFinal){
    clienteDeCompra = _clienteDeCompra;
    montoFinal = _montoFinal;
}

Compra::~Compra(){

}
        
float Compra::getMontoFinal(){
    return montoFinal;
}

DTFecha Compra::getFecha(){
    return fecha;
}


Cliente* Compra::getCliente(){
    return clienteDeCompra;
}

void Compra::setFecha(DTFecha f){
    fecha = f;
}

void Compra::setMontoFinal(float _montoFinal){
    montoFinal = _montoFinal;
}

void Compra::setCliente(Cliente* _cliente){
    clienteDeCompra = _cliente;
}

string Compra::getNickCliente(){
    return clienteDeCompra->getNickname();
}

void Compra::agregarCompraProducto(CompraProducto* compraProducto){
    compraProductos.push_back(compraProducto);
}

vector<CompraProducto*> Compra::obtenerCompraProductos(){
    return compraProductos;
}