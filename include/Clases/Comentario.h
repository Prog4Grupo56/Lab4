#ifndef COMENTARIO
#define COMENTARIO

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataComentario.h"
#include "Usuario.h"

class Usuario; //fwd

class Comentario
{
    private:
        DTFecha fecha;
        string comentario;
        int idComentario;
        map<int,Comentario*> respuestas;
        Comentario* padre;
        Usuario* comentador;
        int codProducto;
    public:
        Comentario(DTFecha _fecha, string _comentario, int _idComentario, Comentario* _padre, Usuario* _comentador, int _codigo);
        ~Comentario();

        DTFecha getFecha();
        string getComentario();
        int getIdComentario();
        map<int,Comentario*> getRespuestas();
        Comentario* getPadre();
        int getProducto();
        Usuario* getComentador();

        void setFecha(DTFecha _fecha);
        void setComentario(string _comentario);
        void setiDComentario(int id);
        void setRespuesta(Comentario* respuesta);
        void setPadre(Comentario* padre);

        void desvincularPadre();
        void eliminarComentario(); //este es el destructor??
        void desvincularHijo(Comentario* c);

        string obtenerNicknameComentador();
        int obtenerCodigoProdComentado();
};

#endif