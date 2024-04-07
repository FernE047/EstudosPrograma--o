#include<windows.h>
#include<stdio.h>
#include<time.h>
#define LARGURA 159	//MAXIMO 159, MINIMO 5 e preferencialmente valores impares
#define ALTURA 49	//MAXIMO 49, MINIMO 5 e preferencialmente valores impares

int controle_de_base=0;				//controle de base
const int largura_base=((LARGURA-3)/2),altura_base=((ALTURA-3)/2),tamanho_base=altura_base*largura_base;  // pseudo-constantes
int x,y,base[largura_base+1][altura_base+1],x_base,y_base,direcao,x_curvas[tamanho_base],y_curvas[tamanho_base],himym,teste_de_cont;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int convn(){
	x=(x_base+1)*2;
	y=2*y_base+1;
}

int sera(){
	if ((base[x_base+1][y_base]==1)or(x_base==largura_base)){
		if((base[x_base-1][y_base]==1)or(x_base==0)){
			if((base[x_base][y_base+1]==1)or(y_base==altura_base)){
				if((base[x_base][y_base-1]==1)or(y_base==0)){
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
    for(y=0;y<ALTURA;y++)
    {
    	for(x=1;x<(LARGURA+1);x++)
    	{
			mgotoxy(x,y);
        	printf("%c",219);
    	}
    }
    for(y_base=0;y_base<altura_base;y_base++)
    {
    	for(x_base=1;x_base<=largura_base;x_base++)
    	{
    		base[x_base][y_base]=0;
       	}
    }
    for(himym=0;himym<tamanho_base;himym++){
    	x_curvas[himym]=0;
    	y_curvas[himym]=0;
	}
	x_base=0;
	y_base=0;
	convn();
	base[x_base][y_base]=1;
	mgotoxy(x,y);
	printf(" ");
	x_curvas[0]=0;
	y_curvas[0]=0;
	do{
		x_base=x_curvas[controle_de_base];
		y_base=y_curvas[controle_de_base];
		while(sera()){
			teste_de_cont=0;
			while(teste_de_cont==0){									
				switch(direcao=((rand()%4)+1)){
					case 1:									//direita
						if(x_base==(largura_base)){
							teste_de_cont=0;
						}else if(base[x_base+1][y_base]==0){
							teste_de_cont=1;
							x_base++;
							base[x_base][y_base]=1;
							convn();
							mgotoxy(x-1,y);
							printf(" ");
							mgotoxy(x,y);
							printf(" ");
						}else{
							teste_de_cont=0;
						}
					break;
					case 2:									//baixo
						if(y_base==(altura_base)){
							teste_de_cont=0;
						}else if(base[x_base][y_base+1]==0){
							teste_de_cont=1;
							y_base++;
							base[x_base][y_base]=1;
							convn();
							mgotoxy(x,y-1);
							printf(" ");
							mgotoxy(x,y);
							printf(" ");
						}else{
							teste_de_cont=0;
						}
					break;
					case 3:									//esquerda
						if(x_base==0){
							teste_de_cont=0;
						}else if(base[x_base-1][y_base]==0){
							teste_de_cont=1;
							x_base--;
							base[x_base][y_base]=1;
							convn();
							mgotoxy(x+1,y);
							printf(" ");
							mgotoxy(x,y);
							printf(" ");
						}else{
							teste_de_cont=0;
						}
					break;
					case 4:									//cima
						if(y_base==0){
							teste_de_cont=0;
						}else if(base[x_base][y_base-1]==0){
							teste_de_cont=1;
							y_base--;
							base[x_base][y_base]=1;
							convn();
							mgotoxy(x,y+1);
							printf(" ");
							mgotoxy(x,y);
							printf(" ");
						}else{
							teste_de_cont=0;
						}
					break;
				}
			}
			controle_de_base++;
			x_curvas[controle_de_base]=x_base;
			y_curvas[controle_de_base]=y_base;
		}
		controle_de_base=controle_de_base-1;
	}while(controle_de_base!=0);
	mgotoxy(0,51);
}

