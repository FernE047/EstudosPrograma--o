#include<stdio.h>
#include<conio.h>
#define MAX 10001

FILE *novo;
int numero,primos[MAX],a,cont,b;

int main(){
	novo=fopen("numeros primos 10k","w");
	for(cont=0;cont<=(MAX-1);cont++){
		primos[cont]=2;
	}
	numero=2;
	for(cont=1;cont<=(MAX-1);cont++){
		b=1;
		while(b){
			b=0;
			for(a=0;a<=(MAX-1);a++){
				if((numero%primos[a])==0)b=1;
			}
			if(b==1)numero++;
		}
		printf("%.2f %%\n", 0.01*cont);
		primos[cont]=numero;
		numero++;
		fprintf(novo,"%d\n",primos[cont]);
	}
}
