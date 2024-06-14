#include  "../../include/CasosDeUso/CasosDeUso.h"

#include  "../../include/Clases/ICompra.h"
#include "../include/Clases/Fabrica.h"

void RealizarCompra()
{

Fabrica * fabrica = Fabrica::getInstance();
ICompra * interfazCompra= fabrica -> getICompra();

vector<string> listaNicknames = interfazCompra->obtenerListaNicknamesClientes();


for(int i = 0; i < listaNicknames.size(); i++)
    cout << listaNicknames[i] << "\n";
cout << "Seleccione un cliente: \n";
string seleccion;
cin >> seleccion;
interfazCompra -> seleccionarCliente(seleccion); //Queda un dataInfoCompra guardado con el nick seleccionado


cout << "Seleccione los productos a vender: \n";
vector<DataProducto> listaProductos = interfazCompra -> obtenerListaProductos();
bool continuar = true;
int opcion = 1; //Para el menu
string id; int cant; //Id y cantidad del producto
while(continuar)
{

    cout << "1. Agregar nuevo producto.\n";
    cout << "0. Terminar.\n";
    cin >> opcion;
    if(opcion == 1)
    {
        for(int i = 0; i < listaProductos.size(); i++)//Imprimir productos
        {
            cout << listaProductos[i].getCodigo() << " - " << listaProductos[i].getNombre();
        };

        cout << "Ingrese la ID del producto: \n";
        cin >> id;
        cout << "Ingrese la cantidad deseada: \n";
        cin >> cant;
        interfazCompra -> agregarProducto(ParCodigoCantidad(id,cant));
        cout << "Producto ingresado con éxito.\n\n";
    }
    else
    {
        continuar = false;
    }
};



ParCompraProductos infoCompra = interfazCompra -> obtenerInfoCompra(); //Almacena los productos, fecha actual y monto final, incluyendo descuentos


interfazCompra->confirmarCompra();

};