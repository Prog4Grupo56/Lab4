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
    bool contrasenaOk = false;
    while (!contrasenaOk){
        cout << "\nIngrese una contraseña (al menos seis caracteres): ";
        cin >> contrasena;
        if (contrasena.length() < 6){
            cout << "\nContraseña invalida." << endl;
        }
        else{
            contrasenaOk = true;
        }
    }
    cout << "\nIngrese una fecha (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    cout << "\nIngrese una direccion (calle numeroDePuerta): ";
    cin >> calle;
    cin >> numeroDePuerta;
    cout << "\nIngrese una ciudad: ";
    cin >> ciudad;
    DTCliente dataCliente = DTCliente(nickname, contrasena, DTFecha(dia,mes,ano), DTDireccion(calle, numeroDePuerta), ciudad);

    if (IU->ingresarCliente(dataCliente)){
        cout << "\nSe ingresó correctamente el usuario." << endl;
    }
    else{
        cout << "\nEl nickname esta ocupado. No se ingreso el usuario." << endl;
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
    bool contrasenaOk = false;
    while (!contrasenaOk){
        cout << "\nIngrese una contraseña (al menos seis caracteres): ";
        cin >> contrasena;
        if (contrasena.length() < 6){
            cout << "\nContraseña invalida." << endl;
        }
        else{
            contrasenaOk = true;
        }
    }
    cout << "\nIngrese una fecha (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    bool RUTok = false;
    while (!RUTok){
        cout << "\nIngrese un RUT (doce caracteres): ";
        cin >> RUT;
        if (RUT.length() != 12){
            cout << "\nRUT invalido." << endl;
        }
        else{
            RUTok = true;
        }
    }

    DTVendedor dataVendedor = DTVendedor(nickname, contrasena, DTFecha(dia,mes,ano), RUT);

    if (IU->ingresarVendedor(dataVendedor)){
        cout << "\nSe ingresó correctamente el usuario.\n";
    }
    else{
        cout << "\nEl nickname esta ocupado. No se ingreso el usuario.\n";
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
