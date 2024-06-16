#include "../../include/CasosDeUso/CasosDeUso.h"

void DejarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();
    IFecha* IF = F->getIFecha();

    DTFecha fecha = IF->getFechaActual();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << listaNicknames[i] << endl;
    }

    cout << "========" << endl;

    cout << "Ingrese un nombre: ";
    string nickname;
    cin >> nickname;

    cout << "========" << endl;

    cout << "Productos:" << endl;
    vector<DataProducto> listaProductos = IC->obtenerListaProductos();
    for (long unsigned int i = 0; i < listaProductos.size(); i++){
        cout << listaProductos[i].getNombre() << ", " <<listaProductos[i].getCodigo() << endl;
    }
    
    cout << "========" << endl;

    cout << "Ingrese un producto (codigo): ";
    int producto;
    cin >> producto;
    
    cout << "========" << endl;
    cout << "¿Desea realizar un comentario nuevo o responder a uno existente?" << endl;
    cout << "0. Nuevo." << endl;
    cout << "1. Responder." << endl;
    cout << "========" << endl;

    int opcion;
    cin >> opcion;

    if (opcion == 0){
        cout << "Ingrese el comentario: ";
        string comentario;
        cin >> comentario;

        IU->ingresarComentarioNuevo(nickname, producto, comentario, fecha);

    }
    else{
        vector<DataComentario> listaComentariosProducto = IU->obtenerListaComentariosProducto(producto);
        cout << "Comentarios sobre el producto " << producto << " (comentario, fecha, id):" << endl;
        for (unsigned int i = 0; i < listaComentariosProducto.size(); i++){
            cout << listaComentariosProducto[i].toString() << endl;
        }

        cout << "========" << endl;
        cout << "Seleccione uno (id): ";
        int id;
        cin >> id;
        cout << "========" << endl;

        cout << "Ingrese el comentario: ";
        string comentario;
        cin >> comentario;

        cout << "========" << endl;

        IU->ingresarComentarioRespuesta(nickname, producto, comentario, fecha, id);
    }

    cout << "Se ingresó su comentario exitosamente." << endl;
    cout << "========" << endl;

}