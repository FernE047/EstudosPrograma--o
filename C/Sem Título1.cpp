#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	int pos1=0,pos2=0,count;
	char tecla,qualquer[25];
	printf("player 1 aperte A\n");
	printf("player 2 aperte L\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("1\n");
	printf("2\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	while((pos1!=80)&&(pos2!=80)){
		tecla=getch();
		system("cls");
		switch(tecla){
			case 'a':
				pos1++;
				break;
			case 'A':
				pos1++;
				break;
			case 'S':
				pos2++;
				break;
			case 's':
				pos2++;
				break;
		}
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		for(count=0;count<pos1;count++){
			printf(" ");
		}
		printf("1\n");
		for(count=0;count<pos2;count++){
			printf(" ");
		}
		printf("2\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	}
	if(pos1==70){
		printf("\n Player 1 e o grande campeao\n");
	}else{
		printf("\n Player 2 e o grande campeao\n");
	}
	scanf("%s",&qualquer);
	system("pause");
}
