#include <stdio.h>
#include <math.h>
#define LIMITE 10

double matriz[11][2];
int count,loop;
long int number[6];

int teste(){
	if(((number[0]==matriz[0][0])and(number[1]==matriz[1][0])and(number[2]==matriz[2][0]))and((number[3]==matriz[3][0])and(number[4]==matriz[4][0])and(number[5]==matriz[5][0]))){
		if(((matriz[0][0]==0)and(matriz[1][0]==0)and(matriz[2][0]==0))and((matriz[3][0]==0)and(matriz[4][0]==0)and(matriz[5][0]==0))){
			return(0);
		}else{
			return(1);
		}
	}else{
		return(0);
	}
}

int main(){
	for(number[0]=0;number[0]<=LIMITE;number[0]++){
		matriz[0][0]=number[0];
		matriz[10][0]=number[0];
		for(number[1]=0;number[1]<=LIMITE;number[1]++){
			matriz[1][0]=number[1];
			matriz[9][0]=number[1];
			for(number[2]=0;number[2]<=LIMITE;number[2]++){
				matriz[2][0]=number[2];
				matriz[8][0]=number[2];
				for(number[3]=0;number[3]<=LIMITE;number[3]++){
					matriz[3][0]=number[3];
					matriz[7][0]=number[3];
					for(number[4]=0;number[4]<=LIMITE;number[4]++){
						matriz[4][0]=number[4];
						matriz[6][0]=number[4];
						for(number[5]=0;number[5]<=LIMITE;number[5]++){
							matriz[5][0]=number[5];
							for(count=0;count<=10;count++){
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
							}
							printf("%c:%ld\n\n",70,number[5]);
							if(teste())break;
						}
						if(teste())break;
					}
					if(teste())break;
				}
				if(teste())break;
			}
			if(teste())break;
		}
		if(teste())break;
	}
	printf("\n\nsoma:%lf\n\n",matriz[0][1]+matriz[1][1]+matriz[2][1]+matriz[3][1]+matriz[4][1]+matriz[5][1]+matriz[6][1]+matriz[7][1]+matriz[8][1]+matriz[9][1]+matriz[10][1]);
	for(count=0;count<=10;count++){
		printf("%c 1:%lf\n%c 2:%ld\n",count+65,matriz[count][0],count+65,number[(count<5?count:(10-count))]);
	}
	printf("\nFIM");
}
