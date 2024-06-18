#include "../../include/CasosDeUso/CasosDeUso.h"

void EnviarProducto(){
    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    vector<string> listaNicknames = IC->obtenerListaNicknameVendedores();

    cout << "Vendedores:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << listaNicknames[i] << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;
    cout << "========";

    vector<ParCodigoNombre> productos = IC->obtenerProductosPendientesEnvio(nickname); 

    cout << "Productos del vendedor:" << endl;
    for (long unsigned int i = 0; i < productos.size(); i++){
        cout << productos[i].getCodigo() << "-" << productos[i].getNombre() << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno (codigo): ";
    int producto;
    cin >> producto;
    cout << "========";

    vector<ParNickFecha> clientesCompra = IC -> obtenerParNickFechaEnvio(producto);

    cout << "Clientes a enviar el producto:" << endl;
    for (long unsigned int i = 0; i < clientesCompra.size(); i++){
        cout << clientesCompra[i].getNickname() << " - " << clientesCompra[i].getFecha().toString() << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno (nombre): ";
    string cliente;
    cin >> cliente;
    cout << "========";

    IC->enviarProducto(producto, cliente);

    cout << "Producto enviado"<< endl;
}
