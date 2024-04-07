#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
int procura(int x,int y);
int escreve(int x,int y);

int main(){
	int x,y;
	FILE *arq=fopen("labirinto","w");
	srand(time(NULL));
	system("MODE con cols=161 lines=55");
    for(y=0;y<49;y++)
    {   
    	for(x=1;x<160;x++)
    	{
    		if((x==159)&&(y==48)){
    			fprintf(arq,"1");
			}else{
				fprintf(arq,"0");
			}
			mgotoxy(x,y);
        	printf("%c",219);
    	}
    	fprintf(arq,"\n");
	}
    mgotoxy(2,1);
    printf("");
	escreve(2,1);
}

int procura(int x,int y){
	FILE *arq=fopen("labirinto","r");
//	FILE *esq=fopen("testando","w");
	int soma,cont=0,copo;
	soma=y*160+x;
	while (soma!=cont){
		copo=getc(arq);
//		fprintf(esq,"soma:%d  bin:%d\n",cont,copo);
		cont++;
	}
	if(copo==49){
		copo=1;
	}else{
		copo=0;
	}
	return(copo);
	fclose(arq);
}

int escreve(int x,int y){
	FILE *arq=fopen("labirinto","r");
	int soma,cont=0,copo;
	soma=y*160+x;
	while (soma!=cont){
		if(cont+1==soma){
			fprintf(arq,"");
		}else{
			copo=getc(arq);
		}
		cont++;
	}
	fclose(arq);
}



