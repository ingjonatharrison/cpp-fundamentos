#include <iostream>
#include <string>
using namespace std;

class Ventilador {
public:
    string marca;
    int velocidad;
    bool encendido;

    void encender() {
        encendido = true;
        cout << "El ventilador esta encendido." << endl;
    }

    void apagar() {
        encendido = false;
        cout << "El ventilador esta apagado." << endl;
    }

    void cambiarVelocidad(int nuevaVelocidad) {
        if (encendido) {
            velocidad = nuevaVelocidad;
            cout << "Velocidad: " << velocidad << endl;
        } else {
            cout << "Primero debes encender el ventilador." << endl;
        }
    }
};

int main() {
    Ventilador ventilador1;

    ventilador1.marca = "Mabe";
    ventilador1.velocidad = 0;
    ventilador1.encendido = false;

    ventilador1.encender();
    ventilador1.cambiarVelocidad(3);
    ventilador1.cambiarVelocidad(2);
    ventilador1.apagar();

    return 0;
}