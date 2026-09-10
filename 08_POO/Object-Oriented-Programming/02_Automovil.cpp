#include <iostream>
#include <string>
using namespace std;

class Automovil {
public:
    string marca;
    string modelo;
    int velocidad;
    bool encendido;

    void encender() {
        encendido = true;
        cout << "El automovil se ha encendido." << endl;
    }

    void acelerar() {
        if (encendido) {
            velocidad += 10;
            cout << "Velocidad actual: " << velocidad << " km/h" << endl;
        } else {
            cout << "El automovil esta apagado." << endl;
        }
    }

    void frenar() {
        velocidad -= 10;

        if (velocidad < 0) {
            velocidad = 0;
        }

        cout << "Velocidad actual: " << velocidad << " km/h" << endl;
    }
};

int main() {
    Automovil auto1;

    auto1.marca = "Toyota";
    auto1.modelo = "Corolla";
    auto1.velocidad = 0;
    auto1.encendido = false;

    cout << auto1.marca << " " << auto1.modelo << endl;

    auto1.encender();
    auto1.acelerar();
    auto1.acelerar();
    auto1.frenar();

    return 0;
}