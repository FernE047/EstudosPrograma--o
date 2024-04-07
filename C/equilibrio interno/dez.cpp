#include <stdio.h>
#include <math.h>
#define PRECISAO 0.01

double matriz[11][2];
int count,loop,number,k;

int teste(){
	for(loop=0;loop<=10;loop++){
		if(fmod(matriz[loop][1],1)<=PRECISAO){
			return(0);
		}
	}
	return(1);
}

int main(){
	number=1;
	for(count=0;count<=10;count++){
		matriz[count][1]=0.999999;
	}
	while(teste()){
		for(count=0;count<=10;count++){
			matriz[count][0]=0;
		}
		matriz[5][0]=number;
		for(count=0;count<=100;count++){
			matriz[0][1]=matriz[0][0]/2+matriz[1][0]/2+matriz[2][0]/4+matriz[3][0]/6+matriz[4][0]/8+matriz[5][0]/10+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[1][1]=matriz[0][0]/20+matriz[2][0]/4+matriz[3][0]/6+matriz[4][0]/8+matriz[5][0]/10+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[2][1]=matriz[0][0]/20+matriz[1][0]/18+matriz[3][0]/6+matriz[4][0]/8+matriz[5][0]/10+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[3][1]=matriz[0][0]/20+matriz[1][0]/18+matriz[2][0]/16+matriz[4][0]/8+matriz[5][0]/10+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[4][1]=matriz[0][0]/20+matriz[1][0]/18+matriz[2][0]/16+matriz[3][0]/14+matriz[5][0]/10+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[5][1]=matriz[0][0]/20+matriz[1][0]/18+matriz[2][0]/16+matriz[3][0]/14+matriz[4][0]/12+matriz[6][0]/12+matriz[7][0]/14+matriz[8][0]/16+matriz[9][0]/18+matriz[10][0]/20;
			matriz[6][1]=matriz[10][0]/20+matriz[9][0]/18+matriz[8][0]/16+matriz[7][0]/14+matriz[5][0]/10+matriz[4][0]/12+matriz[3][0]/14+matriz[2][0]/16+matriz[1][0]/18+matriz[0][0]/20;
			matriz[7][1]=matriz[10][0]/20+matriz[9][0]/18+matriz[8][0]/16+matriz[6][0]/8+matriz[5][0]/10+matriz[4][0]/12+matriz[3][0]/14+matriz[2][0]/16+matriz[1][0]/18+matriz[0][0]/20;
			matriz[8][1]=matriz[10][0]/20+matriz[9][0]/18+matriz[7][0]/6+matriz[6][0]/8+matriz[5][0]/10+matriz[4][0]/12+matriz[3][0]/14+matriz[2][0]/16+matriz[1][0]/18+matriz[0][0]/20;
			matriz[9][1]=matriz[10][0]/20+matriz[8][0]/4+matriz[7][0]/6+matriz[6][0]/8+matriz[5][0]/10+matriz[4][0]/12+matriz[3][0]/14+matriz[2][0]/16+matriz[1][0]/18+matriz[0][0]/20;
			matriz[10][1]=matriz[10][0]/2+matriz[9][0]/2+matriz[8][0]/4+matriz[7][0]/6+matriz[6][0]/8+matriz[5][0]/10+matriz[4][0]/12+matriz[3][0]/14+matriz[2][0]/16+matriz[1][0]/18+matriz[0][0]/20;
			for(loop=0;loop<=10;loop++){
				matriz[loop][0]=matriz[loop][1];
			}
			if((not(teste()))and(count>=4)){
				k=count;
				count=150;
			}
		}
		printf("%d\n",number);
		number++;
	}
	printf("\n\nsoma:%lf\n\n",matriz[0][1]+matriz[1][1]+matriz[2][1]+matriz[3][1]+matriz[4][1]+matriz[5][1]+matriz[6][1]+matriz[7][1]+matriz[8][1]+matriz[9][1]+matriz[10][1]);
	for(count=0;count<=10;count++){
		printf("%c:%lf\n",count+65,matriz[count][1]);
	}
	printf("\n\ncount:%d\nprecisao:%f\nFIM",k,PRECISAO);
}
