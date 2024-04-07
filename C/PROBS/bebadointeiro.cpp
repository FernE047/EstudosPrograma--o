#include<stdio.h>
#include<time.h>
#include<windows.h>
#define PROB 10
#define PASSO_TOTAL 20
#define CERTEZA 10000
const int PASSOO=(PASSO_TOTAL*2)+1;
int total[PASSOO][2],passo,peso1,peso2,dir;

int main(){
	srand(time(NULL));
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		total[peso1][0]=0;
		total[peso1][1]=0;
	}
	for(peso1=1;peso1<=CERTEZA;peso1++){
		passo=0;
		for(peso2=1;peso2<=PASSO_TOTAL;peso2++){
			dir=(rand()%PROB);
			if(dir){
				passo++;
			}else{
				passo--;
			}
		}
		printf("%d\n",passo);
		total[passo+PASSO_TOTAL][(dir==0?0:1)]++;
	}
	printf("\n\n\n",passo);
	peso2=0;
	printf("direcao 1:\n\n");
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		printf("%d:%d\n",peso1,total[peso1][0]);
	}
	printf("\ndirecao 2:\n\n");
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		printf("%d:%d\n",peso1,total[peso1][1]);
	}
	printf("\nsem direcao:\n\n");
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		printf("%d:%d\n",peso1,total[peso1][1]+total[peso1][0]);
		peso2+=total[peso1][1]+total[peso1][0];
	}
	printf("\ntotal:%d\n",peso2);
}
