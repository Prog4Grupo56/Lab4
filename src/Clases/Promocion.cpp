#include "../../include/Clases/Promocion.h"

Promocion :: Promocion(DataPromocion dtPromocion){}

Promocion ::~Promocion(){}

string Promocion ::getNombre(){return nombre;}
string Promocion ::getDescripcion(){return descripcion;}
float Promocion ::getDescuento(){return descuento;}
DTFecha Promocion ::getFechaVenc(){return fechaVenc;}

set<CantMin*> Promocion ::getCantidadesMinimas(){
    return cantMinProductos;
}

void Promocion ::setNombre(string nombre_){ nombre = nombre_;}
void Promocion ::setDescripcion(string descripcion_){ descripcion = descripcion_;}
void Promocion ::setDescuento(float descuento_){ descuento = descuento_;}
void Promocion ::setFechaVenc(DTFecha fecha_){ fechaVenc = fecha_;}

void Promocion ::agregarCantMinProducto(CantMin *cMinProd){
    cantMinProductos.insert(cMinProd);
}

DataPromocion Promocion::getDataPromocion(){
    return DataPromocion(nombre, descripcion, fechaVenc, descuento);
}

set<ParCodigoCantidad> Promocion::aplicaEnCompra(set<ParCodigoCantidad> prodCant){
    /*set<ParCodigoCantidad> aplican;

    bool cumpleCmin = false;
    bool pertenece = false;
    ParCodigoCantidad aux = ParCodigoCantidad();

    set<CantMin*>::iterator it;
    it = cantMinProductos.begin(); 
    while(it != cantMinProductos.end() && pertenece && cumpleCmin ){
        
        set<ParCodigoCantidad>::iterator i;
        i = prodCant.begin();
        while(i != prodCant.end() && !(pertenece && cumpleCmin)){

            cumpleCmin = (*(*it)).getCantidadMinima()<=(*i).getCantidad(); 
            pertenece = (*(*it)).pertenecePromocion( (*i).getCodigo());
            if( pertenece && cumpleCmin ){
                aux = (*i);
                aplican.insert(aux);
            }
            ++i;
        } 
        if(pertenece && cumpleCmin){ // no inserte nada nuevo en aplican, entonces la promocion no aplica 
            aplican.clear();
            return aplican;
        }
        ++it;     
    }
    return aplican;*/
    return {};
}

