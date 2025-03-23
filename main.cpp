#include <iostream>
#include "src/tienda.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Ventas e Inventario ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar productos\n";
    cout << "3. Registrar cliente\n";
    cout << "4. Registrar venta\n";
    cout << "5. Mostrar ventas\n";
    cout << "6. Reabastecer producto\n";
    cout << "7. Calcular valor total del inventario\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    tienda tienda;  // Creación del objeto tienda
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                string codigo, nombre;
                float precio;
                int stock;
                cout << "Ingrese código del producto: ";
                cin >> codigo;
                cout << "Ingrese nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese precio del producto: ";
                cin >> precio;
                cout << "Ingrese cantidad inicial en stock: ";
                cin >> stock;
                tienda.agregarProducto(codigo, nombre, precio, stock);
                cout << "Producto agregado con éxito.\n";
                break;
            }
            case 2:
                tienda.listarProductos();
                break;
            case 3: {
                int id;
                string nombre;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                cout << "Ingrese nombre del cliente: ";
                cin.ignore();
                getline(cin, nombre);
                tienda.agregarCliente(id, nombre);
                break;
            }
            case 4: {
                int idCliente;
                cout << "Ingrese ID del cliente: ";
                cin >> idCliente;
                tienda.registrarVenta(idCliente);
                break;
            }
            case 5:
                tienda.mostrarVentas();
                break;
            case 6: {
                string codigo;
                int cantidad;
                cout << "Ingrese código del producto a reabastecer: ";
                cin >> codigo;
                cout << "Ingrese cantidad a añadir: ";
                cin >> cantidad;
                tienda.reabastecerProducto(codigo, cantidad);
                break;
            }
            case 7:
                cout << "Valor total del inventario: $" << tienda.calcularValorInventario() << endl;
                break;
            case 8:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 8);

    return 0;
}
