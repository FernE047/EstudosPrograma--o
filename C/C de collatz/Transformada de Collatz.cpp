#include <stdio.h>
int main()
{
int i,g,k[300];
i=1;
while(i!=300){
	g=i;
	k[i]=0;
	while(g!=1){
		if(g%2==0){
			g=g/2; 
		}
		else
		{
			g=3*g+1;
		}
		k[i]++;
	}
	k[i]++;
	printf("%d:%d\n",i,k[i]);
	i++;
	}
i=1;
scanf("%d",&i);
}
