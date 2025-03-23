//
// Created by santi on 3/19/2025.
//

#include "tienda.h"
#include <iostream>
using namespace std;

tienda::tienda() {}

tienda::~tienda() {
    for (auto p : productos) delete p;
    for (auto c : clientes) delete c;
    for (auto v : ventas) delete v;
}

void tienda::agregarProducto(string codigo, string nombre, float precio, int stockInicial) {
    productos.push_back(new producto(codigo, nombre, precio, stockInicial));
}

producto* tienda::buscarProducto(string codigo) {
    for (auto p : productos) {
        if (p->obtenerNombre() == codigo) return p;
    }
    return nullptr;
}

cliente* tienda::buscarCliente(int idCliente) {
    for (auto c : clientes) {
        if (c->obtenerNombre() == to_string(idCliente)) return c;
    }
    return nullptr;
}

void tienda::registrarVenta(int idCliente) {
    cliente* c = buscarCliente(idCliente);
    if (!c) {
        cout << "Cliente no encontrado." << endl;
        return;
    }
    int idVenta = ventas.size() + 1;
    venta* nuevaVenta = new venta(idVenta, c);
    string codigoProducto;
    int cantidad;
    while (true) {
        cout << "Ingrese codigo de producto (o 'fin' para terminar): ";
        cin >> codigoProducto;
        if (codigoProducto == "fin") break;
        producto* p = buscarProducto(codigoProducto);
        if (!p) {
            cout << "Producto no encontrado." << endl;
            continue;
        }
        cout << "Cantidad: ";
        cin >> cantidad;
        nuevaVenta->agregarProductoVendido(p, cantidad);
    }
    ventas.push_back(nuevaVenta);
}

void tienda::reabastecerProducto(string codigoProducto, int cantidad) {
    producto* p = buscarProducto(codigoProducto);
    if (p) {
        p->agregarStock(cantidad);
    } else {
        cout << "Producto no encontrado." << endl;
    }
}

void tienda::listarProductos() const {
    cout << "Lista de productos disponibles:" << endl;
    for (const auto& p : productos) {
        cout << "- " << p->obtenerNombre() << " (Stock: " << p->obtenerStock() << ")" << endl;
    }
}

void tienda::mostrarVentas() const {
    cout << "Lista de ventas realizadas:" << endl;
    for (const auto& v : ventas) {
        v->mostrarDetalleVenta();
    }
}

float tienda::calcularValorInventario() const {
    float total = 0;
    for (const auto& p : productos) {
        total += p->obtenerStock() * 10;
    }
    return total;
}