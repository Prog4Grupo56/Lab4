#include "../../include/Clases/Promocion.h"

Promocion :: Promocion(DataPromocion _promocion, vector<CantMin*> _cantidadesMinimas){
    cantMinProductos = _cantidadesMinimas;
    nombre = _promocion.getNombre();
    descripcion = _promocion.getDescripcion();
    descuento = _promocion.getDescuento();
    fechaVenc = _promocion.getFechaVenc();
}

Promocion ::~Promocion(){}

string Promocion ::getNombre(){return nombre;}
string Promocion ::getDescripcion(){return descripcion;}
float Promocion ::getDescuento(){return descuento;}
DTFecha Promocion ::getFechaVenc(){return fechaVenc;}

vector<CantMin*> Promocion ::getCantidadesMinimas(){
    return cantMinProductos;
}

void Promocion ::setNombre(string nombre_){ nombre = nombre_;}
void Promocion ::setDescripcion(string descripcion_){ descripcion = descripcion_;}
void Promocion ::setDescuento(float descuento_){ descuento = descuento_;}
void Promocion ::setFechaVenc(DTFecha fecha_){ fechaVenc = fecha_;}

void Promocion ::agregarCantMinProducto(CantMin *cMinProd){
    cantMinProductos.push_back(cMinProd);
}

DataPromocion Promocion::getDataPromocion(){
    return DataPromocion(nombre, descripcion, fechaVenc, descuento);
}

vector<ParCodigoCantidad> Promocion::aplicaEnCompra(vector<ParCodigoCantidad> prodCant){
    vector<ParCodigoCantidad> aplican;
    
    long unsigned int it = 0;
    while( it < cantMinProductos.size() ){
        bool cumpleCmin = false;
        bool pertenece = false;
        long unsigned int i=0;
        while( (i < prodCant.size()) && !(pertenece && cumpleCmin) ){
            cumpleCmin = cantMinProductos[it]->getCantidadMinima() <= prodCant[i].getCantidad();
            pertenece = cantMinProductos[it]->pertenecePromocion(prodCant[i].getCodigo());
            if (pertenece && cumpleCmin) {
                aplican.push_back(prodCant[i]);
            }
            ++i;
        }
        if (!(pertenece && cumpleCmin)) {   // Si no inserte, se recorren todos los prodCant y !(pertenece && cumpleCmin) termina en true
            aplican.clear();     // No se insertó nada nuevo en aplican, la promoción no aplica
            return aplican;
        }

        ++it;
    }
    return aplican;
}