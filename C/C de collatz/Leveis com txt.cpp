#include <stdio.h>
int main()
{
int c,f,i,k;
unsigned int g;
FILE *arq=fopen("kkkkk","w");
i=1;
c=1;
while(c!=100){
	f=1;
	i=1;
	fprintf(arq,"%d:\n\n",c);
	while(f!=1000000){
		g=f;
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
		if(k==c){
			fprintf(arq,"%d:%d\n",f,k);
			i++;
		}
		f++;
		}
		printf("%d\n",c);
		fprintf(arq,"quantidade:%d\n\n",i-1);
	c++;
}
}
