#include  "../../include/CasosDeUso/CasosDeUso.h"

#include  "../../include/Clases/ICompra.h"
#include "../../include/Clases/Fabrica.h"

void RealizarCompra()
{

Fabrica * fabrica = Fabrica::getInstance();
ICompra * interfazCompra= fabrica -> getICompra();
IFecha * IF = fabrica->getIFecha();

vector<string> listaNicknames = interfazCompra->obtenerListaNicknamesClientes();

cout << "Clientes:\n";
for(unsigned int i = 0; i < listaNicknames.size(); i++)
    cout << "\tNickname: " << listaNicknames[i] << endl;
cout << "Ingrese un nickname: ";
string seleccion;
cin >> seleccion;
interfazCompra -> seleccionarCliente(seleccion); //Queda un dataInfoCompra guardado con el nick seleccionado



vector<DTProducto> listaProductos = interfazCompra -> obtenerListaProductos();

bool agregado=false;
int id; int cant; //Id y cantidad del producto
cout << "\nProductos:";
        for(unsigned int i = 0; i < listaProductos.size(); i++)//Imprimir productos
        {
            cout << "\n\t" << listaProductos[i].toString();
        };

        cout << "\n\nIngrese el codigo del producto: ";
        cin >> id;
        cout << "\nIngrese la cantidad deseada: ";
        cin >> cant;
        agregado = interfazCompra -> agregarProductoCantidad(DTCodigoCantidad(id,cant));
        if (agregado){
            cout << "\nProducto ingresado con exito." << endl;
        }else{
            cout << "\nYa ingresado / No hay stock" << endl;
        }

bool continuar = true;
int opcion = 1; //Para el menu
while(continuar)
{
    cout << "\nDesea agregar un producto?";
    cout << "\n\t0. Terminar." << endl;
    cout << "\t1. Agregar nuevo producto." << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    if(opcion == 1)
    {
        cout << "\nProductos:";
        for(unsigned int i = 0; i < listaProductos.size(); i++)//Imprimir productos
        {
            cout << "\n\t" << listaProductos[i].toString();
        };

        cout << "\n\nIngrese el codigo del producto: ";
        cin >> id;
        cout << "\nIngrese la cantidad deseada: ";
        cin >> cant;
        agregado = interfazCompra -> agregarProductoCantidad(DTCodigoCantidad(id,cant));
        if (agregado){
            cout << "\nProducto ingresado con exito." << endl;
        }else{
            cout << "\nYa ingresado / No hay stock" << endl;
        }
    }
    else
    {
        continuar = false;
    }
};



DTCompraProductos infoCompra = interfazCompra -> obtenerInfoCompra(); //Almacena los productos, fecha actual y monto final, incluyendo descuentos

vector<DTProducto> dProductos = infoCompra.getProductos();
cout << "\nFecha: " + infoCompra.getFecha().toString();
cout << "\nMonto final: " + to_string(infoCompra.getMontoFinal());
cout << "\nProductos:";
for (unsigned int i = 0; i<dProductos.size(); i++){
    cout << "\n\t" << dProductos[i].toString();
}
cout << "\n\nDesea confirmar la compra?";
cout << "\n\t0. No." << endl;
cout << "\t1. Si." << endl;
cout << "Seleccione una opcion: ";
int confirmarCompra;
cin >> confirmarCompra;
if (confirmarCompra==1){
    interfazCompra->confirmarCompra(IF->getFechaActual());
}else{
    interfazCompra->cancelarCompra();
}

};