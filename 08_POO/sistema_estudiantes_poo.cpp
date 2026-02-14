#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    float promedio;

public:
    void capturar() {
        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        cout << "Promedio: ";
        cin >> promedio;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio: " << promedio << endl;
    }

    float obtenerPromedio() {
        return promedio;
    }

    string obtenerNombre() {
        return nombre;
    }
};

int main() {

    Estudiante alumnos[100];
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n--- SISTEMA POO ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                alumnos[cantidad].capturar();
                cantidad++;
                break;

            case 2:
                for (int i = 0; i < cantidad; i++) {
                    alumnos[i].mostrar();
                    cout << "------------------\n";
                }
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 3);

    return 0;
}
