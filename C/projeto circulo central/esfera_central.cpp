#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define RAIO 25

const int DIAMETRO=2*RAIO,RAION=sqrt(3*(RAIO*RAIO))-RAIO;
int x,y,z=0;
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(){
	system("MODE con cols=161 lines=64");
	while(tecla!='p'){
		system("cls");
		for(x=0;x<=DIAMETRO;x++){
			for(y=0;y<=DIAMETRO;y++){
				mgotoxy(x,y);
				if(sqrt(x*x+y*y+z*z)<=RAIO){
					printf("%c",219);
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+z*z)<=RAIO){
					printf("%c",219);
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+z*z)<=RAIO){
					printf("%c",219);
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+z*z)<=RAIO){
					printf("%c",219);
				}
				if(sqrt(x*x+y*y+(z-DIAMETRO)*(z-DIAMETRO))<=RAIO){
					printf("%c",219);
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+(z-DIAMETRO)*(z-DIAMETRO))<=RAIO){
					printf("%c",219);
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO))<=RAIO){
					printf("%c",219);
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO))<=RAIO){
					printf("%c",219);
				}
				if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO)+(z-RAIO)*(z-RAIO))<=RAION){
					printf("%c",219);
				}
			}	
		}
		printf("\nz:%d   ",z);
		tecla=getch();
		switch(tecla){
			case 'w':
				if(z<DIAMETRO)z++;
			break;
			case 's':
				if(z>0)z--;
			break;
			case 'W':
				if(z<DIAMETRO)z++;
			break;
			case 'S':
				if(z>0)z--;
			break;
		}
	}
}
