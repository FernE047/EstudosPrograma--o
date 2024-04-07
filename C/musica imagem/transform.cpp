#include<stdio.h>
#include<string.h>
#include<zlib.h>
#include<png.h>

FILE *mus_a;
FILE *mus_n;
FILE *mus;
FILE *imagem;
char maior_tamanho=0;
int quantidade_palavras=0;

int preparacao(){
	char a,b=1,tamanho=0,palavra[20];
	mus_a=fopen("musica","r");
	mus_n=fopen("musica_nova","w");
	while( (fscanf(mus_a,"%c", &a))!=EOF ){
		if(((a>=65)and(a<=90))or((a>97)and(a<122)))tamanho++;
		if((a>=65)and(a<=90)){
			a=a+32;
		}else if(((a<97)or(a>122))and(a!=13)){
			a=32;
			if(tamanho>=maior_tamanho)maior_tamanho=tamanho;
			tamanho=0;
		}
		if((b==2)and(a==32)){
			b=1;
			a=65;
		}else if(b==2){
			b=1;
			fprintf(mus_n,"%c",a);
		}else{
			fprintf(mus_n,"%c",a);
		}
		if((a==32)and(b==1))b=2;
	}
	fclose(mus_a);
	fclose(mus_n);
	mus=fopen("musica_nova","r");
	while((fscanf(mus,"%s",&palavra))!=EOF)quantidade_palavras++;
	printf("maior palavra contem: %d\nquantidade de palavras:%d\n",maior_tamanho,quantidade_palavras);
	fclose(mus);
}

int main(){
	preparacao();
	const int QUANTIA=quantidade_palavras+1;
	const int MAIOR=maior_tamanho+1;
	int linhas,colunas,cont=0;
	char palavras[QUANTIA][MAIOR];
	mus=fopen("musica_nova","r");
	while((fscanf(mus,"%s",&palavras[cont]))!=EOF)cont++;
	fclose(mus);
	imagem=fopen("imagem_musica","w");
	for(colunas=0;colunas<QUANTIA;colunas++){
		for(linhas=0;linhas<QUANTIA;linhas++){
			if(!(strcmp(palavras[colunas],palavras[linhas]))){
				fprintf(imagem,"X");
			}else{
				fprintf(imagem," ");
			}
		}
		fprintf(imagem,"\n");
	}
}
