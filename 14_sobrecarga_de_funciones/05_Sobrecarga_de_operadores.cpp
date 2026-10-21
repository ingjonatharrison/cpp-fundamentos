#include <iostream>
using namespace std;

class Vector {

    private:

        int n;    // Tamano del vector
        int *vec; // Arreglo dinamico

    public:

        // Constructores y destructor
        Vector(int = 1);
        Vector(const Vector &);
        ~Vector();

        // Metodos get y set
        int getN() const;
        void setN(int);

        // Captura y visualizacion
        void captura();
        void mostrar() const;

        // Sobrecarga de operadores
        Vector operator+(const Vector &) const; // vector + vector
        Vector operator*(int) const;            // vector * escalar (A * 3)
        friend Vector operator*(int, const Vector &); // escalar * vector (3 * A)
        int operator*(const Vector &) const;    // producto punto (A * B)
        Vector &operator=(const Vector &);      // asignacion entre objetos
};

// ===================== Etapa 1: constructores y destructor =====================

Vector::Vector(int tam) { // Actividad 1: constructor con argumento predeterminado (n >= 1, todo en cero)
    n = (tam < 1) ? 1 : tam;
    vec = new int[n];
    for (int i = 0; i < n; i++)
        vec[i] = 0;
}

Vector::Vector(const Vector &otro) { // Actividad 2: constructor de copia (copia profunda, memoria propia)
    n = otro.n;
    vec = new int[n];
    for (int i = 0; i < n; i++)
        vec[i] = otro.vec[i];
}


Vector::~Vector() { // Actividad 3: destructor (se reservo con new[], se libera con delete[])
    delete[] vec;
}

// ========================== Etapa 2: metodos basicos ===========================


int Vector::getN() const { // Actividad 4: get y set
    return n;
}

void Vector::setN(int nuevoN) {
    if (nuevoN < 1) {
        cout << "  [Aviso] setN rechazo la dimension " << nuevoN
             << " (debe ser >= 1). El vector no cambio." << endl;
        return;
    }
    if (nuevoN == n)
        return; // mismo tamano: no hay que redimensionar

    int *nuevo = new int[nuevoN];
    for (int i = 0; i < nuevoN; i++)
        nuevo[i] = (i < n) ? vec[i] : 0; // conserva lo que quepa, resto en cero

    delete[] vec; // libera el arreglo anterior
    vec = nuevo;
    n = nuevoN;
}

void Vector::captura() { // Actividad 5: captura
    for (int i = 0; i < n; i++) {
        cout << "  Elemento [" << i + 1 << "] de " << n << ": ";
        cin >> vec[i];
    }
}

void Vector::mostrar() const { // Actividad 6: mostrar (no modifica el objeto)
    cout << "Vector: [ ";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << " ]" << endl;
}

// ===================== Etapa 3: sobrecarga de operadores =======================

Vector Vector::operator+(const Vector &otro) const {// Actividad 7: suma (la validacion de dimensiones se hace en main)
    Vector resultado(n);
    for (int i = 0; i < n; i++)
        resultado.vec[i] = vec[i] + otro.vec[i];
    return resultado;
}

Vector Vector::operator*(int k) const { // Actividad 8.1: vector * escalar. this = operando izquierdo (el Vector)
    Vector resultado(n);
    for (int i = 0; i < n; i++)
        resultado.vec[i] = vec[i] * k;
    return resultado;
}


Vector operator*(int k, const Vector &v) { // Actividad 8.2: escalar * vector. Funcion amiga (sin Vector::), dos parametros
    Vector resultado(v.n);
    for (int i = 0; i < v.n; i++)
        resultado.vec[i] = k * v.vec[i];
    return resultado;
}


int Vector::operator*(const Vector &otro) const { // Actividad 9: producto punto (devuelve int)
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += vec[i] * otro.vec[i];
    return suma;
}


Vector &Vector::operator=(const Vector &otro) { // Actividad 10: asignacion (copia profunda, autoasignacion, encadenable)
    if (this != &otro) {
        int *nuevo = new int[otro.n]; // primero reserva...
        for (int i = 0; i < otro.n; i++)
            nuevo[i] = otro.vec[i];
        delete[] vec;                 // ...luego libera la memoria vieja
        vec = nuevo;
        n = otro.n;
    }
    return *this;
}

// ============================== Programa principal =============================

void titulo(const char *texto) {
    cout << "\n==== " << texto << " ====" << endl;
}

