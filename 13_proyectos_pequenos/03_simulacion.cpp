#include <stdio.h>
#include <windows.h>
#include <time.h>

//prototipos
void simulacion();
void imprimir();
void gotoxy(int x,int y);  
void textcolor(int n);  

int f1=30, f2=20, f3=50;  //variables globales

int main(){
	srand(time(0));
	simulacion();
	return 0;
}

void simulacion(){     
    int n,z;
    gotoxy(20,5); printf("Fila#1");
    gotoxy(40,5); printf("Fila#2");
    gotoxy(60,5); printf("Fila#3");
    imprimir();
    
    for (int k=1; k<100; k++){
    	gotoxy(20,3); printf("%d/100",k);
       	n=1+rand()%(3-1+1);
       	z=0+rand()%(1-0+1);
       	switch(n){
       	    case 1: if (z==0)
			           f1--;
					else
					   f1++;
					break;  
			case 2: if (z==0)
			           f2--;
					else
					   f2++;
					break;
			case 3: if (z==0)
			           f3--;
					else
					   f3++;
					break;    		    		    	
	    }//fin switch
	    imprimir();    	
	}//fin for
    
}//fin simulacion

void imprimir(){
	Sleep(400);
	gotoxy(20,7); printf("%d",f1);
    gotoxy(40,7); printf("%d",f2);
    gotoxy(60,7); printf("%d",f3);
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

 