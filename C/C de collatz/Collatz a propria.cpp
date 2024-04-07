#include <stdio.h>
int main()
{
int g,k;
scanf("%d", &g);
k=1;
while(g!=1){
	if(g%2==0){
		g=g/2; 
	}
	else
	{
		g=3*g+1;
	}
	printf("%d:%d\n",k,g);
	k++;
}
}
