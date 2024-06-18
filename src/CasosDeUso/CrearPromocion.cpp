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
    cout << "Ingrese el descuento de la promocion: ";
    cin >> descuento;

    int dia, mes, ano;
    cout << "Ingrese una fecha de vencimiento (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;

    DataPromocion dataPromocion = DataPromocion(nombre, descripcion, DTFecha(dia,mes,ano), descuento);
    IU->ingresarDatosPromocion(dataPromocion);

    vector<string> listaNicknames = IU->obtenerListaNicknameVendedores();

    cout << "Vendedores:\n" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\t" << listaNicknames[i] << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno:";
    string seleccion;
    cin >> seleccion;
    cout << "========";

    IU->seleccionarVendedor(seleccion); 

    vector<ParCodigoNombre> listaProductos = IU->obtenerListaProductosVendedor(); // Error
    cout << "Productos de "<< seleccion << ": " << endl;
    for (long unsigned int i = 0; i < listaProductos.size(); i++){
        cout << "\t" << listaProductos[i].getNombre() << " - " << listaProductos[i].getCodigo() << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno (codigo, cantidad):";
    int id; int cant; 
    cin >> id;
    cin >> cant;
    cout << "========";

    IU->agregarProductoCantidad(ParCodigoCantidad(id,cant));


    bool continuar = true;
    int opcion = 1; //Para el menu
    while(continuar)
    {
        cout << "\nDesea agregar otro producto?";
        cout << "\n\t0. Terminar." << endl;
        cout << "\t1. Agregar nuevo producto." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if(opcion == 1){

            cout << "\nAgregar mas productos: " << endl;
            for (long unsigned int i = 0; i < listaProductos.size(); i++){
                cout << "\n\t" << listaProductos[i].getNombre() << " - " << listaProductos[i].getCodigo() << endl;
            }

            cout << "\n\nIngrese el codigo del producto: ";
            cin >> id;
            cout << "\nIngrese la cantidad deseada: ";
            cin >> cant;
            IU->agregarProductoCantidad(ParCodigoCantidad(id,cant));
            cout << "\nProducto ingresado con exito." << endl;
            
        }else{
            continuar = false;
        }
    }

    IU -> confirmarAltaPromocion();
    cout << "Promocion ingresado con exito." << endl;
};