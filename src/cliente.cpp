//
// Created by santi on 3/19/2025.
//

#include "cliente.h"
#include <iostream>
using namespace std;

cliente::cliente(int id, string nombre) : id(id), nombre(nombre) {}

void cliente::agregarCompra(string producto) {
    historialCompras.push_back(producto);
}

void cliente::mostrarHistorialCompras() const {
    cout << "Historial de compras de " << nombre << ":" << endl;
    for (const auto& compra : historialCompras) {
        cout << "- " << compra << endl;
    }
}

string cliente::obtenerNombre() const {
    return nombre;
}
