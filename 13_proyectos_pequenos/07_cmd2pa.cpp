#include <iostream>  // Librería para entrada/salida (cout, endl)
#include <string>    // Librería para usar el objeto 'string' y sus métodos (.length)

using namespace std; // Permite usar nombres de la biblioteca estándar sin el prefijo std::

/**
 * Función Principal (main)
 * argc: (Argument Count) Cantidad de palabras detectadas en la consola.
 * argv: (Argument Vector) Array que contiene cada palabra como una cadena de texto.
 */
int main(int argc, char* argv[]) {

    // --- 1. VALIDACIÓN DE PARÁMETROS ---
    // El estándar dice que argv[0] es el nombre del programa. 
    // Si queremos 2 palabras extra, argc DEBE ser 3.
    if (argc != 3) {
        cout << "Error en parametros: Se requieren exactamente 2 palabras." << endl;
        
        // Informamos al usuario cuántos argumentos detectó el sistema
        // Restamos 1 a argc para no contar el nombre del archivo ejecutable
        cout << "Has pasado " << argc - 1 << " argumentos adicionales." << endl;

        // Bucle para mostrar qué palabras recibió el programa realmente
        for (int i = 0; i < argc; ++i) {
            cout << "  Argumento " << i << ": " << argv[i] << endl;
        }

        return 1; // Terminamos el programa con código de error (1)
    }

    // --- 2. ASIGNACIÓN Y CONVERSIÓN ---
    // Pasamos los argumentos de la consola (char*) a objetos string.
    // Esto nos facilita usar funciones como .length()
    string palabra1 = argv[1];
    string palabra2 = argv[2];

    // --- 3. OBTENCIÓN DE LONGITUDES ---
    // Almacenamos el tamaño en variables tipo 'size_t' (un entero largo sin signo)
    // o simplemente en 'int'. .length() cuenta los caracteres.
    int tamano1 = palabra1.length();
    int tamano2 = palabra2.length();

    // --- 4. LÓGICA DE COMPARACIÓN POR TAMAÑO ---
    if (tamano1 == tamano2) {
        // Caso: Ambas miden lo mismo (ej: "casa" y "pato")
        cout << "Ambas palabras tienen la misma longitud: " << tamano1 << " letras." << endl;
        
        // Verificación extra: ¿Son idénticas letra por letra?
        if (palabra1 == palabra2) {
            cout << "Resultado: Las palabras son exactamente iguales." << endl;
        } else {
            cout << "Resultado: Tienen el mismo tamano, pero son palabras diferentes." << endl;
        }
    } 
    else {
        // Caso: Tienen longitudes distintas
        cout << "Las palabras tienen diferentes longitudes." << endl;

        if (tamano1 > tamano2) {
            // palabra1 es más larga (ej: "computadora" vs "sol")
            cout << "La palabra mas larga es: " << palabra1 
                 << " (con " << tamano1 << " letras)." << endl;
        } else {
            // palabra2 es más larga
            cout << "La palabra mas larga es: " << palabra2 
                 << " (con " << tamano2 << " letras)." << endl;
        }
    }

    return 0; // El programa finalizó correctamente
}