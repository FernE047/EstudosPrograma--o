#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define LARGURA 11		//MAXIMO 159, MINIMO 5 e preferencialmente valores impares
#define ALTURA 11		//MAXIMO 49, MINIMO 5 e preferencialmente valores impares
#define PROFUNDIDADE 5	//MAXIMO 99, MINIMO 5 e preferencialmente valores impares

short int controledebase=0;				//controle de base
const int largurabase=((LARGURA-3)/2),alturabase=((ALTURA-3)/2),profundidadebase=(PROFUNDIDADE-3)/2,tamanhobase=alturabase*largurabase*profundidadebase;  // pseudo-constantes
short int x,y,z,base[largurabase+1][alturabase+1][profundidadebase+1],xbase,ybase,zbase,direcao,xcurvas[tamanhobase],ycurvas[tamanhobase],zcurvas[tamanhobase],himym,testedecont; //criação do labirinto
short int lab[161][55][11],xfim,yfim,zfim;			//labirinto manipulavel
char tecla;

void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STDOUTPUTHANDLE),p);
}

int convn(){
	x=(xbase+1)*2;
	y=2*ybase+1;
	z=2*zbase+1;
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
    if(z==zfim){
		mgotoxy(xfim,yfim);
		printf("S");
    }
    if(z==1){
		mgotoxy(2,1);
		printf("C");
    }
}

int sera(){
	if ((base[xbase+1][ybase][zbase]==1)or(xbase==largurabase)){
		if((base[xbase-1][ybase][zbase]==1)or(xbase==0)){
			if((base[xbase][ybase+1][zbase]==1)or(ybase==alturabase)){
				if((base[xbase][ybase-1][zbase]==1)or(ybase==0)){
					if((base[xbase][ybase][zbase+1]==1)or(ybase==profundidadebase)){
						if((base[xbase][ybase][zbase-1]==1)or(zbase==0)){
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

int criar(){
	srand(time(NULL));
	system("MODE con cols=161 lines=55");
    for(y=0;y<ALTURA;y++)
    {
    	for(x=1;x<(LARGURA+1);x++)
    	{
    		for(z=0;x<PROFUNDIDADE;z++)
    		{
    	   	 	lab[x][y][z]=219;
    		}
    	}
    }
    for(ybase=0;ybase<alturabase;ybase++)
    {
    	for(xbase=1;xbase<=largurabase;xbase++)
    	{
  		  	for(zbase=0;zbase<=profundidadebase;zbase++)
    		{
    			base[xbase][ybase][zbase]=0;
       		}
       	}
    }
    for(himym=0;himym<tamanhobase;himym++){
    	xcurvas[himym]=0;
    	ycurvas[himym]=0;
    	zcurvas[himym]=0;
	}
	xbase=0;
	ybase=0;
	zbase=0;
	convn();
	base[xbase][ybase][zbase]=1;
    lab[x][y][z]=0;
	xcurvas[0]=0;
	ycurvas[0]=0;
	zcurvas[0]=0;
	do{
		xbase=xcurvas[controledebase];
		ybase=ycurvas[controledebase];
		zbase=zcurvas[controledebase];
		while(sera()){
			testedecont=0;
			while(testedecont==0){
				switch(direcao=((rand()%6)+1)){
					case 1:									//direita
						if(xbase==(largurabase)){
							testedecont=0;
						}else if(base[xbase+1][ybase][zbase]==0){
							testedecont=1;
							xbase++;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x-1][y][z]=0;
        					lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
					case 2:									//baixo
						if(ybase==(alturabase)){
							testedecont=0;
						}else if(base[xbase][ybase+1][zbase]==0){
							testedecont=1;
							ybase++;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x][y-1][z]=0;
							lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
					case 3:									//esquerda
						if(xbase==0){
							testedecont=0;
						}else if(base[xbase-1][ybase][zbase]==0){
							testedecont=1;
							xbase--;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x+1][y][z]=0;
        					lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
					case 4:									//cima
						if(ybase==0){
							testedecont=0;
						}else if(base[xbase][ybase-1][zbase]==0){
							testedecont=1;
							ybase--;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x][y+1][z]=0;
        					lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
					case 5:									//tras
						if(zbase==0){
							testedecont=0;
						}else if(base[xbase][ybase][zbase-1]==0){
							testedecont=1;
							zbase--;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x][y][z+1]=0;
        					lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
					case 6:									//frente
						if(zbase==profundidadebase){
							testedecont=0;
						}else if(base[xbase][ybase][zbase+1]==0){
							testedecont=1;
							ybase++;
							base[xbase][ybase][zbase]=1;
							convn();
        					lab[x][y][z-1]=0;
        					lab[x][y][z]=0;
						}else{
							testedecont=0;
						}
					break;
				}
			}
			controledebase++;
			xcurvas[controledebase]=xbase;
			ycurvas[controledebase]=ybase;
			zcurvas[controledebase]=zbase;
		}
		controledebase=controledebase-1;
	}while(controledebase!=0);
    himym=1;
    controledebase=tamanhobase;
    while(himym==1){
    	if((xcurvas[controledebase]!=0)and(ycurvas[controledebase]!=0)and(zcurvas[controledebase]!=0)){
    		himym=0;
    		xbase=xcurvas[controledebase];
    		ybase=ycurvas[controledebase];
    		zbase=zcurvas[controledebase];
    		convn();
    		xfim=x;
    		yfim=y;
    		zfim=z;
		}
		controledebase--;
	}
	xbase=0;
	ybase=0;
	zbase=0;
	convn();
	himym=0;
	zescreve();
}

int main(){
	criar();
	while(not((x==xfim)and(y==yfim)and(z==zfim))){
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
