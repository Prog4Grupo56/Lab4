#include "../../include/CasosDeUso/CasosDeUso.h"

#include "../../include/Clases/IUsuario.h"
#include "../../include/Clases/Fabrica.h"


void CrearPromocion()
{

    Fabrica* fabrica = Fabrica::getInstance();
    IUsuario* interfazUsuario = fabrica -> getIUsuario();

    //interfazUsuario -> ingresarDatosPromocion(data)
    //Falta?


    vector<string> nicknamesVendedores = interfazUsuario -> obtenerListaNicknameVendedores();


    //====Imprimir nicknames====
    for(int i = 0; i < nicknamesVendedores.size();i++)
    {
        cout << nicknamesVendedores[i] << "\n";
    }
    cout << "Seleccione un vendedor: \n";
    string seleccion;
    cin >> seleccion;
    interfazUsuario -> seleccionarVendedor(seleccion); //Queda guardado en dataCrearP


    //vector<ParCodigoNombre> productos = interfazUsuario -> obtenerListaProductosVendedor(); //El include esta en el IUsuario.h
    /*
    for(int i = 0; i < productos.size();i++)
        cout << productos.getNombre() << "\n";
    */
    cout << "Seleccione un producto:\n";
    string id;
    cin >> id;
    cout << "Ingrese la cantidad minima:\n";
    int cant;
    cin >> cant;
    interfazUsuario -> agregarProductoCantidad(ParCodigoCantidad(id,cant));


    interfazUsuario -> confirmarAltaPromocion();

};