int main() {

    // ---- 1. Construccion de objetos ----
    titulo("1. CONSTRUCTORES");
    Vector D;      // tamano predeterminado (1)
    Vector A(3);
    Vector B(3);
    cout << "D (predeterminado) -> n = " << D.getN() << " | ";
    D.mostrar();
    cout << "A -> n = " << A.getN() << " | ";
    A.mostrar();
    cout << "B -> n = " << B.getN() << " | ";
    B.mostrar();
    Vector Inv(-4); // dimension invalida: se corrige a 1
    cout << "Vector(-4) -> n = " << Inv.getN() << " (se evita dimension menor que 1)" << endl;

    // ---- 2. Captura y visualizacion ----
    titulo("2. CAPTURA Y MOSTRAR");
    cout << "Captura de A:" << endl;
    A.captura();
    cout << "Captura de B:" << endl;
    B.captura();
    cout << "A: "; A.mostrar();
    cout << "B: "; B.mostrar();

    // ---- 3. Suma ----
    titulo("3. SUMA (A + B)");
    if (A.getN() == B.getN()) {
        Vector S = A + B;
        cout << "A + B = "; S.mostrar();
    } else {
        cout << "Dimensiones distintas: no se puede sumar." << endl;
    }

    // ---- 4. Multiplicacion por escalar ----
    titulo("4. VECTOR POR ESCALAR Y ESCALAR POR VECTOR");
    Vector M1 = A * 3;   // funcion miembro
    Vector M2 = 3 * A;   // funcion amiga
    cout << "A * 3 (funcion MIEMBRO) = "; M1.mostrar();
    cout << "3 * A (funcion AMIGA)   = "; M2.mostrar();
    // Si X.Y == X.X == Y.Y entonces X == Y (igualdad en Cauchy-Schwarz)
    if (M1 * M2 == M1 * M1 && M1 * M2 == M2 * M2)
        cout << "Verificacion: ambas versiones producen exactamente los mismos elementos." << endl;
    else
        cout << "Verificacion: las versiones NO coinciden." << endl;

    // ---- 5. Producto punto ----
    titulo("5. PRODUCTO PUNTO (A * B)");
    if (A.getN() == B.getN())
        cout << "A * B = " << A * B << endl;
    else
        cout << "Dimensiones distintas: el producto punto no puede realizarse." << endl;

    // ---- 6. Constructor de copia ----
    titulo("6. CONSTRUCTOR DE COPIA");
    Vector C(A); // C es copia independiente de A
    cout << "Despues de Vector C(A):" << endl;
    cout << "A: "; A.mostrar();
    cout << "C: "; C.mostrar();
    cout << "Capturo nuevos valores en C (A no debe cambiar):" << endl;
    C.captura();
    cout << "A: "; A.mostrar();
    cout << "C: "; C.mostrar();

    // ---- 7. Asignacion ----
    titulo("7. OPERADOR DE ASIGNACION");
    Vector P(5); // tamano distinto al de A
    cout << "Antes de P = A -> P tiene n = " << P.getN() << endl;
    P = A;
    cout << "Despues de P = A: n = " << P.getN() << " | ";
    P.mostrar();
    cout << "Capturo nuevos valores en P (A no debe cambiar):" << endl;
    P.captura();
    cout << "A: "; A.mostrar();
    cout << "P: "; P.mostrar();

    cout << "\nAsignacion encadenada X = Y = Z (tamanos 3, 5 y 2):" << endl;
    Vector X(3), Y(5), Z(2);
    cout << "Captura de Z:" << endl;
    Z.captura();
    X = Y = Z;
    cout << "Z: n = " << Z.getN() << " | "; Z.mostrar();
    cout << "Y: n = " << Y.getN() << " | "; Y.mostrar();
    cout << "X: n = " << X.getN() << " | "; X.mostrar();

    cout << "\nAutoasignacion A = A:" << endl;
    A = A;
    cout << "A: "; A.mostrar();

    // ---- 8. getN y setN ----
    titulo("8. getN() Y setN()");
    Vector R(A); // R = [1, 2, 3]
    cout << "R inicial -> n = " << R.getN() << " | "; R.mostrar();
    R.setN(5);
    cout << "Tras setN(5) (aumenta) -> n = " << R.getN() << " | "; R.mostrar();
    R.setN(2);
    cout << "Tras setN(2) (reduce)  -> n = " << R.getN() << " | "; R.mostrar();
    R.setN(2);
    cout << "Tras setN(2) (igual)   -> n = " << R.getN() << " | "; R.mostrar();
    R.setN(0);
    cout << "Tras setN(0) (invalido)-> n = " << R.getN() << " | "; R.mostrar();

    // ---- 9. Originales sin cambios ----
    titulo("9. ORIGINALES SIN CAMBIOS TRAS SUMA Y MULTIPLICACIONES");
    cout << "A: "; A.mostrar();
    cout << "B: "; B.mostrar();

    // ---- 10. Dimensiones incompatibles ----
    titulo("10. DIMENSIONES INCOMPATIBLES");
    Vector W(4); // n = 4 contra A con n = 3
    cout << "A tiene n = " << A.getN() << " y W tiene n = " << W.getN() << endl;
    if (A.getN() == W.getN()) {
        Vector S2 = A + W;
        S2.mostrar();
    } else {
        cout << "[Aviso] Dimensiones distintas: la suma NO se ejecuta." << endl;
    }
    if (A.getN() == W.getN()) {
        cout << "A * W = " << A * W << endl;
    } else {
        cout << "[Aviso] Dimensiones distintas: el producto punto NO se ejecuta." << endl;
    }

    cout << "\nFin del programa." << endl;
    return 0;
}