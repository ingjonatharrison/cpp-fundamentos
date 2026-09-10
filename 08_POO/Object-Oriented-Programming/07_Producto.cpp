#include <iostream>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    double precio;
    string codigo;

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Codigo: " << codigo << endl;
    }

    void cambiarPrecio(double nuevoPrecio) {
        precio = nuevoPrecio;
        cout << "El precio ha sido actualizado." << endl;
    }

    void consultarPrecio() {
        cout << "Precio actual: $" << precio << endl;
    }
};

int main() {
    Producto producto1;

    producto1.nombre = "Laptop";
    producto1.precio = 15000;
    producto1.codigo = "LAP001";

    producto1.mostrarInformacion();

    producto1.cambiarPrecio(14000);
    producto1.consultarPrecio();

    return 0;
}