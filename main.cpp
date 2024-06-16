#include <iostream>
#include <stdexcept>
#include <limits>
#include "include/CasosDeUso/CasosDeUso.h"
//poner opcion para cambiar fecha
 
using namespace std;

int main(){

    DataCliente d = DataCliente("nico", "hola", DTFecha(12,1,2002), DTDireccion("priamo", 1552), "montevideo");

    /*====== MENÚ =====*/
    int opcion;
    do{
        cout << "=================" << endl;
        cout << "Menu de opciones:" << endl;
        cout << "=================" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Alta de usuario" << endl;
        cout << "2. Listado de usuarios" << endl;
        cout << "3. Alta de producto" << endl;
        cout << "4. Consultar producto" << endl;
        cout << "5. Crear promocion" << endl;
        cout << "6. Consultar promocion" << endl;
        cout << "7. Realizar compra" << endl;
        cout << "8. Dejar comentario" << endl;
        cout << "9. Eliminar comentario" << endl;
        cout << "10. Enviar producto" << endl;
        cout << "11. Expediente de usuario" << endl;
        cout << "12. Suscribirse a notificaciones" << endl;
        cout << "13. Consulta de notificaciones" << endl;
        cout << "14. Eliminar suscripciones" << endl;
        //todos los casos de uso
        cout << "15. Cargar datos" << endl;
        cout << "Seleccione una opcion: ";

        try
        {
            cin >> opcion;
            cout << "\n";
            if (cin.fail()){
                throw invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
            }
            switch (opcion)
            {
                case 0:
                    /* Salir */
                    break;
                case 1:
                    AltaDeUsuario();
                    break;
                case 2:
                    ListadoDeUsuarios();
                    break;
                case 3:
                    AltaDeProducto();
                    break;
                case 4:
                    ConsultarProducto();
                    break;
                case 5:
                    CrearPromocion();
                    break;
                case 6:
                    ConsultarPromocion();
                    break;
                case 7:
                    RealizarCompra();
                    break;
                case 8:
                    DejarComentario();
                    break;
                case 9:
                    EliminarComentario();
                    break;
                case 10:
                    EnviarProducto();
                    break;
                case 11:
                    ExpedienteDeUsuario();
                    break;
                case 12:
                    SuscribirseANotificaciones();
                    break;
                case 13:
                    ConsultaDeNotificaciones();
                    break;
                case 14:
                    EliminarSuscripciones();
                    break;

                case 15:
                    CargarDatos();
                    break;
                default:
                    cout << "Numero fuera de rango. Por favor, intente de nuevo." << endl;
                    break;
            }
            if (opcion!=0){
                cout << "\nPresione enter para continuar.";
                string dummy;
                cin.ignore();
                getline(cin, dummy);
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
    //ELIMINAR MEMORIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    return 0;
}