#ifndef USUARIO
#define USUARIO
#include <vector>
#include <map>
#include <string>
#include "../Datatypes/DTFecha.h"
#include "Comentario.h"
#include "Producto.h"

using namespace std;

class Comentario; //fwd

class Usuario{

    private:
        string nickname;
        DTFecha fecha;
        string contrasena;
        map<int, Comentario*> comentarios;
    public:
        //Constructor
        Usuario(string _nickname, string _constrasenia, DTFecha _fecha); 
        //Destructor
        virtual ~Usuario();

        /*======= GETTERS ========*/
        string getNickname();
        DTFecha getFecha();
        string getContrasena();
        vector<DataComentario> obtenerComentarios();

        /*======= SETTERS ========*/
        void setNickname(string _nickname);
        void setFecha(DTFecha _fecha);

        void setComentario(Comentario* comentario); //Caso de uso dejar comentario
        
        void eliminarComentario(int idComentario);
        void desvincularComentario(Comentario* c);

        void agregarComentarioNuevo(string comentario, Producto* pr, DTFecha _fecha, int idComentario);
        void agregarComentarioRespuesta(string comentario, Producto* pr, DTFecha _fecha, int idComentario, Comentario* padre);

        Comentario* buscarComentario(int id);
};

#endif