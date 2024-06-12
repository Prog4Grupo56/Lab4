#include "../../include/CasosDeUso/CasosDeUso.h"


void EliminarSuscripciones(){
     Fabrica* F = Fabrica::getInstance();
     IUsuario* IU = F->getIUsuario();

     cout << "Ingrese su nickname: ";
     string nickname;
     cin >> nickname;
     cout << "========";
     vector<DataVendedor> lista = IU->obtenerListaVendedoresSuscritos(nickname);
     vector<DataVendedor> aux = lista;

     int opcion;
     vector<DataVendedor> listaVendedoresSeleccionados;

     do{
          cout << "Elija una opcion: " << endl;
          cout << "0. Terminar.";
          cout << "1. Agregar vendedor." << endl;
          cin >> opcion;
          cout << "========";
          if (opcion == 1){
               for (long unsigned int i = 0; i < lista.size(); i++){ //imprimo 
                    cout << lista[i].toString() << endl;
               }
               cout << "Escriba el nombre del vendedor:";
               string vendedor;
               cin >> vendedor;
               for (char &c : vendedor) {
                    c = tolower(c);
               }
               
               for (long unsigned int i = 0; i < lista.size(); i++){ 
                    for (char &c : aux[i].getNickname()) {
                         c = tolower(c);
                    }
                    if (aux[i].getNickname() == vendedor){
                         listaVendedoresSeleccionados.push_back(lista[i]);
                         break;
                    }
               }
          }
          cout << "========";
     } while (opcion != 0);

     IU->seleccionarVendedoresAEliminarSuscripciones(listaVendedoresSeleccionados); // vaciar dataelimsus en controladorUsuario
     IU->eliminarSuscripciones();

     cout << "Suscripciones eliminadas correctamente.";
}