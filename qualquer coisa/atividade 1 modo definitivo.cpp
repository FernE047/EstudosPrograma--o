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
	pos=3;
	while(pos!=1){
		printf("digite 1 para uma apresentacao grafica \ndigite 2 para uma apresentacao em lista\n");
		scanf("%d",&pos);
		system("cls");
		if(pos==1){
			printf("   0  1  2\n");
			printf("  ---------\n");
			for(pos=0;pos<=2;pos++){
				printf("%d| ",pos);
				for(pos2=0;pos2<=2;pos2++){
					printf("%d|",quaisquer[pos][pos2]);
				}
				printf("\n");
			}
			pos=1;
		}else if(pos==2){
		printf("numeros digitados:\n");
			for(pos=0;pos<=2;pos++){
				for(pos2=0;pos2<=2;pos2++){
					printf("matriz[%d][%d]=%d \n",pos,pos2,quaisquer[pos][pos2]);
				}
			}
			pos=1;
		}else{
			printf("voce digitou um valor invalido\n");
		}
	}
	system("pause");
}

