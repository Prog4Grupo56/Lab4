#ifndef USUARIO
#define USUARIO
#include <vector>
#include <map>
#include <string>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTComentario.h"
#include "Comentario.h"

using namespace std;

class Comentario; //fwd
class Producto;

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
        vector<DTComentario> obtenerComentarios();

        /*======= SETTERS ========*/
        void setNickname(string _nickname);
        void setFecha(DTFecha _fecha);

        void setComentario(Comentario* comentario); //Caso de uso dejar comentario
        
        void eliminarComentario(int idComentario);
        void desvincularComentario(Comentario* c);

        void agregarComentarioNuevo(string comentario, int _codigo, DTFecha _fecha, int idComentario);
        void agregarComentarioRespuesta(string comentario, int _codigo, DTFecha _fecha, int idComentario, Comentario* padre);

        Comentario* buscarComentario(int id);
};

#endif