#include<stdio.h>
#include<stdlib.h>
int main(){
	int produtos[6][11],fat1,fat2;
	for(fat1=1;fat1<=5;fat1++){
		for(fat2=0;fat2<=10;fat2++){
			produtos[fat1][fat2]=fat1*fat2;
			printf("%dX%d=%d\n",fat1,fat2,produtos[fat1][fat2]);
		}
		printf("\n\n\n\n");
	}
	system("pause");
}
