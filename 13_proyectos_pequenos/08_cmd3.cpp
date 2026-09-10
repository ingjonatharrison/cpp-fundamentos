#include <iostream> // Biblioteca estándar para entrada y salida de datos
#include <string>   // Biblioteca para el manejo de cadenas de texto y stoi()

using namespace std;

/**
 * Función principal del programa.
 * @param argc (Argument Count): Contador de argumentos pasados por consola.
 * @param argv (Argument Vector): Arreglo de cadenas que contiene los argumentos.
 * argv[0] es siempre el nombre del programa ejecutable.
 */
int main(int argc, char* argv[]) {

    // 1. VALIDACIÓN: Se esperan 4 argumentos (el nombre del programa + 3 datos)
    // Ejemplo: ./programa suma 5 10
    if (argc != 4) {
        cout << "Error: Uso incorrecto del programa." << endl;
        cout << "Formato: <operacion (suma/multiplicacion)> <numero1> <numero2>" << endl;
        cout << "Argumentos detectados: " << argc - 1 << endl;
        return 1; // Retorna 1 indicando que el programa terminó con error
    }

    // 2. EXTRACCIÓN Y CONVERSIÓN DE DATOS
    // Los argumentos vienen como texto (string), debemos procesarlos:
    string operacion = argv[1]; // El primer argumento después del nombre es la operación
    
    // stoi (String To Integer) convierte la cadena de texto a un valor entero
    int a = stoi(argv[2]); 
    int b = stoi(argv[3]);

    // 3. LÓGICA DE OPERACIÓN
    // Comprobamos la operación ignorando si la primera letra es mayúscula o minúscula
    if (operacion == "suma" || operacion == "Suma") {
        cout << "\nResultado de la suma:" << endl;
        cout << a << " + " << b << " = " << a + b << endl;
    } 
    else if (operacion == "multiplicacion" || operacion == "Multiplicacion") {
        cout << "\nResultado de la multiplicacion:" << endl;
        cout << a << " x " << b << " = " << a * b << endl;
    } 
    // 4. MANEJO DE ERRORES DE USUARIO
    else {
        cout << "Error: Operacion '" << operacion << "' no reconocida." << endl;
    }    

    return 0; // El programa finalizó correctamente
}