#include <iostream>
#include <stdlib.h>

using namespace std;

int Menu();
void funcione_capturarV(int Vector[5]);
void funcion_mostrar_invertida(int Vector[5]);
int funcion_mayor(int Vector[5]);
void funcion_mostrar_matriz(int matriz[3][3]);

int main(){
    int Vector[5] = {0};
    int matriz[3][3]{{1,2,3},{4,5,6},{7,8,9}};
    
    int Aux, Op;
    do{
        Op = Menu();
        switch(Op){
            case 1:
                funcione_capturarV(Vector);
                break;
            case 2:
                funcion_mostrar_invertida(Vector);
                break;
            case 3:
                Aux = funcion_mayor(Vector);
                cout << "El numero mas grande del vector es: " << Aux << endl;
                break;
            case 4:
                funcion_mostrar_matriz(matriz);
                break;
            default:
                cout << "Saliendo del programa..." << endl;
                break;
        }
    } while(Op >= 1 && Op <= 4);
    
    return 0;
}

int Menu(){
    int Op;
    cout << endl << "--------------------------MENU--------------------------" << endl;
    cout << "1.- Llenar el vector" << endl;
    cout << "2.- Mostrar el vector invertido" << endl;
    cout << "3.- Mostrar el dato mayor del vector" << endl;
    cout << "4.- Mostrar Matriz" << endl;
    cout << "Otro: Salir" << endl;
    cout << "Seleccion: ";
    cin >> Op;
    return Op;
}

void funcione_capturarV(int Vector[5]){
    for(int i = 0; i < 5; i++){ 
        cout << "Dame el valor de el dato en la pos [" << i << "]: ";
        cin >> Vector[i];
    }
}

void funcion_mostrar_invertida(int Vector[5]){
    cout << "Vector invertido: ";
    for(int i = 4; i >= 0; i--){ 
        cout << Vector[i] << " ";
    }
    cout << endl;
}

int funcion_mayor(int Vector[5]){
    int Aux = Vector[0]; 
    for(int n = 1; n < 5; n++){
        if(Aux < Vector[n]){
            Aux = Vector[n];
        }
    }
    return Aux;
}

void funcion_mostrar_matriz(int matriz[3][3]){
    cout << "Contenido de la matriz:" << endl;
    for(int n = 0; n < 3; n++){
        for(int i = 0; i < 3; i++){
            cout << matriz[n][i] << "\t";
        }
        cout << endl; 
    }
}