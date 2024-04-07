#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define LARGURA 5		//MAXIMO 159, MINIMO 5 e preferencialmente valores impares
#define ALTURA 5		//MAXIMO 49, MINIMO 5 e preferencialmente valores impares
#define PROFUNDIDADE 5	//MAXIMO 99, MINIMO 5 e preferencialmente valores impares

short int controle_de_base=0;				//controle de base
const int base=(PROFUNDIDADE*ALTURA*LARGURA-PROFUNDIDADE*ALTURA-PROFUNDIDADE*LARGURA+PROFUNDIDADE-ALTURA*LARGURA+ALTURA+LARGURA-1)/8;
short int x,y,z,direcao,x_curvas[base],y_curvas[base],z_curvas[base],himym,teste_de_cont; //criação do labirinto
short int lab[LARGURA+1][ALTURA+1][PROFUNDIDADE+1],x_fim,y_fim,z_fim;			//labirinto manipulavel
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int zescreve(){
    for(y=0;y<ALTURA;y++)
    {
    	for(x=1;x<(LARGURA+1);x++)
    	{
			mgotoxy(x,y);
        	printf("%c",lab[x][y][z]);
    	}
    }
    if(z==z_fim){
		mgotoxy(x_fim,y_fim);
		printf("S");
    }
    if(z==1){
		mgotoxy(2,1);
		printf("C");
    }
}

int sera(){
	if ((lab[x+2][y][z]!=0)or(x==LARGURA-1)){
		if((lab[x-2][y][z]!=0)or(x==2)){
			if((lab[x][y+2][z]!=0)or(y==ALTURA-2)){
				if((lab[x][y-2][z]!=0)or(y==1)){
					if((lab[x][y][z+2]!=0)or(z==PROFUNDIDADE-2)){
						if((lab[x][y][z-2]!=0)or(z==1)){
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
		}else{
			return(1);
		}
	}else{
		return(1);
	}
}

int main(){
	srand(time(NULL));
    for(y=0;y<ALTURA;y++)
    {
    	for(x=1;x<(LARGURA+1);x++)
    	{
    		for(z=0;z<PROFUNDIDADE;z++)
    		{
    	   	 	lab[x][y][z]=219;
    		}
    	}
    }
    for(himym=0;himym<base;himym++){
    	x_curvas[himym]=0;
    	y_curvas[himym]=0;
    	z_curvas[himym]=0;
	}
	x=2;
	y=1;
	z=1;
    lab[x][y][z]=0;
	x_curvas[0]=x;
	y_curvas[0]=y;
	z_curvas[0]=z;
	do{
		x=x_curvas[controle_de_base];
		y=y_curvas[controle_de_base];
		z=z_curvas[controle_de_base];
		while(sera()){
			teste_de_cont=0;
			while(teste_de_cont==0){
				switch(direcao=((rand()%6)+1)){
					case 1:									//direita
						if(x==(LARGURA-1)){
							teste_de_cont=0;
						}else if(lab[x+2][y][z]==0){
							teste_de_cont=1;
							x++;
        					lab[x][y][z]=0;
        					x++;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 2:									//baixo
						if(y==(ALTURA-2)){
							teste_de_cont=0;
						}else if(lab[x][y+2][z]==0){
							teste_de_cont=1;
							y++;
        					lab[x][y][z]=0;
        					y++;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 3:									//esquerda
						if(x==2){
							teste_de_cont=0;
						}else if(lab[x-2][y][z]==0){
							teste_de_cont=1;
							x--;
        					lab[x][y][z]=0;
							x--;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 4:									//cima
						if(y==1){
							teste_de_cont=0;
						}else if(lab[x][y-2][z]==0){
							teste_de_cont=1;
							y--;
        					lab[x][y][z]=0;
							y--;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 5:									//tras
						if(z==1){
							teste_de_cont=0;
						}else if(lab[x][y][z-2]==0){
							teste_de_cont=1;
							z--;
        					lab[x][y][z]=0;
							z--;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 6:									//frente
						if(z==(PROFUNDIDADE-2)){
							teste_de_cont=0;
						}else if(lab[x][y][z+2]==0){
							teste_de_cont=1;
							y++;
        					lab[x][y][z]=0;
							y++;
        					lab[x][y][z]=0;
						}else{
							teste_de_cont=0;
						}
					break;
				}
			}
			controle_de_base++;
			x_curvas[controle_de_base]=x;
			y_curvas[controle_de_base]=y;
			z_curvas[controle_de_base]=z;
		}
		controle_de_base--;
	}while(controle_de_base!=0);
    himym=1;
    controle_de_base=base;
    while(himym==1){
    	if((x_curvas[controle_de_base]!=0)and(y_curvas[controle_de_base]!=0)and(z_curvas[controle_de_base]!=0)){
    		himym=0;
    		x_fim=x_curvas[controle_de_base];
    		y_fim=y_curvas[controle_de_base];
    		z_fim=z_curvas[controle_de_base];
		}
		controle_de_base--;
	}
	x=2;
	y=1;
	z=1;
	himym=0;
	zescreve();
	while(not((x==x_fim)and(y==y_fim)and(z==z_fim))){
		tecla=getch();
		switch(tecla){
		case'H':					//cima
			if (lab[x][y-1][z]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				y--;
				mgotoxy(x,y);
				printf("%c",30);
			}
		break;
		case'M':					//direita
			if (lab[x+1][y][z]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				x++;
				mgotoxy(x,y);
				printf("%c",16);
			}
		break;
		case'P':					//baixo
			if (lab[x][y+1][z]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				y++;
				mgotoxy(x,y);
				printf("%c",31);
			}
		break;
		case'K':					//esquerda
			if (lab[x-1][y][z]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				x--;
				mgotoxy(x,y);
				printf("%c",17);
			}
		break;
		case'w':					//frente
			if (lab[x][y][z+1]!=219){
				z++;
				zescreve();
				mgotoxy(x,y);
				printf("%c",1);
			}
		break;
		case's':					//tras
			if (lab[x][y][z-1]!=219){
				z--;
				zescreve();
				mgotoxy(x,y);
				printf("O");
			}
		break;
		}
	}
}
