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
    cout << "Seleccione un vendedor: \n";
    string seleccion;
    cin >> seleccion;
    interfazUsuario -> seleccionarVendedor(seleccion); //Queda guardado en dataCrearP


    //set<ParCodigoNombre> productos = IUsuario -> obtenerListaProductosVendedor(); //El include esta en el IUsuario.h
    //====Imprimir productos===
    cout << "Seleccione un producto:\n";
    string id;
    cin >> id;
    cout << "Ingrese la cantidad minima:\n";
    int cant;
    cin >> cant;
    interfazUsuario -> agregarProductoCantidad(ParCodigoCantidad(id,cant));


    interfazUsuario -> confirmarAltaPromocion();

};