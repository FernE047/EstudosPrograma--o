#include <stdio.h>
#include <time.h>
#include <windows.h>
#define QUANT 1

int tesoura[3][3], papel[3][3], pedra[3][3];
int esc=0,count,lount,quant,desc;

int main(){	
	srand(time(NULL));
	for(count=0;count<=2;count++){
		for(lount=0;lount<=2;lount++){
			tesoura[count][lount]=QUANT;
			papel[count][lount]=QUANT;
			pedra[count][lount]=QUANT;
		}
	}
	count=0;
	lount=0;
	while(esc!=3){
		count=esc;
		printf("0:papel\n1:tesoura\n2:pedra\n");
		scanf("%d",&esc);
		quant=tesoura[count][lount]+papel[count][lount]+pedra[count][lount];
		desc=rand()%quant;
		if(desc<=(papel[count][lount]-1)){
			desc=0;
		}else if(desc<=tesoura[count][lount]+papel[count][lount]-1){
			desc=1;
		}else{
			desc=2;
		}
		switch(esc){
			case 0:
				switch(desc){
					case 0:
						papel[count][lount]-=1;
						lount=1;
					break;
					case 1:
						tesoura[count][lount]+=3;
						lount=2;
					break;
					case 2:
						pedra[count][lount]-=1;
						lount=0;
					break;
				}
			break;
			case 1:
				switch(desc){
					case 0:
						papel[count][lount]-=1;
						lount=0;
					break;
					case 1:
						tesoura[count][lount]-=1;
						lount=1;
					break;
					case 2:
						pedra[count][lount]+=3;
						lount=2;
					break;
				}
			break;
			case 2:
				switch(desc){
					case 0:
						papel[count][lount]+=3;
						lount=2;
					break;
					case 1:
						tesoura[count][lount]-=1;
						lount=0;
					break;
					case 2:
						pedra[count][lount]-=1;
						lount=1;
					break;
				}
			break;
		}
		switch(lount){
			case 0:
				printf("\n\n Voce ganhou, parabens\n\n");
			break;
			case 1:
				printf("\n\n empatou \n\n");
			break;
			case 2:
				printf("\n\n Voce perdeu, que pena\n\n");
			break;
		}
	}
	printf("\n\npedra[perdeu][papel]=%d\n",pedra[0][0]);
	printf("pedra[perdeu][tesoura]=%d\n",pedra[0][1]);
	printf("pedra[perdeu][pedra]=%d\n",pedra[0][2]);
	printf("pedra[empate][papel]=%d\n",pedra[1][0]);
	printf("pedra[empate][tesoura]=%d\n",pedra[1][1]);
	printf("pedra[empate][pedra]=%d\n",pedra[1][2]);
	printf("pedra[ganhou][papel]=%d\n",pedra[2][0]);
	printf("pedra[ganhou][tesoura]=%d\n",pedra[2][1]);
	printf("pedra[ganhou][pedra]=%d\n",pedra[2][2]);
	printf("tesoura[perdeu][papel]=%d\n",tesoura[0][0]);
	printf("tesoura[perdeu][tesoura]=%d\n",tesoura[0][1]);
	printf("tesoura[perdeu][pedra]=%d\n",tesoura[0][2]);
	printf("tesoura[empate][papel]=%d\n",tesoura[1][0]);
	printf("tesoura[empate][tesoura]=%d\n",tesoura[1][1]);
	printf("tesoura[empate][pedra]=%d\n",tesoura[1][2]);
	printf("tesoura[ganhou][papel]=%d\n",tesoura[2][0]);
	printf("tesoura[ganhou][tesoura]=%d\n",tesoura[2][1]);
	printf("tesoura[ganhou][pedra]=%d\n",tesoura[2][2]);
	printf("papel[perdeu][papel]=%d\n",papel[0][0]);
	printf("papel[perdeu][tesoura]=%d\n",papel[0][1]);
	printf("papel[perdeu][pedra]=%d\n",papel[0][2]);
	printf("papel[empate][papel]=%d\n",papel[1][0]);
	printf("papel[empate][tesoura]=%d\n",papel[1][1]);
	printf("papel[empate][pedra]=%d\n",papel[1][2]);
	printf("papel[ganhou][papel]=%d\n",papel[2][0]);
	printf("papel[ganhou][tesoura]=%d\n",papel[2][1]);
	printf("papel[ganhou][pedra]=%d\n",papel[2][2]);
}
