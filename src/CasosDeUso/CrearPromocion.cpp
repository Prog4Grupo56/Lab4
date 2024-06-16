#include "../../include/CasosDeUso/CasosDeUso.h"

#include "../../include/Clases/IUsuario.h"
#include "../../include/Clases/Fabrica.h"


/*
El caso de uso comienza cuando se desea dar de alta una promoción en el
sistema. Para ello, el Administrador ingresa los datos de la promoción, luego,
el Sistema lista el nickname de todos vendedores y el Administrador
selecciona uno, que será quien ofrezca la promoción. Luego, el Sistema lista
el código y el nombre de todos los productos disponibles asociados al
vendedor seleccionado, para que el Administrador seleccione los productos
que compondrán la promoción. Es importante destacar que el sistema no
permite que un producto esté incluido en dos promociones vigentes
simultáneamente. Para cada producto seleccionado, el usuario especifica la
cantidad mínima que debe ser adquirida para aplicar la promoción. Una vez
que el Administrador termina, el Sistema da de alta la nueva promoción con
los datos ingresados.
*/

void CrearPromocion()
{

    Fabrica* fabrica = Fabrica::getInstance();
    IUsuario* IU = fabrica -> getIUsuario();

    string nombre;
    cout << "Ingrese el nombre de la promocion: ";
    cin >> nombre;

    string descripcion;
    cout << "Ingrese la descripcion de la promocion: ";
    cin >> descripcion;

    float descuento;
    cout << "Ingrese el precio de la promocion: ";
    cin >> descuento;

    int dia, mes, ano;
    cout << "Ingrese una fecha de vencimiento (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;

    DataPromocion dataPromocion = DataPromocion(nombre, descripcion, DTFecha(dia,mes,ano), descuento);
    IU -> ingresarDatosPromocion(dataPromocion);

    vector<string> listaNicknames = IU->obtenerListaNicknameVendedores();

    cout << "Vendedores:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\t" << listaNicknames[i] << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno:";
    string seleccion;
    cin >> seleccion;
    IU -> seleccionarVendedor(seleccion); //Queda guardado en dataCrearP


    //vector<ParCodigoNombre> productos = IU -> obtenerListaProductosVendedor(); //El include esta en el IUsuario.h
    /*
    for(int i = 0; i < productos.size();i++)
        cout << productos.getNombre() << endl;
    */
    cout << "Seleccione un producto:" << endl;
    int id;
    cin >> id;
    cout << "Ingrese la cantidad minima:" << endl;
    int cant;
    cin >> cant;
    IU -> agregarProductoCantidad(ParCodigoCantidad(id,cant));


    IU -> confirmarAltaPromocion();

};