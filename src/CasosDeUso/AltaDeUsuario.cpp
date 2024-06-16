#include "../../include/CasosDeUso/CasosDeUso.h"

void AltaCliente(){

    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
   
    //PEDIR DATOS
    string nickname;
    string contrasena;
    int dia, mes, ano;
    int numeroDePuerta;
    string ciudad;
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
    DataCliente dataCliente = DataCliente(nickname, contrasena, DTFecha(dia,mes,ano), DTDireccion(calle, numeroDePuerta), ciudad);

    if (IU->ingresarCliente(dataCliente)){
        cout << "Se ingresó correctamente el usuario." << endl;
    }
    else{
        cout << "El nickname esta ocupado. No se ingreso el usuario." << endl;
    }
}

void AltaVendedor(){

    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
   
    //PEDIR DATOS
    string nickname;
    string contrasena;
    int dia, mes, ano;
    string RUT;

    cout << "Ingrese un nickname: ";
    cin >> nickname;
    cout << "Ingrese una contraseña: ";
    cin >> contrasena;
    cout << "Ingrese una fecha (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    cout << "Ingrese un RUT: ";
    cin >> RUT;

    DataVendedor dataVendedor = DataVendedor(nickname, contrasena, DTFecha(dia,mes,ano), RUT);

    if (IU->ingresarVendedor(dataVendedor)){
        cout << "Se ingresó correctamente el usuario.";
    }
    else{
        cout << "El nickname esta ocupado. No se ingreso el usuario. ";
    }
}

void AltaDeUsuario(){
    int opcion;
    cout << "=================" << endl;
    cout << "Alta de usuario:" << endl;
    cout << "=================" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Alta de cliente" << endl;
    cout << "2. Alta de vendedor" << endl;
    cout << "Seleccione una opcion: ";

    //try and catch
    cin >> opcion;
    cout << "\n";
    
    switch (opcion)
    {
        case 0:
            break;
        case 1:
            AltaCliente();
            break;
        case 2:
            AltaVendedor();
            break;
        default:
            cout << "Numero fuera de rango. Por favor, intente de nuevo." << endl;
            break;
    }
}
