#include<stdio.h>
#include<stdlib.h>
int main(){
	int numeros[5][3],pos,pos2;
	for(pos=0;pos<=4;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("digite um numero qualquer\n");
			scanf("%d",&numeros[pos][pos2]);
		}
	}
	printf("ordem inversa:\n");
	for(pos=4;pos>=0;pos--){
		for(pos2=2;pos2>=0;pos2--){
			printf("%d\n",numeros[pos][pos2]);
		}
	}
	system("pause");
}
