#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define LARGURA 5		//MAXIMO 159, MINIMO 5 e preferencialmente valores impares
#define ALTURA 5		//MAXIMO 49, MINIMO 5 e preferencialmente valores impares
#define PROFUNDIDADE 5 	//MAXIMO 29, MINIMO 5 e preferencialmente valores imapares
#define KATANA 5 		//MAXIMO 29, MINIMO 5 e preferencialmente valores imapares

short int controle_de_base=0;				//controle de base
const int base=((LARGURA-1)/2)*((ALTURA-1)/2)*((PROFUNDIDADE-1)/2)*((KATANA-1)/2);  // pseudo-constantes
short int x,y,z,w,direcao,x_curvas[base],y_curvas[base],z_curvas[base],w_curvas[base],himym,teste_de_cont; //criação do labirinto
short int lab[LARGURA+1][ALTURA][PROFUNDIDADE][KATANA],x_fim,y_fim,z_fim,w_fim;			//labirinto manipulavel
short int x_escreve,y_escreve;				//zescreve
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int sera(){
	if ((lab[x+2][y][z][w]==0)or(x==LARGURA-1)){
		if((lab[x-2][y][z][w]==0)or(x==2)){
			if((lab[x][y+2][z][w]==0)or(y==ALTURA-2)){
				if((lab[x][y-2][z][w]==0)or(y==1)){
					if((lab[x][y][z+2][w]==0)or(z==PROFUNDIDADE-2)){
						if((lab[x][y][z-2][w]==0)or(z==1)){
							if((lab[x][y][z][w+2]==0)or(z==KATANA-2)){
								if((lab[x][y][z][w-2]==0)or(z==1)){
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
		}else{
			return(1);
		}
	}else{
		return(1);
	}
}

int zescreve(){
	system("cls");
    for(y_escreve=0;y_escreve<ALTURA;y_escreve++)
    {
    	for(x_escreve=1;x_escreve<(LARGURA+1);x_escreve++)
    	{
			mgotoxy(x_escreve,y_escreve);
        	printf("%c",lab[x_escreve][y_escreve][z][w]);
    	}
    }
    if((z==1)and(w==1)){
    	mgotoxy(2,1);
    	printf("C");
	}
	if((z==z_fim)and(w==w_fim)){
		mgotoxy(x_fim,y_fim);
    	printf("S");
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
		    	for(w=0;w<KATANA;w++)
   				{
   		 	    	lab[x][y][z][w]=219;
   				}
   			}
    	}
    }
    for(himym=0;himym<base;himym++){
    	x_curvas[himym]=0;
    	y_curvas[himym]=0;
    	z_curvas[himym]=0;
    	w_curvas[himym]=0;
	}
	x=2;
	y=1;
	z=1;
	w=1;
    lab[x][y][z][w]=0;
	x_curvas[0]=x;
	y_curvas[0]=y;
	z_curvas[0]=z;
	w_curvas[0]=w;
	do{
		x=x_curvas[controle_de_base];
		y=y_curvas[controle_de_base];
		z=z_curvas[controle_de_base];
		w=w_curvas[controle_de_base];
		while(sera()){
			teste_de_cont=0;
			while(teste_de_cont==0){									
				switch(direcao=((rand()%8)+1)){
					case 1:									//direita
						if(x==(LARGURA-1)){
							teste_de_cont=0;
						}else if(lab[x+2][y][z][w]!=0){
							teste_de_cont=1;
							x++;
        					lab[x][y][z][w]=0;
							x++;
        					lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 2:									//baixo
						if(y==(ALTURA-2)){
							teste_de_cont=0;
						}else if(lab[x][y+2][z][w]!=0){
							teste_de_cont=1;
							y++;
							lab[x][y][z][w]=0;
							y++;
							lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 3:									//esquerda
						if(x==2){
							teste_de_cont=0;
						}else if(lab[x-2][y][z][w]!=0){
							teste_de_cont=1;
							x--;
        					lab[x][y][z][w]=0;
							x--;
        					lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 4:									//cima
						if(y==1){
							teste_de_cont=0;
						}else if(lab[x][y-2][z][w]!=0){
							teste_de_cont=1;
							y--;
        					lab[x][y][z][w]=0;
							y--;
        					lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 5:									//baixo
						if(z==(PROFUNDIDADE-2)){
							teste_de_cont=0;
						}else if(lab[x][y][z+2][w]!=0){
							teste_de_cont=1;
							z++;
							lab[x][y][z][w]=0;
							z++;
							lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 6:									//cima
						if(z==1){
							teste_de_cont=0;
						}else if(lab[x][y][z-2][w]!=0){
							teste_de_cont=1;
							z--;
        					lab[x][y][z][w]=0;
							z--;
        					lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 7:									//baixo
						if(w==(KATANA-2)){
							teste_de_cont=0;
						}else if(lab[x][y][z][w+2]!=0){
							teste_de_cont=1;
							w++;
							lab[x][y][z][w]=0;
							w++;
							lab[x][y][z][w]=0;
						}else{
							teste_de_cont=0;
						}
					break;
					case 8:									//cima
						if(w==1){
							teste_de_cont=0;
						}else if(lab[x][y][z][w-2]!=0){
							teste_de_cont=1;
							w--;
        					lab[x][y][z][w]=0;
							w--;
        					lab[x][y][z][w]=0;
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
			w_curvas[controle_de_base]=w;
		}
		controle_de_base=controle_de_base-1;
	}while(controle_de_base!=0);
    himym=1;
    controle_de_base=base;
    while(himym==1){
    	if((x_curvas[controle_de_base]>1)and(y_curvas[controle_de_base]>1)and(z_curvas[controle_de_base]>1)and(w_curvas[controle_de_base]>1)){
    		himym=0;
    		x_fim=x_curvas[controle_de_base];
    		y_fim=y_curvas[controle_de_base];
    		z_fim=z_curvas[controle_de_base];
    		w_fim=w_curvas[controle_de_base];
		}
		controle_de_base--;
	}
	x=2;
	y=1;
	z=1;
	w=1;
	zescreve();
	himym=0;
	while(not((x==x_fim)and(y==y_fim)and(z==z_fim)and(w==w_fim))){
		tecla=getch();
		switch(tecla){
		case'H':					//cima
			if (lab[x][y-1][z][w]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				lab[x][y][z][w]=177;
				y--;
				mgotoxy(x,y);
				printf("%c",30);
			}
		break;
		case'M':					//direita
			if (lab[x+1][y][z][w]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				lab[x][y][z][w]=177;
				x++;
				mgotoxy(x,y);
				printf("%c",16);
			}
		break;
		case'P':					//baixo
			if (lab[x][y+1][z][w]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				lab[x][y][z][w]=177;
				y++;
				mgotoxy(x,y);
				printf("%c",31);
			}
		break;
		case'K':					//esquerda
			if (lab[x-1][y][z][w]!=219){
				mgotoxy(x,y);
				printf("%c",177);
				lab[x][y][z][w]=177;
				x--;
				mgotoxy(x,y);
				printf("%c",17);
			}
		break;
		case'w':					//tras
			if (lab[x][y][z-1][w]!=219){
				lab[x][y][z][w]=177;
				z--;
				zescreve();
				mgotoxy(x,y);
				printf("%c",79);
			}
		break;
		case's':					//frente
			if (lab[x][y][z+1][w]!=219){
				lab[x][y][z][w]=177;
				z++;
				zescreve();
				mgotoxy(x,y);
				printf("%c",2);
			}
		break;
		case'a':					//kata
			if (lab[x][y][z][w-1]!=219){
				lab[x][y][z][w]=177;
				w--;
				zescreve();
				mgotoxy(x,y);
				printf("%c",168);
			}
		break;
		case'd':					//ana
			if (lab[x][y][z][w+1]!=219){
				lab[x][y][z][w]=177;
				w++;
				zescreve();
				mgotoxy(x,y);
				printf("%c",63);
			}
		break;
		}
	}
}
