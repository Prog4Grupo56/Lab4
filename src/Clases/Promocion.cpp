#include "../../include/Clases/Promocion.h"

Promocion :: Promocion(DataPromocion dtPromocion){}

Promocion ::~Promocion(){}

string Promocion ::getNombre(){}
string Promocion ::getDescripcion(){}
float Promocion ::getDescuento(){}
DTFecha Promocion ::getFechaVenc(){}

void Promocion ::setNombre(){}
void Promocion ::setDescripcion(){}
void Promocion ::setDescuento(){}
void Promocion ::setFechaVenc(){}

DataPromocion Promocion::getDataPromocion(){}
set<ParCodigoCantidad> Promocion::aplicaEnCompra(set<ParCodigoCantidad> prodCant){}
