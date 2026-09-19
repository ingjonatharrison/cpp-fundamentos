// Ejercicio 8: Procesamiento configurable con puntero a funcion
#include <iostream>
using namespace std;

// Funciones compatibles: reciben un int y devuelven un int
int doble(int x)       { return x * 2; }
int cuadrado(int x)    { return x * x; }
int incrementar(int x) { return x + 1; }

// Funcion general: aplica 'operacion' a cada elemento (un solo recorrido)
void procesar(int datos[], int cantidad, int (*operacion)(int))
{
    for (int i = 0; i < cantidad; i++)
    {
        datos[i] = operacion(datos[i]);
    }
}

void mostrar(const char* titulo, const int datos[], int cantidad)
{
    cout << titulo << " [ ";
    for (int i = 0; i < cantidad; i++)
    {
        cout << datos[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    cout << "=== PROCESAMIENTO CON PUNTERO A FUNCION ===\n";

    const int CANTIDAD = 5;
    int datos[CANTIDAD];

    cout << "Ingresa " << CANTIDAD << " enteros:\n";
    for (int i = 0; i < CANTIDAD; i++)
    {
        cout << "Dato [" << i << "]: ";
        while (!(cin >> datos[i]))
        {
            cout << "Dato invalido. Ingresa un entero: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    cout << "\nTransformaciones disponibles:\n";
    cout << "  1. Doble\n  2. Cuadrado\n  3. Incrementar en 1\n";
    int opcion;
    cout << "Elige una opcion: ";
    while (!(cin >> opcion) || opcion < 1 || opcion > 3)
    {
        cout << "Opcion invalida. Elige 1, 2 o 3: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Seleccion mediante puntero a funcion
    int (*operacion)(int) = nullptr;
    switch (opcion)
    {
        case 1: operacion = doble; break;
        case 2: operacion = cuadrado; break;
        case 3: operacion = incrementar; break;
    }

    cout << "\n";
    mostrar("Valores originales:     ", datos, CANTIDAD);
    procesar(datos, CANTIDAD, operacion);
    mostrar("Valores transformados:  ", datos, CANTIDAD);

    return 0;
}
