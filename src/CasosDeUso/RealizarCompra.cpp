#include  "../../include/CasosDeUso/CasosDeUso.h"

#include  "../../include/Clases/ICompra.h"
#include "../../include/Clases/Fabrica.h"

void RealizarCompra()
{

Fabrica * fabrica = Fabrica::getInstance();
ICompra * interfazCompra= fabrica -> getICompra();

vector<string> listaNicknames = interfazCompra->obtenerListaNicknamesClientes();

cout << "Clientes:\n";
for(unsigned int i = 0; i < listaNicknames.size(); i++)
    cout << "\t" << listaNicknames[i] << endl;
cout << "Seleccione un cliente: ";
string seleccion;
cin >> seleccion;
interfazCompra -> seleccionarCliente(seleccion); //Queda un dataInfoCompra guardado con el nick seleccionado



vector<DataProducto> listaProductos = interfazCompra -> obtenerListaProductos();
bool continuar = true;
int opcion = 1; //Para el menu
int id; int cant; //Id y cantidad del producto
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
        interfazCompra -> agregarProductoCantidad(ParCodigoCantidad(id,cant));
        cout << "\nProducto ingresado con exito." << endl;
    }
    else
    {
        continuar = false;
    }
};



ParCompraProductos infoCompra = interfazCompra -> obtenerInfoCompra(); //Almacena los productos, fecha actual y monto final, incluyendo descuentos

vector<DataProducto> dProductos = infoCompra.getProductos();
cout << "\nFecha: " + infoCompra.getFecha().toString();
cout << "\nMonto final: " + to_string(infoCompra.getMontoFinal());
cout << "\nProductos:";
for (unsigned int i = 0; i<dProductos.size(); i++){
    cout << "\n\t" << dProductos[i].toString();
}
cout << "\n";

interfazCompra->confirmarCompra();

};