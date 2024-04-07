#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

const int RAIO=49-sqrt(2),DIAMETRO=2*RAIO;
int x,y,z;
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main(){
	system("MODE con cols=161 lines=64");
	z=0;
	while(tecla!='p'){
		for(x=0;x<=DIAMETRO;x++){
			for(y=0;y<=DIAMETRO;y++){
				mgotoxy(x,y);
				if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO)+(z-RAIO)*(z-RAIO))<=RAIO){
					printf("%c",219);
				}else{
					printf(" ");
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
		}
	}
}
