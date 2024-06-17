/*
El caso de uso comienza cuando se quiere registrar el envío de un producto
para una compra determinada. Para esto el Sistema lista los nicknames de
todos los vendedores, el Administrador selecciona uno y se listan los
productos que vende ese vendedor que tienen al menos una compra
pendiente de envío. Luego el Administrador selecciona el producto y el
Sistema lista todas las compras como parejas (nickname del cliente, fecha
de compra), para aquellas compras que tienen pendientes de enviar el
producto. Finalmente, el Administrador selecciona un elemento de esa lista y
el Sistema marca el producto en la compra como enviado
*/

#include "../../include/CasosDeUso/CasosDeUso.h"

void EnviarProducto(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();

    vector<string> listaNicknames = IU->obtenerListaNicknameVendedores();

    cout << "Vendedores:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << listaNicknames[i] << endl;
    }

    cout << "========"<< endl;
    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;
    IU->seleccionarUsuario(nickname);
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

    IC->enviarProducto();
}
