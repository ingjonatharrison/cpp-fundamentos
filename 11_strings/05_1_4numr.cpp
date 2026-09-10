#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int NumeroRand();
void VerificarYReto(int Aux, int &cont);
void OperacionAleatoria(int &cont);

int main(){
    int Aux, cont = 0; 
    string Name;
    float est;
    srand(time(NULL));
    
    cout << "Dame tu nombre: ";
    cin >> Name;
    cout << "Dame tu estatura en mts: ";
    cin >> est;
    
    cout << "--- Bienvenido " << Name << " de estatura " << est << " ---" << endl;
    cout << "--- DESAFIO ---" << endl;
    
    do {
        Aux = NumeroRand();
        VerificarYReto(Aux, cont);
        
        cout << "Puntaje actual: " << cont << endl << "-------" << endl;
        
        if(cont >= 3) {
            cout << "FELICIDADES! Has alcanzado los 10 puntos Ganaste!!" << endl;
            break;
        }
    } while(cont > -1);
    cout << "Jugador " << Name << " de estatura" << est << endl;
    
    if(cont <= -1) {
        cout << "HAS PERDIDO! Has perdido todos tus puntos" << endl;
    }
    
    return 0;
}

int NumeroRand(){
    return 1 + rand() % 10;
}

void VerificarYReto(int Aux, int &cont){
    int num;
    cout << "Adivina el numero secreto (1 al 10): ";
    cin >> num;
    
    if(Aux == num){
        cout << "Es correcto! Pero para ganar el punto, resuelve la siguiente operacion:" << endl;
        OperacionAleatoria(cont);
    } else {
        cout << "Incorrecto! El numero era: " << Aux << endl;
        cout << "Resuelve esto correctamente para NO perder un punto:" << endl;

        int puntosAntes = cont;
        OperacionAleatoria(cont);
        cont--;
    }
}

void OperacionAleatoria(int &cont){
    int a = 1 + rand() % 10;
    int b = 1 + rand() % 10;
    int respuesta;
    
    cout << "Cuanto es " << a << " + " << b << "? ";
    cin >> respuesta;
    
    if(respuesta == (a + b)){
        cout << "Operacion correcta!" << endl;
        cont++; 
    } else {
        cout << "Operacion incorrecta!" << endl;
    }
}