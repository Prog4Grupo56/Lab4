#include "../../include/CasosDeUso/CasosDeUso.h"

using namespace std;

void SuscribirseANotificaciones(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    vector<DataCliente> listaClientes = IU->obtenerListadoClientes();
    cout << "Clientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << "\t" << listaClientes[i].toString() << endl;
    }

    string nickname;
    cout << "\nIngrese su nickname: ";
    cin >> nickname;

    vector<DataVendedor> lista = IU->obtenerListaVendedoresNoSuscritos(nickname);

    vector<DataVendedor> listaVendedoresSeleccionados;

    int opcion;
    do{
        cout << "\nDesea agregar un vendedor? " << endl;
        cout << "\t" << "0. Terminar." << endl;
        cout << "\t" << "1. Agregar." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (opcion == 1){
            cout << "\nVendedores: " << endl;
            for (long unsigned int i = 0; i < lista.size(); i++){ //imprimo 
                cout << "\t" << lista[i].toString() << endl;
            }
            cout << "\nEscriba el nombre del vendedor: ";
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

    cout << "\n" << listaVendedoresSeleccionados.size() << "\n";
    IU->vendedoresASuscribirse(listaVendedoresSeleccionados);

    cout << "\nSe suscribio existosamente."<< endl;
}