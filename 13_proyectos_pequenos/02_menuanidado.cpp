#include <stdio.h>

/* Prototipos */
void menuPrincipal(void);
void menuAcciones(void);

int main() {
    /* Punto de arranque */
    menuPrincipal();
    return 0;
}

/* ================= MEN� PRINCIPAL ================= */
void menuPrincipal(void) {
    int opcion;

    do {
        printf("\n===== Sistema de Biblioteca =====\n");
        printf("1. Ingresar al sistema\n");
        printf("2. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
        case 1:
            menuAcciones();   // Llama al men� secundario
            break;
        case 2:
            printf("\nCerrando sistema...\n");
            break;
        default:
            printf("Opcion no valida en el menu principal.\n");
        }

    } while(opcion != 2);
}

/* ================= MEN� SECUNDARIO ================= */
void menuAcciones(void) {
    char opcion;

    do {
        printf("\n--- Acciones de Biblioteca ---\n");
        printf("a) Registrar libro\n");
        printf("b) Prestar libro\n");
        printf("c) Consultar disponibilidad\n");
        printf("d) Salir al menu principal\n");
        printf("Elige una opcion: ");
        scanf(" %c", &opcion);   // el espacio evita capturar ENTER

        switch(opcion) {
        case 'a': case 'A':
            printf("Elegiste Registrar libro.\n");
            break;
        case 'b': case 'B':
            printf("Elegiste Prestar libro.\n");
            break;
        case 'c': case 'C':
            printf("Elegiste Consultar disponibilidad.\n");
            break;
        case 'd': case 'D':
            printf("Regresando al menu principal...\n");
            break;
        default:
            printf("Opcion no valida en acciones.\n");
        }

    } while(opcion != 'd' && opcion != 'D');
}
