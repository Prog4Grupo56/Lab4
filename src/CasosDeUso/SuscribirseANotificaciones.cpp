#include "../../include/CasosDeUso/CasosDeUso.h"

using namespace std;

void SuscribirseANotificaciones(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    string nickname;
    cout << "Ingrese su nickname: ";
    cin >> nickname;

    vector<DataVendedor> lista = IU->obtenerListaVendedoresNoSuscritos(nickname);

    vector<DataVendedor> listaVendedoresSeleccionados;

    cout << "========" << endl;
    int opcion;
    do{
        cout << "Elija una opcion: " << endl;
        cout << "0. Terminar.";
        cout << "1. Agregar vendedor." << endl;
        cin >> opcion;
        cout << "========" << endl;
        if (opcion == 1){
            for (long unsigned int i = 0; i < lista.size(); i++){ //imprimo 
                cout << lista[i].toString() << endl;
            }
            cout << "Escriba el nombre del vendedor: ";
            string vendedor;
            cin >> vendedor;
            
            for (long unsigned int i = 0; i < lista.size(); i++){ 
                if (lista[i].getNickname() == vendedor){
                    listaVendedoresSeleccionados.push_back(lista[i]);
                    break;
                }
            }
        }
        cout << "========" << endl;
    } while (opcion != 0);

    IU->vendedoresASuscribirse(listaVendedoresSeleccionados);

    cout << "Se suscribió existosamente."<< endl;
}