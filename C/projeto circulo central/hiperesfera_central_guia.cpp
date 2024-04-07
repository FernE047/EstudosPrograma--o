#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define RAIO 25

const int DIAMETRO=2*RAIO,RAION=sqrt(4*(RAIO*RAIO))-RAIO;
int x,y,z,w;
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(){
	system("MODE con cols=161 lines=64");
	z=0;
	while(tecla!='p'){
		system("cls");
		for(x=0;x<=DIAMETRO;x++){
			for(y=0;y<=DIAMETRO;y++){
				mgotoxy(x,y);
				if(sqrt(x*x+y*y+z*z+w*w)<=RAIO){
					printf("1");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+z*z+w*w)<=RAIO){
					printf("2");
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+z*z+w*w)<=RAIO){
					printf("3");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+z*z+w*w)<=RAIO){
					printf("4");
				}
				if(sqrt(x*x+y*y+(z-DIAMETRO)*(z-DIAMETRO)+w*w)<=RAIO){
					printf("5");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+(z-DIAMETRO)*(z-DIAMETRO)+w*w)<=RAIO){
					printf("6");
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO)+w*w)<=RAIO){
					printf("7");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO)+w*w)<=RAIO){
					printf("8");
				} 
				if(sqrt(x*x+y*y+z*z+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("9");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+z*z+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("0");
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+z*z+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("A");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+z*z+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("B");
				}
				if(sqrt(x*x+y*y+(z-DIAMETRO)*(z-DIAMETRO)+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("C");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+y*y+(z-DIAMETRO)*(z-DIAMETRO)+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("D");
				}
				if(sqrt(x*x+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO)+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("E");
				}
				if(sqrt((x-DIAMETRO)*(x-DIAMETRO)+(y-DIAMETRO)*(y-DIAMETRO)+(z-DIAMETRO)*(z-DIAMETRO)+(w-DIAMETRO)*(w-DIAMETRO))<=RAIO){
					printf("F");
				}
				if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO)+(z-RAIO)*(z-RAIO)+(w-RAIO)*(w-RAIO))<=RAION){
					printf("%c",219);
				}
			}	
		}
		printf("\nz:%d   ",z);
		printf("\nw:%d   ",w);
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
			case 'd':
				if(w<DIAMETRO)w++;
			break;
			case 'a':
				if(w>0)w--;
			break;
			case 'D':
				if(w<DIAMETRO)w++;
			break;
			case 'A':
				if(w>0)w--;
			break;
		}
	}
}
