#include <iostream>
using namespace std;

class RelojDigital {
public:
    int hora;
    int minutos;
    int segundos;

    void mostrarHora() {
        cout << hora << ":" << minutos << ":" << segundos << endl;
    }

    void ajustarHora(int nuevaHora, int nuevosMinutos, int nuevosSegundos) {
        hora = nuevaHora;
        minutos = nuevosMinutos;
        segundos = nuevosSegundos;
    }

    void avanzarSegundo() {
        segundos++;

        if (segundos == 60) {
            segundos = 0;
            minutos++;
        }

        if (minutos == 60) {
            minutos = 0;
            hora++;
        }

        if (hora == 24) {
            hora = 0;
        }
    }
};

int main() {
    RelojDigital reloj1;

    reloj1.ajustarHora(16, 35, 59);

    cout << "Hora inicial: ";
    reloj1.mostrarHora();

    reloj1.avanzarSegundo();

    cout << "Despues de avanzar un segundo: ";
    reloj1.mostrarHora();

    return 0;
}