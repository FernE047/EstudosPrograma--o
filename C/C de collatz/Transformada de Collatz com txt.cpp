#include <stdio.h>
int main()
{
int i,k;
unsigned int g;
FILE *arq=fopen("lol","w");
i=1;
while(i!=1000000){
	g=i;
	k=0;
	while(g!=1){
		if(g%2==0){
			g=g/2; 
		}
		else
		{
			g=3*g+1;
		}
		k++;
	}
	k++;
	fprintf(arq,"%d:%d\n",i,k);
	printf("%d\n",i);
	i++;
	}
i=1;
scanf("%d",&i);
}
