#include<stdio.h>
int main(){
	char info[100];
	long unsigned int numero,letra,i;
	i=0;
	scanf("%d",&numero);
	while(numero>=27){		
		printf("%d/%d\n",numero,27);
		printf("%d*%d=%d\n",27,numero/27,(27*(numero/27)));
		printf("%d\n\n",(numero-(27*(numero/27))));
		letra=numero%27;
		printf("%d\n\n",letra);
		if(letra==0){
			info[i]=' ';
		}else{
			info[i]=(letra+64);
		}
		numero=numero/27;
		i++;
	}
	if(numero<27){
		info[i]=(numero+64);
	}
	printf("%s",info);
}
