#include<stdio.h>
#include<stdlib.h>
int main(){
	int numeros[5][3],pos,pos2;
	for(pos=0;pos<=4;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("digite o numero da posicao [%d][%d]\n",pos,pos2);
			scanf("%d",&numeros[pos][pos2]);
			system("cls");
		}
	}
	printf("ordem inversa:\n");
	for(pos=4;pos>=0;pos--){
		for(pos2=2;pos2>=0;pos2--){
			printf("matriz[%d][%d]=%d\n",pos,pos2,numeros[pos][pos2]);
		}
	}
	system("pause");
}
