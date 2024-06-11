#include <iostream>
#ifndef DATAPRODUCTO
#define DATAPRODUCTO
using namespace std;

#include "Categoria.h"


class DataProducto{

    private:
        string codigo, nombre, descripcion;
        int stock;
        float precio;
        Categoria categoria;

    public:
        //Constructor
        DataProducto();
        DataProducto(string _codigo, int _stock, float _precio, string _nombre, string _descripcion, Categoria _categoria);

        //Destructor
        ~DataProducto();

        //Getters
        string getCodigo();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();

        string toString();
        
};

#endif