#include<stdlib.h>
#include<stdio.h>
int main(){
	int numeros[20][10],soma[20],pos,pos2;
	for(pos=0;pos<=19;pos++){
		soma[pos]=0;
		for(pos2=0;pos2<=9;pos2++){
			printf("digite o numero da posicao [%d][%d]\n",pos,pos2);
			scanf("%d",numeros[pos][pos2]);
			soma[pos]=soma[pos]+numeros[pos][pos2];
		}
		printf("linha %d terminada\n\n\n\n\n",pos);
	}
	for(pos=0;pos<=19;pos++){
		printf("soma da linha %d:\n",pos);
		for(pos2=0;pos2<=8;pos2++){
			printf("%d+",numeros[pos][pos2]);
		}
		printf("%d=%d\n\n",numeros[pos][9],soma[pos]);
	}
	system("pause");
}
