#include "../../include/CasosDeUso/CasosDeUso.h"

void ConsultarPromocion(){

    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();
    IFecha* IF = F->getIFecha();
    vector<DataPromocion> promociones = IC->obtenerInfoPromociones(IF->getFechaActual());
    cout << "Promociones:";
    for(unsigned int i = 0; i<promociones.size(); i++){
        cout << "\n\t" << promociones[i].toString();
    }
    cout << "\n\n=================" << endl;
    cout << "Menu de opciones:" << endl;
    cout << "=================" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Ingresar nombre de promocion" << endl;
    int opcion;
    cin >> opcion;
    if (opcion==1){
        string nombre;
        cout<< "Ingrese el nombre de la promocion: ";
        cin.ignore();
        getline(cin, nombre);
        string info = IC->obtenerInfoPromocion(nombre);
        cout << "\n" + info;
    }

}