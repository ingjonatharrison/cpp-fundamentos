// Ejercicio 7: Alumno con cantidad variable de calificaciones
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Alumno
{
    string nombre;
    float* calificaciones;
    int cantidadCalificaciones;
    float promedio;
};

int main()
{
    cout << "=== ALUMNO CON CALIFICACIONES VARIABLES ===\n";

    Alumno* alumno = new Alumno;
    alumno->calificaciones = nullptr;
    alumno->promedio = 0.0f;

    cout << "Nombre del alumno: ";
    getline(cin >> ws, alumno->nombre);

    cout << "Cantidad de calificaciones: ";
    while (!(cin >> alumno->cantidadCalificaciones) || alumno->cantidadCalificaciones <= 0)
    {
        cout << "Dato invalido. Ingresa un entero mayor a 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Reserva del arreglo interno
    alumno->calificaciones = new float[alumno->cantidadCalificaciones];

    float suma = 0.0f;
    for (int i = 0; i < alumno->cantidadCalificaciones; i++)
    {
        cout << "Calificacion " << (i + 1) << " (0-100): ";
        while (!(cin >> alumno->calificaciones[i]) || alumno->calificaciones[i] < 0 || alumno->calificaciones[i] > 100)
        {
            cout << "Dato invalido. Ingresa un valor entre 0 y 100: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        suma += alumno->calificaciones[i];
    }
    alumno->promedio = suma / alumno->cantidadCalificaciones;

    // Reporte completo
    cout << fixed << setprecision(2);
    cout << "\n----- REPORTE DEL ALUMNO -----\n";
    cout << "Nombre: " << alumno->nombre << "\n";
    cout << "Cantidad de calificaciones: " << alumno->cantidadCalificaciones << "\n";
    cout << "Calificaciones: ";
    for (int i = 0; i < alumno->cantidadCalificaciones; i++)
    {
        cout << alumno->calificaciones[i] << (i < alumno->cantidadCalificaciones - 1 ? ", " : "");
    }
    cout << "\nPromedio: " << alumno->promedio << "\n";

    // Liberacion de adentro hacia afuera
    delete[] alumno->calificaciones;
    alumno->calificaciones = nullptr;
    delete alumno;
    alumno = nullptr;

    cout << "\nMemoria liberada correctamente.\n";
    return 0;
}
