#include <iostream>
using namespace std;

// Definición del struct
struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

// Función para capturar datos
Estudiante crearEstudiante() {
    Estudiante e;

    cout << "Nombre: ";
    cin >> e.nombre;

    cout << "Edad: ";
    cin >> e.edad;

    cout << "Promedio: ";
    cin >> e.promedio;

    return e;
}

// Función para mostrar datos
void mostrarEstudiante(Estudiante e) {
    cout << "\n--- Datos del Estudiante ---" << endl;
    cout << "Nombre: " << e.nombre << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Promedio: " << e.promedio << endl;
}

int main() {

    Estudiante alumno = crearEstudiante();
    mostrarEstudiante(alumno);

    return 0;
}
