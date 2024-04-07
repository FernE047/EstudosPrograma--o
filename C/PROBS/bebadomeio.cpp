#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define PROB 2
#define PASSO_TOTAL 20
#define CERTEZA 10000
const int PASSOO=(PASSO_TOTAL*2)+1;
int total[PASSOO],passo,peso1,peso2;

int main(){
	srand(time(NULL));
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		total[peso1]=0;
	}
	for(peso1=1;peso1<=CERTEZA;peso1++){
		passo=0;
		for(peso2=1;peso2<=PASSO_TOTAL;peso2++){
			if(rand()%PROB){
				passo++;
			}else{
				passo--;
			}
		}
		printf("%d\n",passo);
		total[passo+PASSO_TOTAL]++;
	}
	printf("\n\n\n",passo);
	peso2=0;
	for(peso1=0;peso1<=(PASSO_TOTAL*2);peso1++){
		printf("%d:%d\n",peso1,total[peso1]);
		peso2+=total[peso1];
	}
	printf("%d\n",peso2);
}
