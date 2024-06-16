#include "../../include/Clases/Compra.h"

Compra::Compra(){

}

Compra::Compra(Cliente* _clienteDeCompra, int _montoFinal){
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

void Compra::setMontoFinal(int _montoFinal){
    montoFinal = _montoFinal;
}

void Compra::setCliente(Cliente* _cliente){
    clienteDeCompra = _cliente;
}

string Compra::getNickCliente(){
    return clienteDeCompra->getNickname();
}