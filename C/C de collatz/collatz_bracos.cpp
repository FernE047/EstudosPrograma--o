#include <stdio.h>
#include <string.h>
#include <windows.h> 
#define LIMITE 262144

int constroi(int inicial,int ordem,int origem){
	unsigned long int termo;
	int n;
	char nome[42]="braco/";
	char aux1[10],aux2[10];
	sprintf(aux1, "%i", inicial);
	sprintf(aux2, "%i", ordem);
	strcat(nome, aux2);
	CreateDirectoryA(nome,NULL);
	strcat(nome, "/braco-");
	sprintf(aux2, "%i", origem); 
	strcat(nome, aux2);
	strcat(nome, "-");
	strcat(nome, aux1);
	strcat(nome,".txt");
	FILE *catalogo=fopen(nome,"w");
	fprintf(catalogo,nome);
	printf(nome);
	printf("\n");
	fprintf(catalogo,"\n%d\n/\\ \n|| \n",inicial);
	termo=inicial;
	for(n=1;n<=14;n++){
		termo=termo*2;
		fprintf(catalogo,"%d",termo);
		if((((termo-1)%3)==0)and(termo!=4)){
			fprintf(catalogo,"<-%d",((termo-1)/3));
			if(((termo-1)/3)<=LIMITE){
				constroi(((termo-1)/3),(ordem+1),inicial);
			}
		}
		if(n!=14){
			fprintf(catalogo,"\n/\\ \n|| \n");
		}
	}
	fclose(catalogo);		
}

int main(){
	constroi(1,0,4);
}
