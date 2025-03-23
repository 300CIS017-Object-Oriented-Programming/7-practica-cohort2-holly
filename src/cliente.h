//
// Created by santi on 3/19/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <vector>
using namespace std;

class cliente {
private:
    int id;
    string nombre;
    vector<string> historialCompras;

public:
    cliente(int id, string nombre);
    void agregarCompra(string producto);
    void mostrarHistorialCompras() const;
    string obtenerNombre() const;
    string getNombre() const { return nombre; }
    int getId() const { return id; }
};



#endif //CLIENTE_H
