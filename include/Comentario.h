#ifndef COMENTARIO
#define COMENTARIO

#include "DTs/DTFecha.h"
#include "DTs/DataComentario.h"
#include <set>
#include "Usuario.h"

class Usuario; //fwd

class Comentario
{
    private:
        DTFecha* fecha;
        string comentario;
        int idComentario;
        set<Comentario*> respuestas;
        Comentario* padre;
        Usuario* comentador;
    public:
        Comentario(DTFecha* _fecha, string _comentario, int _idComentario, Comentario* _padre, Usuario* _comentador);
        ~Comentario();

        DTFecha* getFecha();
        string getComentario();
        int getIdComentario();
        set<Comentario*> getRespuestas();
        Comentario* getPadre();

        void setFecha(DTFecha* _fecha);
        void setComentario(string _comentario);
        void setiDComentario(int id);
        void setRespuesta(Comentario* respuesta);
        void setPadre(Comentario* padre);

        void desvincularPadre();
        void eliminarComentario(); //este es el destructor??
        void desvincularHijo(Comentario* c);
};

#endif