#include "../../include/CasosDeUso/CasosDeUso.h"

void LimpiarMemoria(){

    Fabrica* F = Fabrica::getInstance();

    IUsuario* IU = F->getIUsuario();
    //ICompra* IC = F->limpiarCC();
    //IFecha* IF = F->getIFecha();
    IU->limpiarCU();
    //delete IC;
    //delete IF;

    //delete F;

}