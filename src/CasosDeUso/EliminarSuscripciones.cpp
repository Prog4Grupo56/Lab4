#include "../../include/CasosDeUso/CasosDeUso.h"


void EliminarSuscripciones(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    cout << "Ingrese su nickname: ";
    string nickname;
    cin >> nickname;
    set<DataVendedor> lista = IU->obtenerListaVendedoresSuscritos(nickname);

    //imprimir vendedores

    int opcion;
    set<DataVendedor> listaVendedoresSeleccionados;

    do{
         cout << "Elija una opcion: " << endl;
         cout << "0. Terminar.";
         cout << "1. Agregar vendedor." << endl;
         cin >> opcion;
           if (opcion == 1){
                //imprimir vendedores
                cout << "========";
                cout << "Escriba el nombre del vendedor:";
                string vendedor;
                cin >> vendedor;
                //find vendedor en lista
                //insert vendedor en listaVendedoresSeleccionados
           };
    } while (opcion != 0);

        IU->seleccionarVendedoresAEliminarSuscripciones(listaVendedoresSeleccionados); // vaciar dataelimsus en controladorUsuario
        IU->eliminarSuscripciones();
}