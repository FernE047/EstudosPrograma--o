#include <stdio.h>
#include <math.h>
int k,h,j;
unsigned int g,t;
FILE *arq=fopen("potencia_2","w");

int trans(){
	t=g;
	j=20;
	while(j>=0){
		if(t>pow(2,j)){
			fprintf(arq,"%d+",j);
			t=t-pow(2,j);				
		}else if(t==pow(2,j)){
			fprintf(arq,"%d",j);
			t=t-pow(2,j);
		}
		j--;
	}
}

int main()
{
h=1;
while(h!=1000){
	g=h;
	k=1;
	fprintf(arq,"\n\n%d:\n\n",g);
	printf("%d\n",g);
	while(g!=1){
		if(g>=1000){
			if(k<10){
				fprintf(arq,"\n%d:%d:		",k,g);
			}else{
				fprintf(arq,"\n%d:%d:	",k,g);
			}
		}else{
			fprintf(arq,"\n%d:%d:		",k,g);
		}		
		trans();
		if(g%2==0){
			g=g/2; 
			fprintf(arq,"			B");
		}
		else
		{
			g=3*g+1;
			fprintf(arq,"			A");
		}
		k++;
	}
	h++;
}
}
