//
// Created by santi on 3/19/2025.
//

#include "venta.h"

#include <iostream>

using namespace std;

venta::venta(int id, class cliente* cliente) : id(id), cliente(cliente) {}

venta::~venta() {
    productosVendidos.clear();
    cantidades.clear();
}

void venta::agregarProductoVendido(producto* producto, int cantidad) {
    if (producto->descontarStock(cantidad)) {
        productosVendidos.push_back(producto);
        cantidades.push_back(cantidad);
    } else {
        cout << "Stock insuficiente para " << producto->getNombre() << endl;
    }
}

float venta::calcularTotal() const {
    float total = 0;
    for (size_t i = 0; i < productosVendidos.size(); i++) {
        total += productosVendidos[i]->getPrecio() * cantidades[i];
    }
    return total;
}

void venta::mostrarDetalleVenta() const {
    cout << "Venta ID: " << id << " | Cliente: " << cliente->getNombre() << "\nProductos vendidos:\n";
    for (size_t i = 0; i < productosVendidos.size(); i++) {
        cout << " - " << productosVendidos[i]->getNombre() << " x " << cantidades[i] << "\n";
    }
    cout << "Total: $" << calcularTotal() << endl;
}