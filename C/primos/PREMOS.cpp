#include<stdio.h>
#define MAX 1000000

FILE *arq;
FILE *park;

int main(){
	char sdn[MAX];
	int primos,cont,acrescimo,result,holder;
	arq=fopen("1M","r");
	park=fopen("MAIOR SUPER DIVISOR 1M","w");
	for(cont=0;cont<MAX;cont++){
		sdn[cont]=0;
	}
	sdn[MAX-1]=1;
	while((fscanf(arq,"%d ",&primos))!=EOF){
		acrescimo=0;
		for(cont=(MAX-1);cont>=0;cont--){
			result=(sdn[cont]*primos)+acrescimo;
			holder=result%10;
			acrescimo=(result-holder)/10;/*
			printf("primos:%d\n*\nsdn:%d\nresult:%d\nacrescimo:%d\nholder:%d\ncont:%d\n\n\n",primos,sdn[cont],result,acrescimo,holder,cont);
			getch();*/
			sdn[cont]=holder;
		}
		if(acrescimo>0)break;
	}
	fprintf(park,"%d",acrescimo);
	for(cont=0;cont<MAX;cont++){
		fprintf(park,"%d",sdn[cont]);
	}
	fprintf(park,"\n\n%d",primos);
	printf("%d",primos);
}
