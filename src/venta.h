//
// Created by santi on 3/19/2025.
//

#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include "Producto.h"
#include "cliente.h"
using namespace std;

class venta {
private:
    int id;
    cliente* cliente;
    vector<producto*> productosVendidos;
    vector<int> cantidades;
public:
    venta(int id, class cliente* cliente);
    ~venta();

    void agregarProductoVendido(producto* producto, int cantidad);
    float calcularTotal() const;
    void mostrarDetalleVenta() const;
};



#endif //VENTA_H
