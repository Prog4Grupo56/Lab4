#ifndef USUARIO
#define USUARIO
#include <set>
#include <string>
#include "DTs/DTFecha.h"
#include "Comentario.h"

using namespace std;

class Comentario; //fwd

class Usuario{

    private:
        string nickname;
        DTFecha* fecha;
        string contrasenia;
        set<Comentario*> comentarios; //hay que ver que coleccion usamos
    public:
        //Constructor
        Usuario(string _nickname, string _constrasenia, DTFecha* _fecha); // va este constructor?
        //Destructor
        virtual ~Usuario();

        /*======= GETTERS ========*/
        string getNickname();
        DTFecha* getFecha();
        set<DataComentario*> obtenerComentarios();

        /*======= SETTERS ========*/
        void setNickname(string _nickname);
        void setFecha(DTFecha* _fecha);

        void setComentario(Comentario* comentario); //Caso de uso dejar comentario
        
        void eliminarComentario();
        void desvincularComentario(Comentario* c);
};

#endif