#include "../include/DTFecha.h"
// Constructor
DTFecha::DTFecha(int _dia, int _mes, int _ano): dia(_dia), mes(_mes), ano(_ano) {}
// Destructor
DTFecha::~DTFecha() {};

/*======= GETTERS ========*/
int DTFecha::getDia(){ return dia; }
int DTFecha::getMes(){ return mes; }
int DTFecha::getAno(){ return ano; }

/*======= SETTERS ========*/
void DTFecha::setFecha(int _dia, int _mes, int _ano){
    dia = _dia;
    mes = _mes;
    ano = _ano;
}
// Metodos
string DTFecha::toString(){
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}

bool operator<=(DTFecha f1, DTFecha f2){
    return (f1.ano<f2.ano || (f1.ano==f2.ano && f1.mes<f2.mes) || (f1.ano==f2.ano && f1.mes==f2.mes && f1.dia<=f2.dia));
}