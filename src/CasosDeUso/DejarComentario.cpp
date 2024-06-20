#include "../../include/CasosDeUso/CasosDeUso.h"
#include <iostream>
#include <string>

void DejarComentario(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();
    IFecha* IF = F->getIFecha();

    DTFecha fecha = IF->getFechaActual();

    vector<string> listaNicknames = IU->obtenerListaNicknamesUsuarios();

    cout << "Usuarios:" << endl;
    for (long unsigned int i = 0; i < listaNicknames.size(); i++){
        cout << "\tNickname: " << listaNicknames[i] << endl;
    }

    cout << "\nIngrese un nickname: ";
    string nickname;
    cin >> nickname;

    cout << "\nProductos:" << endl;
    vector<DTProducto> listaProductos = IC->obtenerListaProductos();
    for (long unsigned int i = 0; i < listaProductos.size(); i++){
        cout << "\tNombre: " << listaProductos[i].getNombre() << " | Codigo: " <<listaProductos[i].getCodigo() << endl;
    }
    
    cout << "\nIngrese un codigo: ";
    int producto;
    cin >> producto;
    
    cout << "\n¿Desea realizar un comentario nuevo o responder a uno existente?" << endl;
    cout << "\t" << "0. Nuevo." << endl;
    cout << "\t" << "1. Responder." << endl;
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;

    if (opcion == 0){
        cout << "\nIngrese el comentario: ";
        string comentario;
        cin >> comentario;

        IU->ingresarComentarioNuevo(nickname, producto, comentario, fecha);

    }
    else{
        vector<DTComentario> listaComentariosProducto = IU->obtenerListaComentariosProducto(producto);
        cout << "\nComentarios sobre el producto " << producto << ":" << endl;
        for (unsigned int i = 0; i < listaComentariosProducto.size(); i++){
            cout << "\t" << listaComentariosProducto[i].toString() << endl;
        }
        cout << "\nIngrese un Id: ";
        int id;
        cin >> id;
        cout << "\nIngrese el comentario: ";
        string comentario;
        cin.ignore();
        getline(cin, comentario);
        IU->ingresarComentarioRespuesta(nickname, producto, comentario, fecha, id);
    }

    cout << "\nSe ingresó su comentario exitosamente." << endl;

}