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

    cout << "========";
    cout << "Seleccione uno: ";
    string nickname;
    cin >> nickname;
    IU->seleccionarUsuario(nickname);
    cout << "========";

    vector<ParCodigoNombre> productos = IC->obtenerProductosPendientesEnvio(nickname); //Implementar

    cout << "Productos del vendedor:" << endl;
    for (long unsigned int i = 0; i < productos.size(); i++){
        cout << productos[i].getCodigo() << "-" << productos[i].getNombre() << endl;
    }

    cout << "========";
    cout << "Seleccione uno (codigo): ";
    string producto;
    cin >> producto;
    cout << "========";

    vector<ParNickFecha> comprasProducto = IC -> obtenerParNickFechaEnvio(producto); // Implementar

    cout << "Clientes pendientes de envio del producto:" << endl;
    for (long unsigned int i = 0; i < comprasProducto.size(); i++){
        cout << comprasProducto[i].getNickname() << "-" << comprasProducto[i].getFecha().toString() << endl;
    }

    cout << "========";
    cout << "Seleccione uno (nombre): ";
    string cliente;
    cin >> cliente;
    cout << "========";

    IC->enviarProducto();
}
