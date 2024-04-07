#include<stdio.h>
#include<stdlib.h>
int main(){
	int produtos[6][11],fat1,fat2;
	for(fat1=1;fat1<=5;fat1++){
		for(fat2=0;fat2<=10;fat2++){
			produtos[fat1][fat2]=fat1*fat2;
		}
	}
	for(fat2=0;fat2<=10;fat2++){			//AVISO: me preocupei mais com a aparencia da tabuada
		for(fat1=1;fat1<=5;fat1++){
			if(produtos[fat1][fat2]>=10&&fat2!=10){
				printf("%dX%d=%d   ",fat1,fat2,produtos[fat1][fat2]);			
			}else if(fat2==10){
				printf("%dX%d=%d  ",fat1,fat2,produtos[fat1][fat2]);
			}else{
				printf("%dX%d=%d    ",fat1,fat2,produtos[fat1][fat2]);
			}
		}
		printf("\n");
	}
	system("pause");
	
}
