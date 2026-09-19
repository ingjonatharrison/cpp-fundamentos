// Ejercicio 2: Dato dinamico con new y delete
#include <iostream>
using namespace std;

int main()
{
    cout << "=== CUADRADO DE UN NUMERO (DATO DINAMICO) ===\n";

    double* numero = new double;   // reserva dinamica de un solo double

    cout << "Ingresa un numero real: ";
    while (!(cin >> *numero))      // captura mediante desreferencia
    {
        cout << "Dato invalido. Ingresa un numero real: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "\nValor almacenado: " << *numero << "\n";
    cout << "Su cuadrado:      " << (*numero) * (*numero) << "\n";

    delete numero;                 // liberar un solo dato
    numero = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
