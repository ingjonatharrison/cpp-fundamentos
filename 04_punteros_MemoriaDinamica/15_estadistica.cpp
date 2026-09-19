// Ejercicio 10: Programa estadistico mediante argumentos de main
// Uso: estadistica <suma|promedio> <numero1> [numero2 ...]
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

void mostrarUso(const char* programa)
{
    cout << "Uso: " << programa << " <suma|promedio> <numero1> [numero2 ...]\n";
    cout << "Ejemplos:\n";
    cout << "  " << programa << " suma 8 9 10 7\n";
    cout << "  " << programa << " promedio 8 9 10 7\n";
}

int main(int argc, char* argv[])
{
    // Se requiere: programa, operacion y al menos un numero
    if (argc < 3)
    {
        cout << "Error: faltan argumentos.\n";
        mostrarUso(argv[0]);
        return 1;
    }

    string operacion = argv[1];
    if (operacion != "suma" && operacion != "promedio")
    {
        cout << "Error: operacion desconocida \"" << operacion << "\".\n";
        mostrarUso(argv[0]);
        return 1;
    }

    double suma = 0.0;
    int cantidad = 0;

    // Procesa desde argv[2] hasta argv[argc - 1]
    for (int i = 2; i < argc; i++)
    {
        try
        {
            size_t posicion = 0;
            string texto = argv[i];
            double valor = stod(texto, &posicion);
            if (posicion != texto.size())
            {
                throw invalid_argument("caracteres extra");
            }
            suma += valor;
            cantidad++;
        }
        catch (const exception&)
        {
            cout << "Error: \"" << argv[i] << "\" no es un numero valido.\n";
            mostrarUso(argv[0]);
            return 1;
        }
    }

    cout << "Operacion: " << operacion << "\n";
    cout << "Cantidad de numeros: " << cantidad << "\n";
    if (operacion == "suma")
    {
        cout << "Resultado (suma): " << suma << "\n";
    }
    else
    {
        cout << "Resultado (promedio): " << suma / cantidad << "\n";
    }

    return 0;
}
