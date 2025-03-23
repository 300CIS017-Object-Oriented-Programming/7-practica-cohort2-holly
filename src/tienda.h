//
// Created by santi on 3/19/2025.
//

#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <string>
#include "producto.h"
#include "cliente.h"
#include "venta.h"
using namespace std;

class tienda {
private:
    vector<producto*> productos;
    vector<cliente*> clientes;
    vector<venta*> ventas;

public:
    tienda();
    ~tienda();

    void agregarProducto(string codigo, string nombre, float precio, int stockInicial);
    void registrarVenta(int idCliente);
    void reabastecerProducto(string codigoProducto, int cantidad);
    producto* buscarProducto(string codigo);
    cliente* buscarCliente(int idCliente);
    void listarProductos() const;
    void mostrarVentas() const;
    float calcularValorInventario() const;
};



#endif //TIENDA_H
