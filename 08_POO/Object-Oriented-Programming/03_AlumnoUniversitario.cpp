#include <iostream>
#include <string>
using namespace std;

class Alumno {
public:
    string nombre;
    string matricula;
    string carrera;
    int semestre;

    void estudiar() {
        cout << nombre << " esta estudiando." << endl;
    }

    void asistirClase() {
        cout << nombre << " esta asistiendo a clase." << endl;
    }

    void hacerTarea() {
        cout << nombre << " esta haciendo la tarea." << endl;
    }
};

int main() {
    Alumno alumno1;

    alumno1.nombre = "Jonathan";
    alumno1.matricula = "123456";
    alumno1.carrera = "Ingenieria en Sistemas Computacionales";
    alumno1.semestre = 3;

    cout << "Nombre: " << alumno1.nombre << endl;
    cout << "Matricula: " << alumno1.matricula << endl;
    cout << "Carrera: " << alumno1.carrera << endl;
    cout << "Semestre: " << alumno1.semestre << endl;

    alumno1.estudiar();
    alumno1.asistirClase();
    alumno1.hacerTarea();

    return 0;
}