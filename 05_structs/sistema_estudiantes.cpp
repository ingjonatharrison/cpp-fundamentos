#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

void capturarEstudiantes(Estudiante alumnos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> alumnos[i].nombre;

        cout << "Edad: ";
        cin >> alumnos[i].edad;

        cout << "Promedio: ";
        cin >> alumnos[i].promedio;
    }
}

void mostrarEstudiantes(Estudiante alumnos[], int cantidad) {
    cout << "\n--- Lista de Estudiantes ---\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Edad: " << alumnos[i].edad << endl;
        cout << "Promedio: " << alumnos[i].promedio << endl;
    }
}

int main() {

    int cantidad;

    cout << "Cuantos estudiantes deseas registrar? ";
    cin >> cantidad;

    Estudiante alumnos[100];  // arreglo con capacidad máxima

    capturarEstudiantes(alumnos, cantidad);
    mostrarEstudiantes(alumnos, cantidad);

    return 0;
}
