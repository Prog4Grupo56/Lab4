#include "../include/ParCodigoCantidad.h"


ParCodigoCantidad::ParCodigoCantidad(string _codigo, int _cantMinima)
{
    codigo = _codigo;
    cantidadMinima = _cantMinima;
};
ParCodigoCantidad::~ParCodigoCantidad(){}; //Destructor


string ParCodigoCantidad::getCodigo()
{
    return codigo;
};
int ParCodigoCantidad::getCantidadMinima()
{
    return cantidadMinima;
};

void ParCodigoCantidad::setCodigo(string _codigo)
{
    codigo = _codigo;
};
void ParCodigoCantidad::setCantidadMinima(int _cantMinima)
{
    cantidadMinima = _cantMinima;
};