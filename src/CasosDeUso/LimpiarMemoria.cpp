#include "../../include/CasosDeUso/CasosDeUso.h"

void LimpiarMemoria(){

    Fabrica* F = Fabrica::getInstance();

    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();
    IFecha* IF = F->getIFecha();

    delete IU;
    delete IC;
    delete IF;

    //delete F;
}