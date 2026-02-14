#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

void registrarEstudiantes(Estudiante alumnos[], int &cantidad) {

    cout << "Cuantos estudiantes deseas agregar? ";
    int nuevos;
    cin >> nuevos;

    // 🔴 Validación 1: arreglo lleno
    if (cantidad >= 100) {
        cout << "No se pueden agregar mas estudiantes. Limite alcanzado.\n";
        return;
    }

    // 🔴 Validación 2: evitar desbordamiento
    if (cantidad + nuevos > 100) {
        cout << "Supera el limite de 100 estudiantes.\n";
        return;
    }

    // ✅ Si pasa validaciones, ahora sí ejecutamos el for
    for (int i = 0; i < nuevos; i++) {

        cout << "\nEstudiante " << cantidad + 1 << endl;

        cout << "Nombre: ";
        cin >> alumnos[cantidad].nombre;

        cout << "Edad: ";
        cin >> alumnos[cantidad].edad;

        cout << "Promedio: ";
        cin >> alumnos[cantidad].promedio;

        cantidad++;
    }
}


void mostrarEstudiantes(Estudiante alumnos[], int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Edad: " << alumnos[i].edad << endl;
        cout << "Promedio: " << alumnos[i].promedio << endl;
    }
}

void promedioGeneral(Estudiante alumnos[], int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes.\n";
        return;
    }

    float suma = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += alumnos[i].promedio;
    }

    cout << "Promedio general: " << suma / cantidad << endl;
}

void buscarEstudiante(Estudiante alumnos[], int cantidad) {
    string nombreBuscado;
    cout << "Nombre a buscar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].nombre == nombreBuscado) {
            cout << "Encontrado: "
                 << alumnos[i].nombre
                 << " - Promedio: "
                 << alumnos[i].promedio << endl;
            return;
        }
    }

    cout << "Estudiante no encontrado.\n";
}

int main() {

    Estudiante alumnos[100];
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n--- SISTEMA DE ESTUDIANTES ---\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Promedio general\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiantes(alumnos, cantidad);
                break;
            case 2:
                mostrarEstudiantes(alumnos, cantidad);
                break;
            case 3:
                promedioGeneral(alumnos, cantidad);
                break;
            case 4:
                buscarEstudiante(alumnos, cantidad);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}
