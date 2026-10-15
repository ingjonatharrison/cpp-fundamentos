#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;

public:
    Producto();
    Producto(string, double);

    void setNombre(string);
    void setPrecio(double);

    string getNombre();
    double getPrecio();

    // Métodos sobrecargados
    void actualizarPrecio(double nuevoPrecio);
    void actualizarPrecio(double nuevoPrecio, double porcentajeDescuento);

    void mostrar();
};

Producto::Producto() {
    nombre = "";
    precio = 0.0;
}

Producto::Producto(string nombre, double precio) {
    this->nombre = nombre;
    this->precio = precio;
}

void Producto::setNombre(string nombre) {
    this->nombre = nombre;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}

string Producto::getNombre() {
    return nombre;
}

double Producto::getPrecio() {
    return precio;
}

// Versión 1
void Producto::actualizarPrecio(double nuevoPrecio) {
    this->precio = nuevoPrecio;
}

// Versión 2
void Producto::actualizarPrecio(double nuevoPrecio, double porcentajeDescuento) {
    double descuento = nuevoPrecio * (porcentajeDescuento / 100.0);
    this->precio = nuevoPrecio - descuento;
}

void Producto::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: $" << precio << endl;
}

int main() {
    Producto producto1("Laptop", 15000.0);
    Producto producto2("Mouse", 300.0);

    cout << "--- Estado inicial ---" << endl;
    producto1.mostrar();
    producto2.mostrar();

    producto1.actualizarPrecio(14000.0);
    
    producto2.actualizarPrecio(400.0, 10.0);

    cout << "\n--- Despues de actualizar ---" << endl;
    producto1.mostrar();
    producto2.mostrar();

    return 0;
}

/*

¿Cuál es el papel de this?

this es un puntero implícito que cada método no estático recibe 
automáticamente y que apunta al objeto que invocó el método. Cuando 
se ejecuta producto1.actualizarPrecio(...), dentro del método this 
apunta a producto1; cuando se ejecuta con producto2, apunta a producto2.
Así, this->precio siempre se refiere al atributo del objeto correcto. 
También sirve para distinguir un atributo de un parámetro con el mismo 
nombre, como en el constructor: this->nombre = nombre; (el de la izquierda
es el atributo, el de la derecha es el parámetro).

¿Por qué las funciones pueden compartir el mismo nombre?
Esto se llama sobrecarga de funciones (polimorfismo estático). C++ permite
que varias funciones tengan el mismo nombre siempre que su lista de parámetros
sea distinta (en cantidad o tipo). El compilador decide en tiempo de compilación
cuál versión llamar según los argumentos que le pasas: con un argumento elige 
actualizarPrecio(double), con dos elige actualizarPrecio(double, double). 
Esto hace el código más legible, porque la misma acción conceptual (“actualizar el 
precio”) conserva un solo nombre, aunque se realice de formas distintas.

*/