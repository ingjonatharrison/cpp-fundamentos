#include <iostream>
#include <string>
using namespace std;

class Cafetera {
public:
    string marca;
    bool encendida;
    int cantidadAgua;

    void encender() {
        encendida = true;
        cout << "La cafetera esta encendida." << endl;
    }

    void apagar() {
        encendida = false;
        cout << "La cafetera esta apagada." << endl;
    }

    void prepararCafe() {
        if (!encendida) {
            cout << "La cafetera esta apagada." << endl;
        } else if (cantidadAgua <= 0) {
            cout << "No hay suficiente agua." << endl;
        } else {
            cout << "Preparando cafe..." << endl;
            cantidadAgua -= 100;
            cout << "Cafe listo." << endl;
        }
    }
};

int main() {
    Cafetera cafetera1;

    cafetera1.marca = "Oster";
    cafetera1.encendida = false;
    cafetera1.cantidadAgua = 500;

    cafetera1.encender();
    cafetera1.prepararCafe();

    cout << "Agua restante: " << cafetera1.cantidadAgua << " ml" << endl;

    cafetera1.apagar();

    return 0;
}