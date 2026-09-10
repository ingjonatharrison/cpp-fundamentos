#include <iostream>
#include <string>
using namespace std;

class Mascota {
public:
    string nombre;
    string especie;
    int edad;

    void comer() {
        cout << nombre << " esta comiendo." << endl;
    }

    void dormir() {
        cout << nombre << " esta durmiendo." << endl;
    }

    void jugar() {
        cout << nombre << " esta jugando." << endl;
    }
};

int main() {
    Mascota mascota1;

    mascota1.nombre = "Firulais";
    mascota1.especie = "Perro";
    mascota1.edad = 3;

    cout << "Nombre: " << mascota1.nombre << endl;
    cout << "Especie: " << mascota1.especie << endl;
    cout << "Edad: " << mascota1.edad << " años" << endl;

    mascota1.comer();
    mascota1.jugar();
    mascota1.dormir();

    return 0;
}