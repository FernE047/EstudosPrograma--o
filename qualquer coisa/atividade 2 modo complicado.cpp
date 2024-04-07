#include<stdio.h>
#include<stdlib.h>
int main(){
	int numeros[5][3],soremun[5][3],pos,pos2,sop,sop2;
	for(pos=0;pos<=4;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("digite um numero qualquer\n");
			scanf("%d",&numeros[pos][pos2]);
			system("cls");
		}
	}
	printf("ordem inversa:\n");
	for(pos=4,sop=0;pos>=0,sop<=4;pos--,sop++){
		for(pos2=2,sop2=0;pos2>=0,sop2<=2;pos2--,sop2++){
			soremun[sop][sop2]=numeros[pos][pos2];
		}
	}
	for(pos=0;pos<=4;pos++){
		for(pos2=0;pos2<=2;pos2++){
			printf("%d\n",soremun[pos][pos2]);
		}
	}
	system("pause");
}
