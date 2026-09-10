#include <iostream>
using namespace std;
// Eliminamos <dos.h> porque ya no es necesario para esto
int main(int argc, char* argv[]) {
    // Usamos argc y argv (sin el guion bajo)
    cout << "Se han pasado " << argc << " argumentos:" << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "  " << i << " - " << argv[i] << endl;
    }
    return 0;
}