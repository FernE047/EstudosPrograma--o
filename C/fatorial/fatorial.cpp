#include<stdio.h>
#define MAX 100000

FILE *arq;

int main(){
	char fat[MAX];
	int numeros=1,cont,acrescimo,result,holder;
	arq=fopen("100K todos","w");
	for(cont=0;cont<MAX;cont++){
		fat[cont]=0;
	}
	fat[MAX-1]=1;
	while(numeros){
		acrescimo=0;
		numeros++;
		for(cont=(MAX-1);cont>=0;cont--){
			result=(fat[cont]*numeros)+acrescimo;
			holder=result%10;
			acrescimo=(result-holder)/10;
			fat[cont]=holder;
		}
		fprintf(arq,"%d!=",numeros);
		if((numeros-206)%250==0)printf("%d%%\n",(numeros-206)/250);
		if(acrescimo>0)fprintf(arq,"%d",acrescimo);
		for(cont=0;cont<MAX;cont++){
			if(fat[cont]!=0){
				holder=cont;
				break;
			}
		}
		for(cont=holder;cont<MAX;cont++){
			fprintf(arq,"%d",fat[cont]);
		}
		fprintf(arq,"\n\n");
		if(acrescimo>0)break;
	}
	printf("%d!",numeros);
}
