#include <iostream>
#ifndef DATAPRODUCTO
#define DATAPRODUCTO
using namespace std;

#include "Categoria.h"


class DTProducto{

    private:
        string nombre, descripcion;
        int stock, codigo;
        float precio;
        Categoria categoria;

    public:
        //Constructor
        DTProducto();
        DTProducto(int _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria);

        //Destructor
        ~DTProducto();

        //Getters
        int getCodigo();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();

        string toString();
        
};

#endif