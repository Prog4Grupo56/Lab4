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
    cout << "\n\nDesea obtener mas informacion sobre una promocion?";
    cout << "\n\t0. Salir";
    cout << "\n\t1. Obtener mas informacion";
    cout << "\nIngrese una opcion: ";
    int opcion;
    cin >> opcion;
    if (opcion==1){
        string nombre;
        cout<< "\nIngrese el nombre de la promocion: ";
        cin.ignore();
        getline(cin, nombre);
        string info = IC->obtenerInfoPromocion(nombre);
        cout << "\n" + info + "\n";
    }

}