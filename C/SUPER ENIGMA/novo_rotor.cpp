#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

int control,random,a,b,teste,tester[67],ves;
char rotor[67];
FILE *arq=fopen("save/novo rotor","w");

int main(){
	srand(time(NULL));
	for(ves=0;ves<=6;ves++){
	fprintf(arq,"\n\n");
	b=0;
	for(teste=0;teste<=66;teste++){
		rotor[teste]=219;
		tester[teste]=219;
	}
	for(control=66;control>=0;control--){
		a=1;
		while(a){
			a=0;
			random=(rand()%67);
			switch(random){
				case 0:
					random=65;
				break;
				case 1:
					random=66;
				break;
				case 2:
					random=67;
				break;
				case 3:
					random=68;
				break;
				case 4:
					random=69;
				break;
				case 5:
					random=70;
				break;
				case 6:
					random=71;
				break;
				case 7:
					random=72;
				break;
				case 8:
					random=73;
				break;
				case 9:
					random=74;
				break;
				case 10:
					random=75;
				break;
				case 11:
					random=76;
				break;
				case 12:
					random=77;
				break;
				case 13:
					random=78;
				break;
				case 14:
					random=79;
				break;
				case 15:
					random=80;
				break;
				case 16:
					random=81;
				break;
				case 17:
					random=82;
				break;
				case 18:
					random=83;
				break;
				case 19:
					random=84;
				break;
				case 20:
					random=85;
				break;
				case 21:
					random=86;
				break;
				case 22:
					random=87;
				break;
				case 23:
					random=88;
				break;
				case 24:
					random=89;
				break;
				case 25:
					random=90;
				break;
				case 26:
					random=97;
				break;
				case 27:
					random=98;
				break;
				case 28:
					random=99;
				break;
				case 29:
					random=100;
				break;
				case 30:
					random=101;
				break;
				case 31:
					random=102;
				break;
				case 32:
				break;
				case 33:
				break;
				case 34:
					random=103;
				break;
				case 35:
					random=104;
				break;
				case 36:
					random=105;
				break;
				case 37:
					random=106;
				break;
				case 38:
					random=107;
				break;
				case 39:
					random=108;
				break;
				case 40:
					random=109;
				break;
				case 41:
					random=110;
				break;
				case 42:
					random=111;
				break;
				case 43:
					random=112;
				break;
				case 44:
				break;
				case 45:
					random=113;
				break;
				case 46:
				break;
				case 47:
					random=114;
				break;
				case 48:
				break;
				case 49:
				break;
				case 50:
				break;
				case 51:
				break;
				case 52:
				break;
				case 53:
				break;
				case 54:
				break;
				case 55:
				break;
				case 56:
				break;
				case 57:
				break;
				case 58:
					random=115;
				break;
				case 59:
					random=116;
				break;
				case 60:
					random=117;
				break;
				case 61:
					random=118;
				break;
				case 62:
					random=119;
				break;
				case 63:
				break;
				case 64:
					random=120;
				break;
				case 65:
					random=121;
				break;
				case 66:
					random=122;
				break;
			}
			for(teste=0;teste<=66;teste++){
				if(tester[teste]==random)a=1;
			}
		}
		rotor[b]=random;
		tester[b]=random;
		fprintf(arq,"%c",rotor[b]);
		printf("%c",rotor[b]);
		b++;
	}
	}
}


