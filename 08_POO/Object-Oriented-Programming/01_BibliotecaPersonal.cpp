#include <iostream>
#include <string>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;
    int paginas;
    bool leido;

    void leer() {
        cout << "Estas leyendo: " << titulo << endl;
    }

    void mostrarInformacion() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }

    void marcarComoLeido() {
        leido = true;
        cout << titulo << " ha sido marcado como leido." << endl;
    }
};

int main() {
    Libro libro1;

    libro1.titulo = "Cien años de soledad";
    libro1.autor = "Gabriel Garcia Marquez";
    libro1.paginas = 417;
    libro1.leido = false;

    libro1.mostrarInformacion();
    libro1.leer();
    libro1.marcarComoLeido();

    return 0;
}