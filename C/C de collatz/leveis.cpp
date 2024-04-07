#include <stdio.h>
int main()
{
int c,f,i,g,k[300];
i=1;
while(i!=0){
	f=1;
	if(i==1){
		printf("qual o valor deseja testar?\n");
		scanf("%d",&c);
	}else{
		c=i;
	}
	i=1;
	while(f!=100000){
		g=f;
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
		if(k[i]==c){
			printf("%d:%d\n",f,k[i]);
			i++;
		}
		f++;
		}
		printf("%d",i-1);
	printf("\nse quiser sair digite 0\n");
	scanf("%d",&i);
}
}
