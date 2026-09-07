#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Nodo {
    string dato;
    Nodo* izq;
    Nodo* der;

    Nodo(const string& valor) : dato(valor), izq(nullptr), der(nullptr) {}
};

bool esHoja(Nodo* nodo) {
    return (nodo->izq == nullptr && nodo->der == nullptr);
}

Nodo* crearNodo(const string& valor) {
    return new Nodo(valor);
}

int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}

int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    if (esHoja(raiz)) return 1;
    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}

int calcularAltura(Nodo* raiz) {
    if (raiz == nullptr) return -1;
    if (esHoja(raiz)) return 0;

    int alturaIzq = calcularAltura(raiz->izq);
    int alturaDer = calcularAltura(raiz->der);

    return 1 + max(alturaIzq, alturaDer);
}

void preorden(Nodo* raiz, vector<string>& resultado) {
    if (raiz == nullptr) return;

    resultado.push_back(raiz->dato);   
    preorden(raiz->izq, resultado);    
    preorden(raiz->der, resultado);    
}

string inorden(Nodo* raiz) {
    if (raiz == nullptr) return "";
    
    if (esHoja(raiz)) {
        return raiz->dato;
    }
    
    string izquierda = inorden(raiz->izq);
    string derecha = inorden(raiz->der);

    return "(" + izquierda + " " + raiz->dato + " " + derecha + ")";
}

void postordenNotacion(Nodo* raiz, vector<string>& resultado) {
    if (raiz == nullptr) return;

    postordenNotacion(raiz->izq, resultado); 
    postordenNotacion(raiz->der, resultado); 
    resultado.push_back(raiz->dato);         
}

double evaluarArbol(Nodo* raiz) {
    if (raiz == nullptr) return 0.0;

    if (esHoja(raiz)) {
        return stod(raiz->dato);
    }

    double valorIzq = evaluarArbol(raiz->izq);
    double valorDer = evaluarArbol(raiz->der);

    if (raiz->dato == "+") return valorIzq + valorDer;
    if (raiz->dato == "-") return valorIzq - valorDer;
    if (raiz->dato == "*") return valorIzq * valorDer;
    if (raiz->dato == "/") {
        if (valorDer == 0) {
            cerr << "Error: division entre cero detectada." << endl;
            exit(1);
        }
        return valorIzq / valorDer;
    }

    cerr << "Error: operador desconocido (" << raiz->dato << ")" << endl;
    exit(1);
}

void liberarArbol(Nodo* raiz) {
    if (raiz == nullptr) return;

    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    delete raiz;             
}

void imprimirVector(const vector<string>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << "   ";
    }
    cout << endl;
}

void procesarArbol(Nodo* raiz, const string& tituloArbol) {
    cout << "=====================================================" << endl;
    cout << tituloArbol << endl;
    cout << "=====================================================" << endl;

    int totalNodos = contarNodos(raiz);
    int totalHojas = contarHojas(raiz);
    int nodosInternos = totalNodos - totalHojas;
    int altura = calcularAltura(raiz);

    cout << "\nNumero total de nodos: " << totalNodos << endl;
    cout << "Numero de hojas: " << totalHojas << endl;
    cout << "Numero de nodos internos: " << nodosInternos << endl;
    cout << "Altura del arbol: " << altura << endl;

    vector<string> pre;
    preorden(raiz, pre);
    cout << "\nPREORDEN - Notacion prefija:" << endl;
    imprimirVector(pre);

    string infija = inorden(raiz);
    cout << "\nINORDEN - Expresion:" << endl;
    cout << infija << endl;

    vector<string> post;
    postordenNotacion(raiz, post);
    cout << "\nPOSTORDEN - Notacion postfija:" << endl;
    imprimirVector(post);

    double resultado = evaluarArbol(raiz);
    cout << "\nResultado de la expresion:" << endl;
    cout << resultado << endl;

    cout << endl;
}

int main() {

    Nodo* n12 = crearNodo("12");
    Nodo* n8  = crearNodo("8");
    Nodo* n15 = crearNodo("15");
    Nodo* n5  = crearNodo("5");
    Nodo* n7  = crearNodo("7");
    Nodo* n3  = crearNodo("3");

    // Operadores internos
    Nodo* sumaIzq = crearNodo("+");   // 12 + 8
    sumaIzq->izq = n12;
    sumaIzq->der = n8;

    Nodo* restaIzq = crearNodo("-");  // 15 - 5
    restaIzq->izq = n15;
    restaIzq->der = n5;

    Nodo* mult = crearNodo("*");      // (12+8) * (15-5)
    mult->izq = sumaIzq;
    mult->der = restaIzq;

    Nodo* sumaDer = crearNodo("+");   // 7 + 3
    sumaDer->izq = n7;
    sumaDer->der = n3;

    Nodo* raiz1 = crearNodo("/");     // ((12+8)*(15-5)) / (7+3)
    raiz1->izq = mult;
    raiz1->der = sumaDer;

    procesarArbol(raiz1, "ARBOL BINARIO DE EXPRESION - CASO 1");

    liberarArbol(raiz1);
    raiz1 = nullptr;

    /*---------------------------------------------------------
    CASO 2: Segundo arbol de prueba (diferente al del ejemplo)
    Expresion elegida:
       ((9 - 4) * 6) + ((20 / 5) - 2)
    
       Operadores usados: -, *, +, /, -   (5 operadores)
       Operandos usados:  9, 4, 6, 20, 5, 2 (6 operandos)
       Tipos de operadores distintos: +, -, *, /  (los 4)
       No hay divisiones entre cero.
    
     Valores calculados manualmente antes de ejecutar:
       Prefija:   +  *  -  9  4  6  -  /  20  5  2
       Infija:    (((9 - 4) * 6) + ((20 / 5) - 2))
       Postfija:  9 4 - 6 * 20 5 / 2 - +
       Resultado: (5 * 6) + (4 - 2) = 30 + 2 = 32
       Numero de nodos: 11
       Numero de hojas: 6
       Altura: 3
     ---------------------------------------------------------*/

    Nodo* m9  = crearNodo("9");
    Nodo* m4  = crearNodo("4");
    Nodo* m6  = crearNodo("6");
    Nodo* m20 = crearNodo("20");
    Nodo* m5  = crearNodo("5");
    Nodo* m2  = crearNodo("2");

    Nodo* restaA = crearNodo("-");  // 9 - 4
    restaA->izq = m9;
    restaA->der = m4;

    Nodo* multA = crearNodo("*");   // (9-4) * 6
    multA->izq = restaA;
    multA->der = m6;

    Nodo* divB = crearNodo("/");    // 20 / 5
    divB->izq = m20;
    divB->der = m5;

    Nodo* restaB = crearNodo("-");  // (20/5) - 2
    restaB->izq = divB;
    restaB->der = m2;

    Nodo* raiz2 = crearNodo("+");   // ((9-4)*6) + ((20/5)-2)
    raiz2->izq = multA;
    raiz2->der = restaB;

    procesarArbol(raiz2, "ARBOL BINARIO DE EXPRESION - CASO 2 (segundo caso de prueba)");

    liberarArbol(raiz2);
    raiz2 = nullptr;

    return 0;
}
