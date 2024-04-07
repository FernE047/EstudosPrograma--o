#include<stdio.h>

FILE *mus_a;
FILE *mus_n;
FILE *mus_t;
FILE *mus;
char a,b=1,palavra[20];
int quantidade_palavras=0;

int main(){
	mus_a=fopen("musica","r");
	mus_n=fopen("musica_nova","w");
	while( (fscanf(mus_a,"%c", &a))!=EOF ){
		if((a>=65)and(a<=90)){
			a=a+32;
		}else if(((a<97)or(a>122))and(a!=13)){
			a=32;
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
	const int QUANTIA=quantidade_palavras;
	char palavras[QUANTIA][20];
	mus=fopen("musica_nova","r");
	printf("%d",QUANTIA);
}
