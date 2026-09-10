#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

char c1[30], c2[30], c3[30], c4[30];
int v1, v2, v3, v4, voto;
char repetir;

void captura();
void votar();
void gotoxy(int x, int y);

int main(){
    printf("\nJonathan Rodriguez Ibarra\n");
    srand(time(0));
    captura();
    do{
        votar();
        printf("\nRepetir votación? (s/n): ");
        scanf(" %c", &repetir);
    } while (repetir == 's');
    return 0;
}

void captura(){
    printf("\nNombre candidato 1: "); scanf("%s", c1);
    printf("Nombre candidato 2: "); scanf("%s", c2);
    printf("Nombre candidato 3: "); scanf("%s", c3);
    printf("Nombre candidato 4: "); scanf("%s", c4);
}

void votar(){
    v1 = v2 = v3 = v4 = 0;
    system("cls");
    for (int i = 1; i <= 1500; i++){
        voto = 1 + rand() % 4;
        if (voto == 1) v1++;
        if (voto == 2) v2++;
        if (voto == 3) v3++;
        if (voto == 4) v4++;
        gotoxy(10, 10);
        printf("      %s      %s      %s      %s     ", c1, c2, c3, c4);
        gotoxy(11, 11);
        printf("     %d     %d     %d     %d   ", v1, v2, v3, v4);
        Sleep(5);
    }
    char nombres[4][30];
    int votos[4];
    strcpy(nombres[0], c1); votos[0] = v1;
    strcpy(nombres[1], c2); votos[1] = v2;
    strcpy(nombres[2], c3); votos[2] = v3;
    strcpy(nombres[3], c4); votos[3] = v4;
    // Ordenamiento burbuja
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
            if (votos[j] > votos[i]){
                int temp = votos[i];
                votos[i] = votos[j];
                votos[j] = temp;
                char aux[30];
                strcpy(aux, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], aux);
            }
        }
    }
    printf("\n\nResultados:\n");
    for (int i = 0; i < 4; i++){
        float porcentaje = (votos[i] * 100.0) / 1500.0;
        printf("%d. %s - %d votos (%.2f%%)\n", i + 1, nombres[i], votos[i], porcentaje);
    }
    printf("\nGanador: %s\n", nombres[0]);
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}