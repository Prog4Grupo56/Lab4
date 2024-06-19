#include "../../include/CasosDeUso/CasosDeUso.h"

void LimpiarMemoria(){

    Fabrica* F = Fabrica::getInstance();

    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();
    IFecha* IF = F->getIFecha();

    IU->limpiarCU();
    IC->limpiarCC();
    IF->limpiarCF();

    delete F;
}