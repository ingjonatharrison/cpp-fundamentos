// Ejercicio 6: Inventario con arreglo dinamico de estructuras
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Producto
{
    string nombre;
    float precio;
    int existencia;
};

int main()
{
    cout << "=== INVENTARIO CON ARREGLO DINAMICO DE ESTRUCTURAS ===\n";

    int cantidad;
    cout << "Cantidad de productos: ";
    while (!(cin >> cantidad) || cantidad <= 0)
    {
        cout << "Dato invalido. Ingresa un entero mayor a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Producto* productos = new Producto[cantidad];

    // Captura
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\n--- Producto " << (i + 1) << " ---\n";
        cout << "Nombre: ";
        getline(cin >> ws, productos[i].nombre);

        cout << "Precio: ";
        while (!(cin >> productos[i].precio) || productos[i].precio < 0)
        {
            cout << "Dato invalido. Ingresa un precio mayor o igual a 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Existencia: ";
        while (!(cin >> productos[i].existencia) || productos[i].existencia < 0)
        {
            cout << "Dato invalido. Ingresa un entero mayor o igual a 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Reporte
    cout << "\n=========== REPORTE DE INVENTARIO ===========\n";
    cout << left << setw(20) << "Producto" << right << setw(10) << "Precio"
         << setw(12) << "Existencia" << setw(14) << "Valor" << "\n";
    cout << string(56, '-') << "\n";

    cout << fixed << setprecision(2);
    float valorTotal = 0.0f;
    for (int i = 0; i < cantidad; i++)
    {
        float valorProducto = productos[i].precio * productos[i].existencia;
        valorTotal += valorProducto;

        cout << left << setw(20) << productos[i].nombre << right << setw(10) << productos[i].precio
             << setw(12) << productos[i].existencia << setw(14) << valorProducto << "\n";
    }
    cout << string(56, '-') << "\n";
    cout << "Valor total del inventario: $" << valorTotal << "\n";

    delete[] productos;
    productos = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
