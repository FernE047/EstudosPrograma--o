#include<stdio.h>
#include<stdlib.h>
int main(){
	int numeros[6][11],pos1,pos2;
	for(pos1=1;pos1<=5;pos1++){
		for(pos2=0;pos2<=10;pos2++){
			numeros[pos1][pos2]=pos1*pos2;
			printf("%dX%d=%d\n",pos1,pos2,numeros[pos1][pos2]);
		}
		printf("\n\n\n");
	}
	system("pause");
}
