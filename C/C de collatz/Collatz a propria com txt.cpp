#include <stdio.h>
int main()
{
int k,h;
unsigned int g;
FILE *arq=fopen("teste","w");
h=1;
while(h!=1000){
	g=h;
	k=1;
	fprintf(arq,"\n\n%d:\n\n",g);
	printf("%d\n",g);
	while(g!=1){
		if(g%2==0){
			g=g/2; 
		}
		else
		{
			g=3*g+1;
		}
		fprintf(arq,"%d:%d\n",k,g);
		k++;
	}
	h++;
}
}
