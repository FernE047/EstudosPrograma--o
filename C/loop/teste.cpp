#include<stdio.h>
#include<conio.h>


short int A,B,C,D,E,F=100,G=100,H=100;

int main(){
	for (A=0;((A<10)and(!(A==F)or!(B==G)or!(C==H)));A++){
		for (B=0;((B<10)and(!(A==F)or!(B==G)or!(C==H)));B++){
			for (C=0;((C<10)and(!(A==F)or!(B==G)or!(C==H)));C++){
				if((A==0)&&(B==0)&&(C==0))C++;
				D=A+B;
				E=B+C;
				if(D>=10){
					if(E>=10){
						F=1+(D%10);
						G=(D%10)+1;
						H=1+(E%10);
					}else{
						F=1+(D%10);
						G=(D%10)+E;
						if(G>=10){
							H=G%10;
							G=1;
						}else{
							H=100;
						}
					}
				}else{
					if(E>=10){
						F=D+1;
						G=1+(E%10);
						if(F>=10){
							H=G;
							G=F%10;
							F=1;
						}else{
							H=100;
						}
					}else{
						F=100;
						G=100;
						H=100;
					}
				}
				printf("%d%d%d:%d%d%d\n",A,B,C,F,G,H);
			}
			getch();
		}
	}
}
