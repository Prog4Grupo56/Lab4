#ifndef DTCOMENTARIO
#define DTCOMENTARIO

#include "DTFecha.h"
#include <string>

class DTComentario{

    private:
        string comentario;
        DTFecha fecha;
        int idComentario;
        string comentador;
        int codigoProducto;
    public:
        DTComentario(string _comentario, DTFecha _fecha, int id, string _comentador, int _codigoProducto);
        ~DTComentario();

        string getComentario();
        DTFecha getFecha();
        int getIdComentario();
        string getComentador();
        int getCodigoProducto();
        
        string toString();

};

#endif