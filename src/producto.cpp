//
// Created by santi on 3/19/2025.
//

#include "producto.h"

producto::producto(string cod, string nom, float prec, int stk)
    : codigo(cod), nombre(nom), precio(prec), stock(stk) {}

bool producto::descontarStock(int cantidad) {
    if (cantidad <= stock) {
        stock -= cantidad;
        return true;
    }
    return false;
}

void producto::agregarStock(int cantidad) {
    stock += cantidad;
}

int producto::obtenerStock() const {
    return stock;
}

string producto::obtenerNombre() const {
    return nombre;
}
