#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
int main(){
	int count,count2,posxp,posyp,posxf[4],posyf[4],vidas=3,pont=0,momento=0,eae[4],comportamento,direcao[4];
	char matriz[22][20],tecla;
	for (count=0;count<=21;count++){
		for(count2=0;count2<=19;count2++){
			matriz[count][count2]=' ';
		}
	}
	matriz[0][0]=201;
	matriz[2][2]=201;
	matriz[2][5]=201;
	matriz[2][11]=201;
	matriz[2][15]=201;
	matriz[9][7]=201;
	matriz[7][15]=201;
	matriz[13][0]=201;
	matriz[17][2]=201;
	matriz[17][5]=201;
	matriz[17][11]=201;
	matriz[17][15]=201;/*¬invertido*/
	matriz[0][18]=187;
	matriz[2][3]=187;
	matriz[2][7]=187;
	matriz[2][13]=187;
	matriz[2][16]=187;
	matriz[7][3]=187;
	matriz[9][11]=187;
	matriz[13][18]=187;
	matriz[17][3]=187;
	matriz[17][7]=187;
	matriz[17][13]=187;
	matriz[17][16]=187;/*¬*/
	matriz[3][2]=200;
	matriz[3][5]=200;
	matriz[3][11]=200;
	matriz[3][15]=200;
	matriz[7][0]=200;
	matriz[11][7]=200;
	matriz[13][15]=200;
	matriz[18][2]=200;
	matriz[18][5]=200;
	matriz[18][11]=200;
	matriz[18][15]=200;
	matriz[20][0]=200;/*|_*/
	matriz[3][3]=188;
	matriz[3][7]=188;
	matriz[3][13]=188;
	matriz[3][16]=188;
	matriz[7][18]=188;
	matriz[11][11]=188;
	matriz[13][3]=188;
	matriz[18][3]=188;
	matriz[18][7]=188;
	matriz[18][13]=188;
	matriz[18][16]=188;
	matriz[20][18]=188;/*_|*/
	for(count=1;count<=17;count++){
		matriz[0][count]=205;/*_*/
	}
	matriz[0][9]=203;  /*T*/
	matriz[1][0]=186; /*|*/
	matriz[1][18]=186;
	matriz[2][0]=186;
	matriz[2][18]=186;
	matriz[3][0]=186;
	matriz[3][18]=186;
	matriz[4][0]=186;
	matriz[4][18]=186;
	matriz[5][0]=186;
	matriz[5][18]=186;
	matriz[6][0]=186;
	matriz[6][18]=186;
	matriz[6][5]=186;
	matriz[6][9]=186;
	matriz[6][13]=186;
	matriz[5][5]=186;
	matriz[5][13]=186;
	matriz[5][9]=203;
	matriz[5][8]=205;
	matriz[5][10]=205;
	matriz[1][9]=186;
	matriz[2][9]=186;
	matriz[3][9]=186;
	matriz[5][7]=205;
	matriz[5][11]=205;
	matriz[2][6]=205;
	matriz[3][6]=205;
	matriz[2][12]=205;
	matriz[3][12]=205;
	matriz[7][6]=205;
	matriz[7][7]=205;
	matriz[7][1]=205;
	matriz[7][2]=205;
	matriz[7][11]=205;
	matriz[7][12]=205;
	matriz[7][16]=205;
	matriz[7][17]=205;
	matriz[7][5]=204;
	matriz[7][13]=185;
	matriz[5][3]=205;
	matriz[5][2]=205;
	matriz[5][15]=205;
	matriz[5][16]=205;
	matriz[8][3]=186;
	matriz[9][3]=186;
	matriz[10][3]=186;
	matriz[11][3]=186;
	matriz[12][3]=186;
	matriz[8][15]=186;
	matriz[9][15]=186;
	matriz[10][15]=186;
	matriz[11][15]=186;
	matriz[12][15]=186;
	matriz[9][13]=186;
	matriz[9][5]=186;
	matriz[8][5]=186;
	matriz[8][13]=186;
	matriz[10][7]=186;
	matriz[10][11]=186;
	matriz[7][9]=186;
	matriz[11][8]=205;
	matriz[11][9]=205;
	matriz[11][10]=205;
	matriz[9][8]=205;
	matriz[9][10]=205;
	matriz[11][5]=186;
	matriz[12][5]=186;
	matriz[14][5]=186;
	matriz[15][5]=186;
	matriz[11][13]=186;
	matriz[12][13]=186;
	matriz[14][13]=186;
	matriz[15][13]=186;
	matriz[13][13]=185;
	matriz[13][5]=204;
	matriz[13][6]=205;
	matriz[13][7]=205;
	matriz[13][11]=205;
	matriz[13][12]=205;
	matriz[13][1]=205;
	matriz[13][2]=205;
	matriz[13][16]=205;
	matriz[13][17]=205;
	matriz[15][7]=205;
	matriz[15][8]=205;
	matriz[15][10]=205;
	matriz[15][11]=205;
	matriz[13][9]=186;
	matriz[14][9]=186;
	matriz[15][9]=202;
	matriz[17][9]=186;
	matriz[18][9]=186;
	matriz[19][9]=186;
	matriz[20][9]=202;
	matriz[15][2]=205;
	matriz[15][3]=205;
	matriz[15][15]=205;
	matriz[15][16]=205;
	matriz[17][6]=205;
	matriz[18][6]=205;
	matriz[17][12]=205;
	matriz[18][12]=205;
	matriz[12][9]=1;
	matriz[10][9]=3;
	matriz[10][8]=4;
	matriz[10][10]=5;
	matriz[9][9]=6;
	for(count=14;count<=19;count++){
		matriz[count][0]=186;
		matriz[count][18]=186;
	}
	for(count=1;count<=8;count++){
		matriz[20][count]=205;
		matriz[20][count+9]=205;
	}
	for (count=0;count<=20;count++){
		for(count2=0;count2<=18;count2++){
			if(matriz[count][count2]==' '){
				matriz[count][count2]='*';
			}
		}
	}
	for(count=0;count<=2;count++){
		matriz[8][count]=' ';
		matriz[9][count]=' ';
		matriz[10][count]=' ';
		matriz[11][count]=' ';
		matriz[12][count]=' ';
	}
	for(count=16;count<=18;count++){
		matriz[8][count]=' ';
		matriz[9][count]=' ';
		matriz[10][count]=' ';
		matriz[11][count]=' ';
		matriz[12][count]=' ';
	}
	for (count=0;count<=21;count++){
		for(count2=0;count2<=19;count2++){
			printf("%c",matriz[count][count2]);
			if(count2==19)printf("\n");
		}
	}
	posxp=9;
	posyp=12;
	posxf[1]=9;
	posxf[2]=8;
	posxf[3]=10;
	posxf[4]=9;
	posyf[1]=10;
	posyf[2]=10;
	posyf[3]=10;
	posyf[4]=9;
	vidas=0;
	srand( (unsigned)time(NULL) );
	while(tecla!='e'){
		system("cls");
		printf("pontuacao:%d\n",pont);
		for (count=0;count<=21;count++){
			for(count2=0;count2<=19;count2++){
				printf("%c",matriz[count][count2]);
				if(count2==19)printf("\n");
			}
		}
		tecla=getch();
		switch(tecla){
			case 'a':
				if((matriz[posyp][posxp-1]==' ')||(matriz[posyp][posxp-1]=='*')||(matriz[posyp][posxp-1]==3)||(matriz[posyp][posxp-1]==4)||(matriz[posyp][posxp-1]==5)||(matriz[posyp][posxp-1]==6)){
					if((matriz[posyp][posxp-1]==3)||(matriz[posyp][posxp-1]==4)||(matriz[posyp][posxp-1]==5)||(matriz[posyp][posxp-1]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp][posxp-1]=='*')pont++;
						matriz[posyp][posxp-1]=2;
						matriz[posyp][posxp]=' ';
						posxp--;
					}else{
						if(matriz[posyp][posxp-1]=='*')pont++;
						matriz[posyp][posxp-1]=1;
						matriz[posyp][posxp]=' ';
						posxp--;
					}
				}
				break;
			case 'A':
				if((matriz[posyp][posxp-1]==' ')||(matriz[posyp][posxp-1]=='*')||(matriz[posyp][posxp-1]==3)||(matriz[posyp][posxp-1]==4)||(matriz[posyp][posxp-1]==5)||(matriz[posyp][posxp-1]==6)){
					if((matriz[posyp][posxp-1]==3)||(matriz[posyp][posxp-1]==4)||(matriz[posyp][posxp-1]==5)||(matriz[posyp][posxp-1]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp][posxp-1]=='*')pont++;
						matriz[posyp][posxp-1]=2;
						matriz[posyp][posxp]=' ';
						posxp--;
					}else{
						if(matriz[posyp][posxp-1]=='*')pont++;
						matriz[posyp][posxp-1]=1;
						matriz[posyp][posxp]=' ';
						posxp--;
					}
				}
				break;
			case 's':
				if((matriz[posyp+1][posxp]==' ')||(matriz[posyp+1][posxp]=='*')||(matriz[posyp+1][posxp]==3)||(matriz[posyp+1][posxp]==4)||(matriz[posyp+1][posxp]==5)||(matriz[posyp+1][posxp]==6)){		
					if((matriz[posyp+1][posxp]==3)||(matriz[posyp+1][posxp]==4)||(matriz[posyp+1][posxp]==5)||(matriz[posyp+1][posxp]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp+1][posxp]=='*')pont++;
						matriz[posyp+1][posxp]=2;
						matriz[posyp][posxp]=' ';
						posyp++;
					}else{
						if(matriz[posyp+1][posxp]=='*')pont++;
						matriz[posyp+1][posxp]=1;
						matriz[posyp][posxp]=' ';
						posyp++;
					}
				}
				break;
			case 'S':
				if((matriz[posyp+1][posxp]==' ')||(matriz[posyp+1][posxp]=='*')||(matriz[posyp+1][posxp]==3)||(matriz[posyp+1][posxp]==4)||(matriz[posyp+1][posxp]==5)||(matriz[posyp+1][posxp]==6)){		
					if((matriz[posyp+1][posxp]==3)||(matriz[posyp+1][posxp]==4)||(matriz[posyp+1][posxp]==5)||(matriz[posyp+1][posxp]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp+1][posxp]=='*')pont++;
						matriz[posyp+1][posxp]=2;
						matriz[posyp][posxp]=' ';
						posyp++;
					}else{
						if(matriz[posyp+1][posxp]=='*')pont++;
						matriz[posyp+1][posxp]=1;
						matriz[posyp][posxp]=' ';
						posyp++;
					}
				}
				break;
			case 'w':
				if((matriz[posyp-1][posxp]==' ')||(matriz[posyp-1][posxp]=='*')||(matriz[posyp-1][posxp]==3)||(matriz[posyp-1][posxp]==4)||(matriz[posyp-1][posxp]==5)||(matriz[posyp-1][posxp]==6)){		
					if((matriz[posyp-1][posxp]==3)||(matriz[posyp-1][posxp]==4)||(matriz[posyp-1][posxp]==5)||(matriz[posyp-1][posxp]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp-1][posxp]=='*')pont++;
						matriz[posyp-1][posxp]=2;
						matriz[posyp][posxp]=' ';
						posyp--;
					}else{
						if(matriz[posyp-1][posxp]=='*')pont++;
						matriz[posyp-1][posxp]=1;
						matriz[posyp][posxp]=' ';
						posyp--;
					}
				}
				break;
			case 'W':
				if((matriz[posyp-1][posxp]==' ')||(matriz[posyp-1][posxp]=='*')||(matriz[posyp-1][posxp]==3)||(matriz[posyp-1][posxp]==4)||(matriz[posyp-1][posxp]==5)||(matriz[posyp-1][posxp]==6)){		
					if((matriz[posyp-1][posxp]==3)||(matriz[posyp-1][posxp]==4)||(matriz[posyp-1][posxp]==5)||(matriz[posyp-1][posxp]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						posyp=12;
						posxp=9;
						vidas--;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp-1][posxp]=='*')pont++;
						matriz[posyp-1][posxp]=2;
						matriz[posyp][posxp]=' ';
						posyp--;
					}else{
						if(matriz[posyp-1][posxp]=='*')pont++;
						matriz[posyp-1][posxp]=1;
						matriz[posyp][posxp]=' ';
						posyp--;
					}
				}
				
				break;
			case 'd':
				if((matriz[posyp][posxp+1]==' ')||(matriz[posyp][posxp+1]=='*')||(matriz[posyp][posxp+1]==3)||(matriz[posyp][posxp+1]==4)||(matriz[posyp][posxp+1]==5)||(matriz[posyp][posxp+1]==6)){
					if((matriz[posyp][posxp+1]==3)||(matriz[posyp][posxp+1]==4)||(matriz[posyp][posxp+1]==5)||(matriz[posyp][posxp+1]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						vidas--;
						posyp=12;
						posxp=9;
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp][posxp+1]=='*')pont++;
						matriz[posyp][posxp+1]=2;
						matriz[posyp][posxp]=' ';
						posxp++;
					}else{
						if(matriz[posyp][posxp+1]=='*')pont++;
						matriz[posyp][posxp+1]=1;
						matriz[posyp][posxp]=' ';
						posxp++;
					}
				}
				break;
			case 'D':
				if((matriz[posyp][posxp+1]==' ')||(matriz[posyp][posxp+1]=='*')||(matriz[posyp][posxp+1]==3)||(matriz[posyp][posxp+1]==4)||(matriz[posyp][posxp+1]==5)||(matriz[posyp][posxp+1]==6)){
					if((matriz[posyp][posxp+1]==3)||(matriz[posyp][posxp+1]==4)||(matriz[posyp][posxp+1]==5)||(matriz[posyp][posxp+1]==6)){
						matriz[posyp][posxp]=' ';
						matriz[12][9]=1;
						vidas--;
						posyp=12;
						posxp=9;					
					}else if(matriz[posyp][posxp]==1){
						if(matriz[posyp][posxp+1]=='*')pont++;
						matriz[posyp][posxp+1]=2;
						matriz[posyp][posxp]=' ';
						posxp++;
					}else{
						if(matriz[posyp][posxp+1]=='*')pont++;
						matriz[posyp][posxp+1]=1;
						matriz[posyp][posxp]=' ';
						posxp++;
					}
				}
			break;
		}
		momento++;
		switch(momento){
			case 1:
				matriz[posyf[4]][posxf[4]]=' ';
				matriz[posyf[4]-1][posxf[4]]=6;
				matriz[posyf[1]][posxf[1]]=' ';
				matriz[posyf[1]-1][posxf[1]]=3;
				break;
		}
	}
}
