#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	int count;
	char tecla;
	for(count=0;count<=256;count++){
		printf("%d:%c\n",count,count);
	}
	tecla=getch();
	printf("%d",tecla);
	getch();
}
