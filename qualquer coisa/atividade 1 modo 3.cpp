#include<stdio.h>
#include<stdlib.h>
int main(){
	int quaisquer[3][3],pos,pos2;
	for(pos=0;pos<=2;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("digite o numero de posicao [%d][%d]:\n",pos,pos2);
			scanf("%d",&quaisquer[pos][pos2]);
			system("cls");
		}
	}
	printf("numeros digitados:\n");
	for(pos=0;pos<=2;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("matriz[%d][%d]=%d \n",pos,pos2,quaisquer[pos][pos2]);
		}
	}
	system("pause");
}