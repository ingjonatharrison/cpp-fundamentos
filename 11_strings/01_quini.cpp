#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nom[5][20] = {"Luis","Ana","Fernanda","Enrique","Carlos"};
char nomAux[20];
int saldo[5] = {5000,7000,9000,4000,2500};
int opc, pos, cant;

void proceso();
void ResFIn();

int main(){
    do{
        printf( "\nCAJERO\n1) Ingresar cliente\n2) Salir\n" );
        scanf("%d", &opc);
        fflush(stdin);
        if(opc == 1){
			proceso();
        }
    } while(opc != 2);
	ResFIn();
    return 0;
}

void proceso(){
    do{
        printf("\nIngresa tu nombre cliente: ");
        scanf("%s", nomAux);
        fflush(stdin);
        pos = -1;  
        for(int i = 0; i < 5; i++){
            if(strcmp(nomAux, nom[i]) == 0){
                pos = i;  // guardamos la posición del cliente
                break;
            }
        }
        if(pos == -1){
            printf("\nCliente NO encontrado\n");
        } else {
            printf("\nBienvenido %s\n", nom[pos]);
        }
    } while(pos == -1);
    
    int op2;
    do{
        printf("\nOPERACIONES\n1) Deposito\n2) Retiro\n3) Saldo\n4) Salir\n");
        scanf("%d", &op2);
        fflush(stdin);
        if(op2 == 1){
            do{
                printf("\nCantidad a depositar (múltiplo de 100): ");
                scanf("%d", &cant);
                if(cant % 100 != 0) printf("Ingrese un monto múltiplo de 100.\n");
            } while(cant % 100 != 0);
                    saldo[pos] += cant;      
                    printf("Depósito exitoso. Nuevo saldo: %d\n", saldo[pos]);
        }

        else if(op2 == 2){
            do{
                printf("\nCantidad a retirar (min 100, max 8000, múltiplo de 100): ");
                scanf("%d", &cant);
                if(cant > saldo[pos])
                    printf("Fondos insuficientes.\n");
                else if(cant % 100 != 0)
                    printf("Debe ser múltiplo de 100.\n");
                else if(cant < 100 || cant > 8000)
                    printf("Monto fuera de rango.\n");
            } while(cant > saldo[pos] || cant % 100 != 0 || cant < 100 || cant > 8000);
            int monto = cant;
            int temp = monto;

            printf("\nBilletes 1000: %d", temp / 1000);
            temp %= 1000;
            printf("\nBilletes 500: %d", temp / 500);
            temp %= 500;
            printf("\nBilletes 200: %d", temp / 200);
            temp %= 200;
            printf("\nBilletes 100: %d\n", temp / 100);
            saldo[pos] -= monto;
            printf("Retiro exitoso. Nuevo saldo: %d\n", saldo[pos]);
        }
        
        else if(op2 == 3){
            printf("\nCliente: %s  Saldo: %d\n", nom[pos], saldo[pos]);
        }
    } while(op2 != 4);  // Salir del submenú
}

void ResFIn(){
    printf("\nSaldos finales:\n");
    for(int i=0; i<5; i++){
        printf("%s - %d\n", nom[i], saldo[i]);
    }
}