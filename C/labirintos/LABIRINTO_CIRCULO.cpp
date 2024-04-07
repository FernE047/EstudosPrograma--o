#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#define DIAMETRO 48	//MAXIMO 159, MINIMO 5 e preferencialmente valores impares

short int controle_de_base=0;				//controle de base
const int base=((DIAMETRO-1)/2)*((DIAMETRO-1)/2),RAIO=DIAMETRO/2;  // pseudo-constantes
short int x,y,direcao,x_curvas[base],y_curvas[base],himym,teste_de_cont; //criação do labirinto
short int lab[DIAMETRO+1][DIAMETRO],x_fim,y_fim;			//labirinto manipulavel
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int sera(){
	if ((lab[x+2][y]==0)or(x==DIAMETRO-1)){
		if((lab[x-2][y]==0)or(x==2)){
			if((lab[x][y+2]==0)or(y==DIAMETRO-2)){
				if((lab[x][y-2]==0)or(y==1)){
					return(0);
				}else{
					return(1);
				}
			}else{
				return(1);
			}
		}else{
			return(1);
		}
	}else{
		return(1);
	}
}

int main(){
	srand(time(NULL));
	system("MODE con cols=161 lines=55");
	for(x=0;x<=DIAMETRO;x++){
		for(y=0;y<=DIAMETRO;y++){
			if(sqrt((x-RAIO)*(x-RAIO)+(y-RAIO)*(y-RAIO))<=RAIO){
				lab[x][y]=219;
			}
		}	
	}
    for(himym=0;himym<base;himym++){
    	x_curvas[himym]=0;
    	y_curvas[himym]=0;
	}
	x=RAIO;
	y=2;
    lab[x][y]=0;
	x_curvas[0]=x;
	y_curvas[0]=y;
	do{
		x=x_curvas[controle_de_base];
		y=y_curvas[controle_de_base];
		while(sera()){
			teste_de_cont=0;
			while(teste_de_cont==0){									
				switch(direcao=((rand()%4)+1)){
					case 1:									//direita
						if(x==(DIAMETRO-1)){
							teste_de_cont=0;
						}else if(lab[x+2][y]!=0){
							teste_de_cont=1;
							x++;
        					lab[x][y]=0;
							x++;
        					lab[x][y]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 2:									//baixo
						if(y==(DIAMETRO-2)){
							teste_de_cont=0;
						}else if(lab[x][y+2]!=0){
							teste_de_cont=1;
							y++;
							lab[x][y]=0;
							y++;
							lab[x][y]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 3:									//esquerda
						if(x==2){
							teste_de_cont=0;
						}else if(lab[x-2][y]!=0){
							teste_de_cont=1;
							x--;
        					lab[x][y]=0;
							x--;
        					lab[x][y]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 4:									//cima
						if(y==1){
							teste_de_cont=0;
						}else if(lab[x][y-2]!=0){
							teste_de_cont=1;
							y--;
        					lab[x][y]=0;
							y--;
        					lab[x][y]=0;
						}else{
							teste_de_cont=0;
						}
					break;
				}
			}
			controle_de_base++;
			x_curvas[controle_de_base]=x;
			y_curvas[controle_de_base]=y;
		}
		controle_de_base=controle_de_base-1;
	}while(controle_de_base!=0);
    for(y=0;y<DIAMETRO;y++)
    {
    	for(x=1;x<(DIAMETRO+1);x++)
    	{
			mgotoxy(x,y);
        	printf("%c",lab[x][y]);
    	}
    }
    himym=1;
    controle_de_base=base;
    while(himym==1){
    	if((x_curvas[controle_de_base]>1)and(y_curvas[controle_de_base]>1)){
    		himym=0;
    		x_fim=x_curvas[controle_de_base];
    		y_fim=y_curvas[controle_de_base];
    		mgotoxy(x_fim,y_fim);
    		printf("S");
		}    	
		controle_de_base--;
	}
	x=RAIO;
	y=2;
	mgotoxy(x,y);
	printf("C");
	himym=0;
	while(not((x==x_fim)and(y==y_fim))){
		tecla=getch();
		switch(tecla){
		case'H':					//cima
			if (lab[x][y-1]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				y--;
				mgotoxy(x,y);
				printf("%c",30);
			}
		break;
		case'M':					//direita
			if (lab[x+1][y]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				x++;
				mgotoxy(x,y);
				printf("%c",16);
			}
		break;
		case'P':					//baixo
			if (lab[x][y+1]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				y++;
				mgotoxy(x,y);
				printf("%c",31);
			}
		break;
		case'K':					//esquerda
			if (lab[x-1][y]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				x--;
				mgotoxy(x,y);
				printf("%c",17);
			}
		break;
		}
	}
}
