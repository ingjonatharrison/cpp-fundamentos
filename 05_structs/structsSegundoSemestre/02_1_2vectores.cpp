#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

/*
FUNCIONES

1 Multiplicar un vector por un escalar
2 Multiplicar dos vectores
3 Sume el contenido del vector
4 ordenar el vector de menor a mayor

*/
void llenarVector(int vec[], int n);
void mostrarVector(int vec[], int n);
void mostrarVectorAleatorio(int vec[], int n);
int buscarElemento(int vec[], int n, int elemento);

int main(){
	int n, elemento, posicion;
	cout<<"ingrese el tamaño del vector: ";
	cin>>n;
	int vec[n];
	int opcion;
	do{
		cout << "\n--- Seleccione una opcion ---" << endl;
	    cout << "1.- Llenar manualmente" << endl;
	    cout << "2.- Llenar con numeros aleatorios (50-70)" << endl;
	    cout << "3.- Mostrar vector" << endl;
	    cout << "4.- Buescar elemento" << endl;
	    cout << "5.- Salir" << endl;
	    cout << "Ingrese una opcion: ";
	    cin>>opcion;
	    switch(opcion){
	    	case 1:
	    		llenarVector(vec, n);
	    		cout<<"Vector llenado manualmente"<<endl;
	    		break;
	    	case 2:
	    		mostrarVectorAleatorio(vec, n);
	    		cout<<"Vector llenado con numeros aleatorios"<<endl;
	    		break;
	    	case 3:
	    		mostrarVector(vec, n);
	    		break;
	    	case 4:
	    		cout<<"Ingrese el elemento a buscar: "<<endl;
	    		cin>>elemento;
	    		posicion=buscarElemento(vec, n, elemento);
	    		if(posicion!=-1)
	    			cout<<"Elemento encontrado en la posicion: "<<posicion<<endl;
	    		else
	    			cout<<"Elemento no encontrado en el vector"<<endl;
	    		break;
	    	case 5:
	    		cout<<"Saliendo, gracias por usar el programa!!"<<endl;
	    		break;
	    	default:
	    		
	    		break;
		}
	}while(opcion!=5);
    return 0;
}

void llenarVector(int vec[], int n){
    for(int i=0; i<n; i++){
        cout<<"Ingrese el elemento"<<i+1<<": ";
        cin>>vec[i];
    }
}

void mostrarVector(int vec[], int n){
	cout<<"elemenos del vector: "<<endl;
	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

void mostrarVectorAleatorio(int vec[], int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        vec[i]=50+(rand()%21);//numeros entre 50 y 70
    }
}

int buscarElemento(int vec[], int n, int elemento){
	for(int i=0; i<n; i++){
		if(vec[i]==elemento)
			return i;
	}
	return -1;
}

/*MODO SENIOR

#include <iostream>  // Librería para entrada (cin) y salida (cout) de datos
#include <vector>    // Contenedor dinámico (la versión moderna y segura de los arrays)
#include <ctime>     // Para obtener la hora del sistema (usada en la semilla del azar)
#include <cstdlib>   // Para funciones de azar: rand() y srand()

using namespace std; // Evita escribir 'std::' antes de cada comando de la librería estándar

// PROTOTIPOS: Avisamos al compilador que estas funciones existen más abajo
// Usamos '&' (referencia) para no copiar el vector completo, sino trabajar sobre el original
void llenarVector(vector<int>& vec);
void mostrarVector(const vector<int>& vec); // 'const' porque esta función no debe modificar el vector
void llenarAleatorio(vector<int>& vec);
int buscarElemento(const vector<int>& vec, int elemento);

int main() {
    int n, elemento, posicion, opcion; // Declaración de variables de control
    
    // Inicializa el generador de números aleatorios basándose en la hora actual
    // Se hace UNA SOLA VEZ para que los números cambien en cada ejecución
    srand(time(NULL)); 

    cout << "Ingrese el tamaño del vector: ";
    cin >> n; // Captura el tamaño deseado por el usuario

    // Creamos el vector llamado 'vec' con 'n' espacios de tipo entero (int)
    // A diferencia de 'int vec[n]', esto es memoria dinámica segura
    vector<int> vec(n); 

    do {
        // Menú visual para el usuario
        cout << "\n--- MENÚ DE CONTROL ---" << endl;
        cout << "1.- Llenar manualmente\n2.- Llenar aleatorio (50-70)\n3.- Mostrar\n4.- Buscar\n5.- Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion; // Captura la decisión del usuario

        switch(opcion) {
            case 1: 
                llenarVector(vec); // Llamada a función para entrada manual
                break;
            case 2: 
                llenarAleatorio(vec); // Llamada a función para azar
                cout << "Vector generado con éxito." << endl;
                break;
            case 3: 
                mostrarVector(vec); // Llamada a función de impresión
                break;
            case 4:
                cout << "Elemento a buscar: ";
                cin >> elemento;
                posicion = buscarElemento(vec, elemento); // Guardamos el índice devuelto
                
                // Operador ternario (un if/else simplificado)
                // Si posicion no es -1, imprime el índice; si es -1, imprime que no existe
                (posicion != -1) ? cout << "Encontrado en indice: " << posicion << endl 
                                 : cout << "Elemento no encontrado." << endl;
                break;
            case 5:
                cout << "Cerrando programa..." << endl;
                break;
            default:
                cout << "Opción inválida, intente de nuevo." << endl;
        }
    } while(opcion != 5); // El bucle se repite mientras el usuario no elija salir

    return 0; // Indica al sistema operativo que el programa terminó correctamente
}

// DEFINICIÓN DE FUNCIONES

void llenarVector(vector<int>& vec) {
    // .size() nos da el tamaño real del vector sin necesidad de otra variable
    for(size_t i = 0; i < vec.size(); i++) {
        cout << "Ingrese valor para posicion [" << i << "]: ";
        cin >> vec[i]; // Guarda el dato directamente en la memoria del vector
    }
}

void mostrarVector(const vector<int>& vec) {
    cout << "\n[ ";
    // Bucle 'for-each' (C++11): "Para cada entero 'x' que esté dentro de 'vec'..."
    for(int x : vec) {
        cout << x << " "; // Imprime el valor seguido de un espacio
    }
    cout << "]" << endl;
}

void llenarAleatorio(vector<int>& vec) {
    // Usamos '&x' para modificar el valor real dentro del vector mientras lo recorremos
    for(int &x : vec) {
        // Genera número entre 50 y 70: rand() % (max - min + 1) + min
        x = 50 + (rand() % 21);
    }
}

int buscarElemento(const vector<int>& vec, int elemento) {
    // Recorrido secuencial clásico
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i] == elemento) { // Si el valor en la posición i es igual al buscado...
            return i; // ...devuelve el índice y corta la función
        }
    }
    return -1; // Si termina el ciclo y no encontró nada, devuelve -1 (error)
}

*/