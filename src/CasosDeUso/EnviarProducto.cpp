#include "../../include/CasosDeUso/CasosDeUso.h"

void EnviarProducto(){
    Fabrica* F = Fabrica::getInstance();
    ICompra* IC = F->getICompra();

    vector<string> listaNicknames = IC->obtenerListaNicknameVendedores();

    cout << "Vendedores:";
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\n\tNickname: "<<listaNicknames[i];
    }

    cout << "\n\nIngrese un nickname: ";
    string nickname;
    cin >> nickname;
    vector<DTCodigoNombre> productos = IC->obtenerProductosPendientesEnvio(nickname); 
    cout << "\nProductos pendientes de envio del vendedor:";
    for (long unsigned int i = 0; i < productos.size(); i++){
        cout << "\n\tCodigo: " << productos[i].getCodigo() << " | Nombre: " << productos[i].getNombre();
    }

    cout << "\n\nIngrese un codigo: ";
    int producto;
    cin >> producto;

    vector<DTNickFecha> clientesCompra = IC -> obtenerParNickFechaEnvio(producto);

    cout << "\nClientes a enviar el producto:";
    for (long unsigned int i = 0; i < clientesCompra.size(); i++){
        cout << "\n\tNickname: " << clientesCompra[i].getNickname() << " | Fecha de compra: " << clientesCompra[i].getFecha().toString();
    }

    cout << "\n\nIngrese un nickname: ";
    string cliente;
    cin >> cliente;

    IC->enviarProducto(producto, cliente);

    cout << "\nProducto enviado"<< endl;
}
