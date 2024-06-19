#include "../../include/CasosDeUso/CasosDeUso.h"

void CambiarFecha(){

    Fabrica* f = Fabrica::getInstance();
    IFecha* IF = f->getIFecha();

    int dia,mes,ano;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "\nIngrese el mes: ";
    cin >> mes;
    cout << "\nIngrese el año: ";
    cin >> ano;
    IF->setFechaActual(DTFecha(dia,mes,ano));

}