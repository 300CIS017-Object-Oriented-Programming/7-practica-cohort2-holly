//
// Created by santi on 3/19/2025.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class producto {
private:
    string codigo;
    string nombre;
    float precio;
    int stock;

public:
    producto(string cod, string nom, float prec, int stk);
    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    int obtenerStock() const;
    string obtenerNombre() const;

};



#endif //PRODUCTO_H
