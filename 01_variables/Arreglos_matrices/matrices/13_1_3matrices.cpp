#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

void LlenarManual(int Mat[100][100], int N, int M);
void LlenarAleatorio(int Mat[100][100], int N, int M);
void mostrarMatriz(int Mat[100][100], int N, int M);
void cuboMagico(int Mat[100][100], int N, int M);

int main(){
	int Mat[100][100];
	int N,M,dato,opcion;	
	cout << "Ingrese el numero de filas" << endl;
	cin >> N;
	cout << "Ingrese el numero de columnas" << endl;
	cin >> M;
	do{
		cout << "-----------MENU----------" << endl;
		cout << "1.- Llenar de manera manual" << endl;
		cout << "2.- Llenar de manera aleatoria" << endl;
		cout << "3.- Mostrar la matriz" << endl;
		cout << "4.- Cubo magico" << endl;
		cout << "5.- Salir" << endl;
		cout << "OPCION: ";
		cin >> opcion;
		switch(opcion){
			case 1:
				LlenarManual(Mat, N, M);
				break;
			case 2:
				LlenarAleatorio(Mat, N, M);
				break;
			case 3:
				mostrarMatriz(Mat, N, M);
				break;
			case 4:
				cuboMagico(Mat, N, M);
				break;
			case 5:
				cout << "Saliendo del programa" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
		}
	}while(opcion!=5);
	return 0;
}

void LlenarManual(int Mat[100][100], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Mat[" << i << "][" << j << "]: ";
            cin >> Mat[i][j];
        }
    }
}

void LlenarAleatorio(int Mat[100][100], int N, int M) {
	srand(time(NULL));
	for (int fila=0; fila<N; fila++) {
		for (int col=0; col<M; col++) {
			Mat[fila][col]=rand();
		}
	}
}

void mostrarMatriz(int Mat[100][100], int N, int M) {
    int sumaColumnas[100] = {0};
    int sumaPrincipal = 0;
    int sumaSecundaria = 0;

    cout << "\n--- MATRIZ ACTUAL ---" << endl;

    for (int fila = 0; fila < N; fila++) {
        int sumaFila = 0;
        for (int col = 0; col < M; col++) {
            cout << "[" << Mat[fila][col] << "]\t";
            sumaFila += Mat[fila][col];
            sumaColumnas[col] += Mat[fila][col];
            if (N == M) {
                if (fila == col) sumaPrincipal += Mat[fila][col];
                if (fila + col == N - 1) sumaSecundaria += Mat[fila][col];
            }
        }
        cout << "| Suma Fila: " << sumaFila << endl;
    }
    for (int j = 0; j < M; j++) cout << "---------";
    cout << endl;
    for (int j = 0; j < M; j++) {
        cout << "  S:" << sumaColumnas[j] << "\t";
    }
    cout << "  <- Sumas Col" << endl;
    if (N == M) {
        cout << "\nDiagonal Principal: " << sumaPrincipal << endl;
        cout << "Diagonal Secundaria: " << sumaSecundaria << endl;
    }
    cout << "---------------------\n" << endl;
}

void cuboMagico(int Mat[100][100], int N, int M) {
    if (N != M) {
        cout << "Error: El numero de filas y columnas debe ser igual" << endl;
        return;
    }

    if (N % 2 != 0) {
        cout << "Guardando datos del cubo magico..." << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Mat[i][j] = 0;
            }
        }
        int fila = 0;
        int col = N / 2;
        for (int k = 1; k <= N * N; k++) {
            Mat[fila][col] = k;
            int f_ant = fila;
            int c_ant = col;
            fila--;
            col++;
            if (fila < 0) fila = N - 1;
            if (col >= N) col = 0;     
            if (Mat[fila][col] != 0) {
                fila = f_ant + 1;
                col = c_ant;
            }
        }
        cout << "Cubo generado con exito! Seleccione la opcion 3 para verlo" << endl;
    } 
    else {
        cout << N << " Es un numero par Solo se aceptan impares" << endl;
    }
}
