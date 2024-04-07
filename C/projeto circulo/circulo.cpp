#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define RAIO 25

const int DIAMETRO=2*RAIO;
int x,y;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(){
	system("MODE con cols=161 lines=64");
	for(x=0;x<=DIAMETRO;x++){
		for(y=0;y<=DIAMETRO;y++){
			mgotoxy(x,y);
			if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO))<=RAIO){
				printf("%c",219);
			}
		}	
	}
}
