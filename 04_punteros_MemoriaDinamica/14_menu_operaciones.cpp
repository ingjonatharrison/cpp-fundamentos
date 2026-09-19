// Ejercicio 9: Menu con arreglo de punteros a funciones
#include <iostream>
using namespace std;

int sumar(int a, int b)       { return a + b; }
int restar(int a, int b)      { return a - b; }
int multiplicar(int a, int b) { return a * b; }
int dividir(int a, int b)     { return a / b; }   // division entera (b != 0 se valida en main)

int main()
{
    cout << "=== CALCULADORA CON ARREGLO DE PUNTEROS A FUNCIONES ===\n";

    int (*operaciones[4])(int, int) =
    {
        sumar,
        restar,
        multiplicar,
        dividir
    };
    const char* nombres[4] = { "suma", "resta", "multiplicacion", "division entera" };
    const char simbolos[4] = { '+', '-', '*', '/' };

    int a, b, opcion;

    cout << "Primer entero: ";
    while (!(cin >> a))
    {
        cout << "Dato invalido. Ingresa un entero: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Segundo entero: ";
    while (!(cin >> b))
    {
        cout << "Dato invalido. Ingresa un entero: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "\nOperaciones:\n  1. Sumar\n  2. Restar\n  3. Multiplicar\n  4. Dividir\n";
    cout << "Elige una opcion: ";
    while (!(cin >> opcion) || opcion < 1 || opcion > 4)
    {
        cout << "Opcion invalida. Elige del 1 al 4: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int indice = opcion - 1;

    if (indice == 3 && b == 0)
    {
        cout << "\nError: no se puede dividir entre cero.\n";
        return 1;
    }

    int resultado = operaciones[indice](a, b);   // llamada mediante el arreglo
    cout << "\nResultado de la " << nombres[indice] << ": "
         << a << " " << simbolos[indice] << " " << b << " = " << resultado << "\n";

    return 0;
}
