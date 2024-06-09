#include "../../include/CasosDeUso/CasosDeUso.h"

bool AltaCliente(){
    string nickname;
    string contrasena;
    string ciudad;
    //int RUT;
    int dia, mes, ano;
    int numeroDePuerta;
    string calle;
    cout << "Ingrese un nickname: ";
    cin >> nickname;
    cout << "Ingrese una contraseña: ";
    cin >> contrasena;
    cout << "Ingrese una fecha (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    cout << "Ingrese una direccion (calle numeroDePuerta): ";
    cin >> calle;
    cin >> numeroDePuerta;
    cout << "Ingrese una ciudad: ";
    cin >> ciudad;
    DataCliente dataCliente = DataCliente(nickname,contrasena, DTFecha(dia,mes,ano), DTDireccion(calle, numeroDePuerta), ciudad);
    //ControladorUsuario.ingresarCliente(dataCliente);
    return true;
}
 
void AltaDeUsuario(){
    int tipo;
    cout << "=================" << endl;
    cout << "Alta de usuario:" << endl;
    cout << "=================" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Alta de cliente" << endl;
    cout << "2. Alta de vendedor" << endl;
    cout << "Seleccione una opcion: ";
    
    try
    {
        cin >> tipo;
        cout << "\n";
        if (cin.fail()){
            throw invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
        }
        switch (tipo)
        {
            case 0:
                break;
            case 1:
                AltaCliente();
                break;
            case 2:
                cout << "Alta de vendedor\n\n";
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
            tipo = -1; // si no hago esto se setea a 0 y termina el loop, lo vi en el debugger.
        }      
}

void ListadoDeUsuarios(){}

void AltaDeProducto(){}

void ConsultarProducto(){}

void CrearPromocion(){}

void ConsultarPromocion(){}

void RealizarCompra(){}

void DejarComentario(){}

void EliminarComentario(){}

void EnviarProducto(){}

void ExpedienteDeUsuario(){}

void SuscribirseANotificaciones(){}

void ConsultaDeNotificaciones(){}

void EliminarSuscripciones(){}