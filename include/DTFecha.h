#ifndef DTFECHA
#define DTFECHA

#include <string>

using namespace std;

class DTFecha {
    private:
        int dia, mes, ano;
    public:
        // Constructor
        DTFecha(int _dia, int _mes, int _ano);
        // Destructor
        ~DTFecha();

        /*======= GETTERS ========*/
        int getDia();
        int getMes();
        int getAno();

        /*======= SETTERS ========*/
        void setFecha(int _dia, int _mes, int _ano);
        
        string toString();

        friend bool operator<=(DTFecha f1, DTFecha f2);
};

#endif