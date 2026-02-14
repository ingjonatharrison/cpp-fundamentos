#include <iostream>
using namespace std;

// 1️⃣ No recibe ni retorna
void mensaje() {
    cout << "Bienvenido al programa de funciones!" << endl;
}

// 2️⃣ Recibe pero no retorna
void mostrarSuma(int a, int b) {
    cout << "La suma es: " << a + b << endl;
}

// 3️⃣ No recibe pero retorna
int obtenerNumero() {
    int numero;
    cout << "Ingresa un numero: ";
    cin >> numero;
    return numero;
}

// 4️⃣ Recibe y retorna
int multiplicar(int a, int b) {
    return a * b;
}

int main() {

    mensaje();  // 1️⃣

    mostrarSuma(5, 3);  // 2️⃣

    int valor = obtenerNumero();  // 3️⃣
    cout << "El numero ingresado fue: " << valor << endl;

    int resultado = multiplicar(4, 6);  // 4️⃣
    cout << "La multiplicacion es: " << resultado << endl;

    return 0;
}
