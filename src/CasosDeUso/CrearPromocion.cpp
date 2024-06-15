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
        cout << nicknamesVendedores[i] << endl;
    }
    cout << "Seleccione un vendedor:" << endl;
    string seleccion;
    cin >> seleccion;
    interfazUsuario -> seleccionarVendedor(seleccion); //Queda guardado en dataCrearP


    //vector<ParCodigoNombre> productos = interfazUsuario -> obtenerListaProductosVendedor(); //El include esta en el IUsuario.h
    /*
    for(int i = 0; i < productos.size();i++)
        cout << productos.getNombre() << endl;
    */
    cout << "Seleccione un producto:" << endl;
    string id;
    cin >> id;
    cout << "Ingrese la cantidad minima:" << endl;
    int cant;
    cin >> cant;
    interfazUsuario -> agregarProductoCantidad(ParCodigoCantidad(id,cant));


    interfazUsuario -> confirmarAltaPromocion();

};