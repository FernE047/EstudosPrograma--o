#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
void mgotoxy(int x,int y)
{
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
int ifmonstruoso(int x,int y)
{
	if((x==1&&y==1)||(x==4&&y==1)||(x==8&&y==1)||(x==10&&y==1)||(x==14&&y==1)||(x==17&&y==1)||(x==1&&y==4)||(x==4&&y==4)||(x==6&&y==4)||(x==8&&y==4)||(x==10&&y==4)||(x==12&&y==4)||(x==14&&y==4)||(x==17&&y==4)||(x==1&&y==6)||(x==4&&y==6)||(x==6&&y==6)||(x==8&&y==6)||(x==10&&y==6)||(x==12&&y==6)||(x==14&&y==6)||(x==17&&y==6)||(x==6&&y==8)||(x==8&&y==8)||(x==10&&y==8)||(x==12&&y==8)||(x==4&&y==10)||(x==6&&y==10)||(x==12&&y==10)||(x==14&&y==10)||(x==6&&y==12)||(x==8&&y==12)||(x==10&&y==12)||(x==12&&y==12)||(x==1&&y==14)||(x==4&&y==14)||(x==6&&y==14)||(x==8&&y==14)||(x==10&&y==14)||(x==12&&y==14)||(x==14&&y==14)||(x==17&&y==14)||(x==1&&y==16)||(x==4&&y==16)||(x==6&&y==16)||(x==8&&y==16)||(x==10&&y==16)||(x==12&&y==16)||(x==14&&y==16)||(x==17&&y==16)||(x==1&&y==19)||(x==4&&y==19)||(x==8&&y==19)||(x==10&&y==19)||(x==14&&y==19)||(x==17&&y==19)){
		return(1);
	}else{
		return(0);
	}
}
int main(){
	int px,py,pont=0,d=3,vidas=3;	/*variaveis do pac man*/
	int fx,fy,fx2,fy2,fx3,fy3,fx4,fy4,inc=0,d1=0,d2=2,d3=3,d4=3,dirpos[5],dirquant,poss;	/*variaveis dos fantasmas 1, 2, 3, 4*/
	char tecla='a',matriz[21][20];
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,187);
	printf("%c********%c********%c\n",186,186,186);
	printf("%c*%c%c*%c%c%c*%c*%c%c%c*%c%c*%c\n",186,201,187,201,205,187,186,201,205,187,201,187,186);
	printf("%c*%c%c*%c%c%c*%c*%c%c%c*%c%c*%c\n",186,200,188,200,205,188,186,200,205,188,200,188,186);
	printf("%c*****************%c\n",186,186); 
	printf("%c*%c%c*%c*%c%c%c%c%c*%c*%c%c*%c\n",186,205,205,186,205,205,203,205,205,186,205,205,186);
	printf("%c****%c***%c***%c****%c\n",186,186,186,186,186);
	printf("%c%c%c%c*%c%c%c*%c*%c%c%c*%c%c%c%c\n",200,205,205,187,204,205,205,186,205,205,185,201,205,205,188);
	printf("   %c*%c*******%c*%c   \n",186,186,186,186);
	printf("   %c*%c*%c%c%c%c%c*%c*%c   \n",186,186,201,205,6,205,187,186,186);
	printf("   %c***%c%c%c%c%c***%c   \n",186,186,4,5,3,186,186);
	printf("   %c*%c*%c%c%c%c%c*%c*%c   \n",186,186,200,205,205,205,188,186,186);
	printf("   %c*%c***%c***%c*%c   \n",186,186,1,186,186);
	printf("%c%c%c%c*%c%c%c*%c*%c%c%c*%c%c%c%c\n",201,205,205,188,204,205,205,186,205,205,185,200,205,205,187);
	printf("%c****%c***%c***%c****%c\n",186,186,186,186,186);	
	printf("%c*%c%c*%c*%c%c%c%c%c*%c*%c%c*%c\n",186,205,205,186,205,205,202,205,205,186,205,205,186);
	printf("%c*****************%c\n",186,186); 
	printf("%c*%c%c*%c%c%c*%c*%c%c%c*%c%c*%c\n",186,201,187,201,205,187,186,201,205,187,201,187,186);
	printf("%c*%c%c*%c%c%c*%c*%c%c%c*%c%c*%c\n",186,200,188,200,205,188,186,200,205,188,200,188,186);
	printf("%c********%c********%c\n",186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,188);
	printf("pontuacao:         \n");
	printf("vidas:             \n");
	strcpy(matriz[0],"XXXXXXXXXXXXXXXXXXX");
	strcpy(matriz[1],"X********X********X");
	strcpy(matriz[2],"X*XX*XXX*X*XXX*XX*X");
	strcpy(matriz[3],"X*XX*XXX*X*XXX*XX*X");
	strcpy(matriz[4],"X*****************X");
	strcpy(matriz[5],"X*XX*X*XXXXX*X*XX*X");
	strcpy(matriz[6],"X****X***X***X****X");
	strcpy(matriz[7],"XXXX*XXX*X*XXX*XXXX");
	strcpy(matriz[8],"   X*X*******X*X   ");
	strcpy(matriz[9],"   X*X*XX1XX*X*X   ");
	strcpy(matriz[10],"   X***X423X***X   ");
	strcpy(matriz[11],"   X*X*XXXXX*X*X   ");
	strcpy(matriz[12],"   X*X*** ***X*X   ");
	strcpy(matriz[13],"XXXX*XXX*X*XXX*XXXX");
	strcpy(matriz[14],"X****X***X***X****X");
	strcpy(matriz[15],"X*XX*X*XXXXX*X*XX*X");
	strcpy(matriz[16],"X*****************X");
	strcpy(matriz[17],"X*XX*XXX*X*XXX*XX*X");
	strcpy(matriz[18],"X*XX*XXX*X*XXX*XX*X");
	strcpy(matriz[19],"X********X********X");
	strcpy(matriz[20],"XXXXXXXXXXXXXXXXXXX");
	px=9;
	py=12;
	fx=9;
	fy=9;
	fx2=9;
	fy2=10;
	fx3=10;
	fy3=10;
	fx4=8;
	fy4=10;
    srand(time(NULL));
	while(tecla!='s'&&vidas>=0&&pont<1690){
		while(tecla!='s'&&!(tecla=kbhit())&&vidas>=0&&pont<1690){
			mgotoxy(px,py);
			printf(" ");
			if(matriz[py][px+1]!='X'&&d==0)px++;
			if(matriz[py-1][px]!='X'&&d==1)py--;
			if(matriz[py][px-1]!='X'&&d==2)px--;
			if(matriz[py+1][px]!='X'&&d==3)py++;
			if(matriz[py][px]=='*')pont+=10;
			if(matriz[py][px]=='*')matriz[py][px]=' ';
			if((py==fy&&px==fx)||(py==fy2&&px==fx2)||(py==fy3&&px==fx3)||(py==fy4&&px==fx4)){
				vidas--;
				px=9;
				py=12;
			}
			matriz[py][px]=' ';
			mgotoxy(px,py);
			printf("%c",1);
			mgotoxy(10,21);
			printf("%d",pont);
			mgotoxy(6,22);
			printf("%d",vidas);
			mgotoxy(fx,fy);
			printf(" ");
			mgotoxy(fx2,fy2);
			printf(" ");
			mgotoxy(fx3,fy3);
			printf(" ");
			mgotoxy(fx4,fy4);
			printf(" ");
			if(inc!=12)inc++;
			if(inc>0&&inc<12){
				mgotoxy(fx,fy);
				printf("*");
				mgotoxy(fx2,fy2);
				printf("*");
				mgotoxy(fx3,fy3);
				printf("*");
				mgotoxy(fx4,fy4);
				printf("*");
				switch(inc){
					case 1:
						fy--;
						fy2--;
						mgotoxy(fx3,fy3);
						printf(" ");
						fx3--;
					break;
					case 2:
						fx++;
						fy2--;
						fy3--;
						mgotoxy(fx4,fy4);
						printf(" ");
						fx4++;
					break;
					case 3:
						fy--;
						fx2--;
						fy3--;
						mgotoxy(fx4,fy4);
						printf(" ");
						fy4--;
					break;
					case 4:
						fy--;
						fy2--;
						fx3++;
						mgotoxy(fx4,fy4);
						printf("%c",205);
						matriz[fy4][fx4]='X';
						fy4--;
					break;
					case 5:
						fx++;
						fy2--;
						fx3++;
						fx4--;
					break;
					case 6:
						fx++;
						fx2--;
						fx3++;
						fx4--;
					break;
					case 7:
						fy--;
						fx2--;
						fy3++;
						fx4--;
					break;
					case 8:
						fy--;
						fy2--;
						fy3++;
						fy4++;
					break;
					case 9:
						fx++;
						fy2--;
						fx3++;
						fy4++;
					break;
					case 10:
						fx++;
						fx2--;
						fx3++;
						fx4--;
					break;
					case 11:
						fx++;
						fx2--;
						fy3++;
						fx4--;
					break;
				}
			}else{
				if(ifmonstruoso(fx,fy)){
					dirquant=0;
					if(matriz[fy-1][fx]!='X'){
						dirquant++;
						dirpos[dirquant]=1;
					}
					if(matriz[fy+1][fx]!='X'){
						dirquant++;
						dirpos[dirquant]=3;
					}
					if(matriz[fy][fx-1]!='X'){
						dirquant++;
						dirpos[dirquant]=2;
					}
					if(matriz[fy][fx+1]!='X'){
						dirquant++;
						dirpos[dirquant]=0;
					}
					poss=(rand()%dirquant)+1;
					if(poss==1)d1=dirpos[poss];
					if(poss==2)d1=dirpos[poss];
					if(poss==3)d1=dirpos[poss];
					if(poss==4)d1=dirpos[poss];
				}
				if(ifmonstruoso(fx2,fy2)){
					dirquant=0;
					if(matriz[fy2-1][fx2]!='X'){
						dirquant++;
						dirpos[dirquant]=1;
					}
					if(matriz[fy2+1][fx2]!='X'){
						dirquant++;
						dirpos[dirquant]=3;
					}
					if(matriz[fy2][fx2-1]!='X'){
						dirquant++;
						dirpos[dirquant]=2;
					}
					if(matriz[fy2][fx2+1]!='X'){
						dirquant++;
						dirpos[dirquant]=0;
					}
					poss=(rand()%dirquant)+1;
					if(poss==1)d2=dirpos[poss];
					if(poss==2)d2=dirpos[poss];
					if(poss==3)d2=dirpos[poss];
					if(poss==4)d2=dirpos[poss];
				}
				if(ifmonstruoso(fx3,fy3)){
					dirquant=0;
					if(matriz[fy3-1][fx3]!='X'){
						dirquant++;
						dirpos[dirquant]=1;
					}
					if(matriz[fy3+1][fx3]!='X'){
						dirquant++;
						dirpos[dirquant]=3;
					}
					if(matriz[fy3][fx3-1]!='X'){
						dirquant++;
						dirpos[dirquant]=2;
					}
					if(matriz[fy3][fx3+1]!='X'){
						dirquant++;
						dirpos[dirquant]=0;
					}
					poss=(rand()%dirquant)+1;
					if(poss==1)d3=dirpos[poss];
					if(poss==2)d3=dirpos[poss];
					if(poss==3)d3=dirpos[poss];
					if(poss==4)d3=dirpos[poss];
				}
				if(ifmonstruoso(fx,fy)){
					dirquant=0;
					if(matriz[fy4-1][fx4]!='X'){
						dirquant++;
						dirpos[dirquant]=1;
					}
					if(matriz[fy4+1][fx4]!='X'){
						dirquant++;
						dirpos[dirquant]=3;
					}
					if(matriz[fy4][fx4-1]!='X'){
						dirquant++;
						dirpos[dirquant]=2;
					}
					if(matriz[fy4][fx4+1]!='X'){
						dirquant++;
						dirpos[dirquant]=0;
					}
					poss=(rand()%dirquant)+1;
					if(poss==1)d4=dirpos[poss];
					if(poss==2)d4=dirpos[poss];
					if(poss==3)d4=dirpos[poss];
					if(poss==4)d4=dirpos[poss];
				}
				if(matriz[fy][fx]=='*'){
					mgotoxy(fx,fy);
					printf("*");
				}
				if(matriz[fy2][fx2]=='*'){
					mgotoxy(fx2,fy2);
					printf("*");
				}
				if(matriz[fy3][fx3]=='*'){
					mgotoxy(fx3,fy3);
					printf("*");
				}
				if(matriz[fy4][fx4]=='*'){
					mgotoxy(fx4,fy4);
					printf("*");
				}
				if(matriz[fy][fx+1]!='X'&&d1==0)fx++;
				if(matriz[fy-1][fx]!='X'&&d1==1)fy--;
				if(matriz[fy][fx-1]!='X'&&d1==2)fx--;
				if(matriz[fy+1][fx]!='X'&&d1==3)fy++;
				if(matriz[fy2][fx2+1]!='X'&&d2==0)fx2++;
				if(matriz[fy2-1][fx2]!='X'&&d2==1)fy2--;
				if(matriz[fy2][fx2-1]!='X'&&d2==2)fx2--;
				if(matriz[fy2+1][fx2]!='X'&&d2==3)fy2++;
				if(matriz[fy3][fx3+1]!='X'&&d3==0)fx3++;
				if(matriz[fy3-1][fx3]!='X'&&d3==1)fy3--;
				if(matriz[fy3][fx3-1]!='X'&&d3==2)fx3--;
				if(matriz[fy3+1][fx3]!='X'&&d3==3)fy3++;
				if(matriz[fy4][fx4+1]!='X'&&d4==0)fx4++;
				if(matriz[fy4-1][fx4]!='X'&&d4==1)fy4--;
				if(matriz[fy4][fx4-1]!='X'&&d4==2)fx4--;
				if(matriz[fy4+1][fx4]!='X'&&d4==3)fy4++;
			}
			if((py==fy&&px==fx)||(py==fy2&&px==fx2)||(py==fy3&&px==fx3)||(py==fy4&&px==fx4)){
				vidas--;
				px=9;
				py=12;
			}
			mgotoxy(fx,fy);
			printf("%c",6);
			mgotoxy(fx2,fy2);
			printf("%c",5);
			mgotoxy(fx3,fy3);
			printf("%c",3);
			mgotoxy(fx4,fy4);
			printf("%c",4);
			Sleep(250);
		}
		if(tecla!='s')tecla=getch();
		if(tecla=='M')d=0;
		if(tecla=='H')d=1;
		if(tecla=='K')d=2;
		if(tecla=='P')d=3;
	}
	system("pause");
}
