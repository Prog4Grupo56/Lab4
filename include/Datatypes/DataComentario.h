#ifndef DATACOMENTARIO
#define DATACOMENTARIO

#include "DTFecha.h"
#include <string>

class DataComentario{

    private:
        string comentario;
        DTFecha fecha;
        int idComentario;
        string comentador;
        int codigoProducto;
    public:
        DataComentario(string _comentario, DTFecha _fecha, int id, string _comentador, int _codigoProducto);
        ~DataComentario();

        string getComentario();
        DTFecha getFecha();
        int getIdComentario();
        string getComentador();
        int getCodigoProducto();
        
        string toString();

};

#endif