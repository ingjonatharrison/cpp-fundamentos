// Ejercicio 5: Producto dinamico
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Producto
{
    string nombre;
    float precio;
    int cantidad;
};

int main()
{
    cout << "=== PRODUCTO DINAMICO ===\n";

    Producto* producto = new Producto;

    cout << "Nombre del producto: ";
    getline(cin >> ws, producto->nombre);

    cout << "Precio unitario: ";
    while (!(cin >> producto->precio) || producto->precio < 0)
    {
        cout << "Dato invalido. Ingresa un precio mayor o igual a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Cantidad: ";
    while (!(cin >> producto->cantidad) || producto->cantidad < 0)
    {
        cout << "Dato invalido. Ingresa una cantidad entera mayor o igual a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    float importe = producto->precio * producto->cantidad;

    cout << fixed << setprecision(2);
    cout << "\n----- REPORTE DEL PRODUCTO -----\n";
    cout << "Nombre:   " << producto->nombre << "\n";
    cout << "Precio:   $" << producto->precio << "\n";
    cout << "Cantidad: " << producto->cantidad << "\n";
    cout << "Importe:  $" << importe << "\n";

    delete producto;
    producto = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
