#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#define CERTEZA 1000000
float num1,num2,num3,porc,quant;
int peso1;
char a[1];

int main(){
	srand(time(NULL));
	a[0]='0';
	while(a[0]=='0'){
		quant=0;
		for(peso1=1;peso1<=CERTEZA;peso1++){
			num1=fmod(rand(),10);
			num2=fmod(rand(),10);
			num3=fmod(rand(),10);
			if(((num1<num2)and(num3>num2))or((num3<num2)and(num1>num2))){
				quant++;
				//printf("sim\n");
			}/*else{
				printf("nao\n");
			}*/
		}
		porc=(quant/CERTEZA)*100;
		printf("\ntotal:%f %%\n",porc);
		scanf("%s",&a);
	}
}
