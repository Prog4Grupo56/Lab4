#include <iostream>
#ifndef DATAPRODUCTO
#define DATAPRODUCTO
using namespace std;

#include <string>
//#include "Categoria.h"


class DataProducto{

    private:
        string codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        //Categoria* categoria;

    public:
        //Constructor
        DataProducto(string _codigo, int _stock, float _precio, string _nombre, string _descripcion/*, Categoria _categoria*/);

        //Destructor
        ~DataProducto();

        //Getters
        string getCodigo();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        //Categoria* getCategoria();

        //Setters
        void setCodigo(string _codigo);
        void setStock(int _stock);
        void setPrecio(float _precio);
        void setNombre(string _nombre);
        void setDescripcion(string _descripcion);
        //void setCategoria(Categoria* _categoria);
};

#endif