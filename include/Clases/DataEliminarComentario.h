#ifndef DATAELIMINARCOMENTARIO
#define DATAELIMINARCOMENTARIO

#include <string>

using namespace std;


class DataEliminarComentario{

    private:
        string nickname;
        int idComentario;
    public:
        DataEliminarComentario();
        DataEliminarComentario(string _nickname, int _idComentario);
        ~DataEliminarComentario();

        string getNickname();
        int getIdComentario();

        void setNickname(string _nickname);
        void setIdComentario(int id);
};

#endif