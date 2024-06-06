#include <iostream>
#include <stdexcept>
#include <limits>
#include "include/Comentario.h"
#include "include/Usuario.h"
#include "include/Cliente.h"

using namespace std;

int main(){
    int opcion;

    //PRUEBASSSSSSSSS
    Cliente* cliente1 = new Cliente("Nico", "1234", NULL, NULL, "Montevideo");
    Cliente* cliente2 = new Cliente("Nico", "1234", NULL, NULL, "Montevideo");

    Comentario* comentario1 = new Comentario(NULL, "soy el primer comentario de Nico", 1, NULL, cliente1);
    Comentario* comentario2 = new Comentario(NULL, "soy la primer respuesta del primer comentario de Nico", 2, comentario1, cliente2);
    Comentario* comentario3 = new Comentario(NULL, "soy el segundo comentario de Nico", 1, comentario2, cliente1);
    Comentario* comentario4 = new Comentario(NULL, "soy la segunda respuesta del primer comentario de Nico", 1, comentario1, cliente1);

    
    comentario1->setRespuesta(comentario2);
    comentario1->setRespuesta(comentario4);
    comentario2->setRespuesta(comentario3);

    cliente1->setComentario(comentario1);
    cliente2->setComentario(comentario2);
    cliente1->setComentario(comentario3);
    cliente1->setComentario(comentario4);

    comentario1->desvincularPadre();
    comentario1->eliminarComentario();
    
    /*====== MENÚ =====*/
    do{
        cout << "=================" << endl;
        cout << "Menu de opciones:" << endl;
        cout << "=================" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Crear Vendedor" << endl;
        cout << "3. Caso de uso 3" << endl;
        //todos los casos de uso
        cout << "Seleccione una opcion: ";

        try
        {
            cin >> opcion;
            if (cin.fail()){
                throw invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
            }
            switch (opcion)
            {
                case 0:
                    /* Salir */
                    break;
                case 1:
                    /* Caso de uso 1 */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;
        
                default:
                    cout << "Numero fuera de rango. Por favor, intente de nuevo." << endl;
                    break;
            }
        }
        catch(const invalid_argument& e)
        {
            cerr << "Error: " << e.what() << '\n';
            cin.clear(); //reestablece a funcionamiento normal la entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //descarta lo que haya quedado en el buffer de entrada
            opcion = -1; // si no hago esto se setea a 0 y termina el loop, lo vi en el debugger.
        }      
    } while (opcion != 0);

    return 0;

}
