#include <iostream>
#include <string>
using namespace std;

class TelefonoCelular {
public:
    string marca;
    string modelo;
    int bateria;

    void llamar() {
        cout << "Realizando una llamada..." << endl;
    }

    void enviarMensaje() {
        cout << "Enviando mensaje..." << endl;
    }

    void cargar() {
        bateria = 100;
        cout << "El telefono se ha cargado al 100%." << endl;
    }
};

int main() {
    TelefonoCelular telefono1;

    telefono1.marca = "Samsung";
    telefono1.modelo = "Galaxy S24";
    telefono1.bateria = 50;

    cout << "Marca: " << telefono1.marca << endl;
    cout << "Modelo: " << telefono1.modelo << endl;
    cout << "Bateria: " << telefono1.bateria << "%" << endl;

    telefono1.llamar();
    telefono1.enviarMensaje();
    telefono1.cargar();

    return 0;
}