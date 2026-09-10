#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *siguiente;
} Nodo;

Nodo* crearNodo(int valor);
Nodo* insertarInicio(Nodo* lista, int valor);
Nodo* insertarFinal(Nodo* lista, int valor);
Nodo* insertarAntesDe(Nodo* lista, int referencia, int valor);
Nodo* insertarDespuesDe(Nodo* lista, int referencia, int valor);
void recorrerLista(Nodo* lista);
void buscarElemento(Nodo* lista, int valor);

int main() {
    Nodo* lista = NULL;
    int opcion, valor, referencia;

    do {
        printf("\n=== Menu Listas Ligadas ===\n");
        printf("0. Salir\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar antes de referencia\n");
        printf("4. Insertar despues de referencia\n");
        printf("5. Buscar elemento\n");
        printf("6. Mostrar lista\n");
        printf("Opcion: "); scanf("%d", &opcion);

        switch(opcion) {
            case 0: printf("Programa finalizado.\n"); break;
            case 1:
                printf("Valor a insertar al inicio: "); scanf("%d", &valor);
                lista = insertarInicio(lista, valor);
                break;
            case 2:
                printf("Valor a insertar al final: "); scanf("%d", &valor);
                lista = insertarFinal(lista, valor);
                break;
            case 3:
                printf("Valor a insertar: "); scanf("%d", &valor);
                printf("Insertar antes de cual referencia: "); scanf("%d", &referencia);
                lista = insertarAntesDe(lista, referencia, valor);
                break;
            case 4:
                printf("Valor a insertar: "); scanf("%d", &valor);
                printf("Insertar despues de cual referencia: "); scanf("%d", &referencia);
                lista = insertarDespuesDe(lista, referencia, valor);
                break;
            case 5:
                printf("Valor a buscar: "); scanf("%d", &valor);
                buscarElemento(lista, valor);
                break;
            case 6: recorrerLista(lista); break;
            default: printf("Opcion no valida.\n"); break;
        }
    } while(opcion != 0);

    return 0;
}


Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

Nodo* insertarInicio(Nodo* lista, int valor) {
    Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = lista;
    return nuevo;
}

Nodo* insertarFinal(Nodo* lista, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (lista == NULL) { return nuevo; }
    Nodo* actual = lista;
    while (actual->siguiente != NULL) { actual = actual->siguiente; }
    actual->siguiente = nuevo;
    return lista;
}

Nodo* insertarAntesDe(Nodo* lista, int referencia, int valor) {
    if (lista == NULL) { printf("La lista está vacía.\n"); return lista; }
    if (lista->valor == referencia) { return insertarInicio(lista, valor); }
    Nodo* actual = lista;
    while (actual->siguiente != NULL && actual->siguiente->valor != referencia) { actual = actual->siguiente; }
    if (actual->siguiente == NULL) { printf("Referencia no encontrada.\n");
    } else { Nodo* nuevo = crearNodo(valor); nuevo->siguiente = actual->siguiente; actual->siguiente = nuevo; }
    return lista;
}

Nodo* insertarDespuesDe(Nodo* lista, int referencia, int valor) {
    Nodo* actual = lista;
    while (actual != NULL && actual->valor != referencia) { actual = actual->siguiente; }
    if (actual == NULL) { printf("Referencia no encontrada.\n");
    } else { Nodo* nuevo = crearNodo(valor); nuevo->siguiente = actual->siguiente; actual->siguiente = nuevo; }
    return lista;
}

void recorrerLista(Nodo* lista) {
    if (lista == NULL) { printf("La lista está vacía.\n"); return; }
    Nodo* actual = lista;
    while (actual != NULL) { printf("%d -> ", actual->valor); actual = actual->siguiente; }
    printf("NULL\n");
}

void buscarElemento(Nodo* lista, int valor) {
    Nodo* actual = lista;
    while (actual != NULL && actual->valor != valor) { actual = actual->siguiente; }
    if (actual == NULL) { printf("Elemento no encontrado.\n");
    } else { printf("Elemento encontrado: %d\n", actual->valor); }
}