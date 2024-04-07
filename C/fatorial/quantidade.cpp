#include<stdio.h>

FILE *arq;

int main(){
	int quant=0;
	char e;
	arq=fopen("100K todos","r");
	while(fscanf(arq,"%c",&e)!=EOF){
		if(e==48)quant++;
		if(e==48)printf("%d\n",quant);
	}
	printf("%d",quant);
}
