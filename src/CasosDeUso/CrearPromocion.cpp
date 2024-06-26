#include "../../include/CasosDeUso/CasosDeUso.h"

void CrearPromocion()
{

    Fabrica* fabrica = Fabrica::getInstance();
    IUsuario* IU = fabrica -> getIUsuario();

    string nombre;
    cout << "Ingrese el nombre de la promocion: ";
    cin.ignore();
    getline(cin, nombre);

    string descripcion;
    cout << "\nIngrese la descripcion de la promocion: ";
    cin.ignore();
    getline(cin, descripcion);

    float descuento;
    cout << "\nIngrese el descuento de la promocion: ";
    cin >> descuento;

    int dia, mes, ano;
    cout << "\nIngrese una fecha de vencimiento (dia mes año): ";
    cin >> dia;
    cin >> mes;
    cin >> ano;

    DTPromocion dataPromocion = DTPromocion(nombre, descripcion, DTFecha(dia,mes,ano), descuento);
    IU->ingresarDatosPromocion(dataPromocion);

    vector<string> listaNicknames = IU->obtenerListaNicknameVendedores();

    cout << "\nVendedores:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\tNickname: " << listaNicknames[i] << endl;
    }

    cout << "\nIngrese un nickname: ";
    string seleccion;
    cin >> seleccion;

    IU->seleccionarVendedor(seleccion); 

    vector<DTCodigoNombre> listaProductos = IU->obtenerListaProductosVendedor(); // Error
    cout << "\nProductos de "<< seleccion << ": ";
    for (long unsigned int i = 0; i < listaProductos.size(); i++){
        cout << "\n\tNombre: " << listaProductos[i].getNombre() << " | Codigo: " << listaProductos[i].getCodigo();
    }

    cout << "\n\nIngrese el codigo del producto: ";
    int id; 
    cin >> id;
    cout << "\nIngrese la cantidad deseada: ";
    int cant; 
    cin >> cant;

    IU->agregarProductoCantidad(DTCodigoCantidad(id,cant));


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
                cout << "\n\tNombre: " << listaProductos[i].getNombre() << " | Codigo: " << listaProductos[i].getCodigo();
            }

            cout << "\n\nIngrese el codigo del producto: ";
            cin >> id;
            cout << "\nIngrese la cantidad deseada: ";
            cin >> cant;
            IU->agregarProductoCantidad(DTCodigoCantidad(id,cant));
            cout << "\nProducto ingresado con exito." << endl;
            
        }else{
            continuar = false;
        }
    }

    IU -> confirmarAltaPromocion();
    cout << "\nPromocion ingresada con exito." << endl;
};