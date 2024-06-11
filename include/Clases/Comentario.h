#ifndef COMENTARIO
#define COMENTARIO

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DataComentario.h"
//#include "../Clases/Producto.h"
#include <set>
#include "Usuario.h"
#include "Producto.h"

class Usuario; //fwd
class Producto;

class Comentario
{
    private:
        DTFecha fecha;
        string comentario;
        int idComentario;
        set<Comentario*> respuestas;
        Comentario* padre;
        Usuario* comentador;
        Producto* producto;
    public:
        Comentario(DTFecha _fecha, string _comentario, int _idComentario, Comentario* _padre, Usuario* _comentador, Producto* p);
        ~Comentario();

        DTFecha getFecha();
        string getComentario();
        int getIdComentario();
        set<Comentario*> getRespuestas();
        Comentario* getPadre();

        void setFecha(DTFecha _fecha);
        void setComentario(string _comentario);
        void setiDComentario(int id);
        void setRespuesta(Comentario* respuesta);
        void setPadre(Comentario* padre);

        void desvincularPadre();
        void eliminarComentario(); //este es el destructor??
        void desvincularHijo(Comentario* c);
};

#endif