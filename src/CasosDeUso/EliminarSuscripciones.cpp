#include "../../include/CasosDeUso/CasosDeUso.h"


void EliminarSuscripciones(){
     Fabrica* F = Fabrica::getInstance();
     IUsuario* IU = F->getIUsuario();

     vector<DataCliente> listaClientes = IU->obtenerListadoClientes();
    cout << "Clientes: " << endl;
    for (long unsigned int i = 0; i < listaClientes.size(); i++){
        cout << "\t" << listaClientes[i].toString() << endl;
    }

     cout << "\nIngrese su nickname: ";
     string nickname;
     cin >> nickname;

     vector<DataVendedor> lista = IU->obtenerListaVendedoresSuscritos(nickname);

     int opcion;
     vector<DataVendedor> listaVendedoresSeleccionados;

     do{
          cout << "\nDesea eliminar un vendedor?" << endl;
          cout << "0. Terminar." << endl;
          cout << "1. Agregar." << endl;
          cout << "Ingrese una opcion: ";
          cin >> opcion;
          
          if (opcion == 1){
               cout << "\nVendedores:";
               for (long unsigned int i = 0; i < lista.size(); i++){ //imprimo 
                    cout << "\n\t" << lista[i].toString();
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

     IU->seleccionarVendedoresAEliminarSuscripciones(listaVendedoresSeleccionados); // vaciar dataelimsus en controladorUsuario
     IU->eliminarSuscripciones();

     cout << "\nSuscripciones eliminadas exitosamente." << endl;
}