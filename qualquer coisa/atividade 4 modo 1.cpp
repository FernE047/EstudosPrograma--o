#include<stdlib.h>
#include<stdio.h>
int main(){
	int numeros[10][20],soma[10],pos,pos2;
	for(pos=0;pos<=9;pos++){
		soma[pos]=0;
		for(pos2=0;pos2<=19;pos2++){
			printf("digite o numero da posicao [%d][%d]\n",pos,pos2);
			scanf("%d",numeros[pos][pos2]);
			soma[pos]=soma[pos]+numeros[pos][pos2];
		}
		printf("linha %d terminada\n\n\n\n\n",pos);
	}
	for(pos=0;pos<=9;pos++){
		printf("soma da linha %d:\n",pos);
		for(pos2=0;pos2<=18;pos2++){
			printf("%d+",numeros[pos][pos2]);
		}
		printf("%d=%d\n\n",numeros[pos][19],soma[pos]);
	}
	system("pause");
}
