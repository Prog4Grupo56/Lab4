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

    int opcion;
    do{
        cout << "¿Desea agregar un vendedor? " << endl;
        cout << "\t" << "0. No." << endl;
        cout << "\t" << "1. Si." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (opcion == 1){
            cout << "Lista de vendedores: " << endl;
            for (long unsigned int i = 0; i < lista.size(); i++){ //imprimo 
                cout << "\t" << lista[i].toString() << endl;
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
    } while (opcion != 0);

    IU->vendedoresASuscribirse(listaVendedoresSeleccionados);

    cout << "Se suscribió existosamente."<< endl;
}