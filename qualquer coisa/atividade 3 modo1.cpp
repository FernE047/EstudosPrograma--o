#include<stdio.h>
#include<stdlib.h>
int main(){
	int maior[6][4],pos1,pos2,quant=0;
	for(pos1=0;pos1<=5;pos1++){
		for(pos2=0;pos2<=3;pos2++){
			printf("digite um numero\n");
			scanf("%d",&maior[pos1][pos2]);
			if(maior[pos1][pos2]>30)quant++;
		}
	}
	printf("voce digitou %d numeros maiores que 30",quant);
}
