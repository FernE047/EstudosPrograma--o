#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

const int RAIO=9-sqrt(2),DIAMETRO=2*RAIO;
int x,y,z,w;
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(){
	z=0;
	w=0;
	while(tecla!='p'){
		for(x=0;x<=DIAMETRO;x++){
			for(y=0;y<=DIAMETRO;y++){
				mgotoxy(x,y);
				if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO)+(z-RAIO)*(z-RAIO)+(w-RAIO)*(w-RAIO))<=RAIO){
					printf("%c",219);
				}else{
					printf(" ");					
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
			case 'd':
				if(w<DIAMETRO)w++;
			break;
			case 'a':
				if(w>0)w--;
			break;
		}
	}
}
