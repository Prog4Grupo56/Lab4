#ifndef DATACOMENTARIO
#define DATACOMENTARIO

#include "DTFecha.h"
#include <string>

class DataComentario{

    private:
        string comentario;
        DTFecha* fecha;
        int idComentario;
    public:
        DataComentario(string _comentario, DTFecha* _fecha, int id);
        ~DataComentario();

        string getComentario();
        DTFecha* getFecha();
        int getIdComentario();

};

#endif