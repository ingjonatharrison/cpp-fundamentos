#include <stdio.h>
#include <windows.h>
#include <time.h>


void estrellitasAleatorias();
void gotoxy(int x,int y);  
void textcolor(int n);  

int main(){
	estrellitasAleatorias();
	return 0;
}

void estrellitasAleatorias(){       
       int num;
       int columna, renglon, i,color, tiempo=200;
       srand(time(0));
       printf ("\n--Cuantas estrellas quieres: ");
       scanf("%d", &num);
       system("cls"); //borra pantalla completa
       for (i=1; i<=num; i++){
       	    textcolor(15);
			gotoxy(1,1); 
			printf("contador %d/%d", i,num);
       	    Sleep(tiempo);//retardo
       		columna = 1+rand()%(80-1+1); //aleatorio para la columna entre 1 y 80
      		renglon = 2+rand()%(24-2 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    Beep(600, 800);
       	    gotoxy(columna, renglon); printf("*");
       }
		    
		
       fflush(stdin);
	   getchar(); //Espera oprimir cualquier tecla        
	   system("cls"); //borra pantalla completa  
    
}



/*********copia esta funcion a tu proyecto. No olvides poner el prototipo de esta funcion***************/
void gotoxy(int x,int y){ //-----------------------------------------------------------------------------------------------------------------
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}  

/*********copia esta funcion a tu proyecto. No olvides poner el prototipo de esta funcion***************/
void textcolor(int n){ //--------------------------------------------------------------------------------------------------------------------
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}

 