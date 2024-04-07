#include<stdio.h>
int main(){
	short n1=96,n2,n3,n4,n5,n6;
	unsigned int n7;
	char eu;
	FILE *arq=fopen("AAAA","w");
	while(n1<=122){
		if(((n1-96)%7==0)&&((n1-96)!=0)) {
			fclose(arq);
		}
		if(n1-96==7){
			arq=fopen("BBBB","w");
		}
		if(n1-96==14){
			arq=fopen("CCCC","w");
		}
		if(n1-96==21){
			arq=fopen("DDDD","w");
		}
		n2=96;
		while(n2<=122){
			n3=96;
			while(n3<=122){
				printf("%d\n",n7);
				n4=96;
				while(n4<=122){
					n5=96;
					while(n5<=122){
						n6=96;
						while(n6<=122){
							fprintf(arq,"%d:",n7);
							if(n1==96){
								fprintf(arq," ");
							} 
							else{
								fprintf(arq,"%c",n1);
							}
							if(n2==96){
								fprintf(arq," ");
							} 
							else{
								fprintf(arq,"%c",n2);
							}
							if(n3==96){
								fprintf(arq," ");
							} 
							else{
								fprintf(arq,"%c",n3);
							}
							if(n4==96){
								fprintf(arq," ");
							} 
							else{
								fprintf(arq,"%c",n4);
							}
							if(n5==96){
								fprintf(arq," ");
							} 
							else{
								fprintf(arq,"%c",n5);
							}
							if(n6==96){
								fprintf(arq," \n");
							} 
							else{
								fprintf(arq,"%c\n",n6);
							}
							n7++;
						n6++;
						}
					n5++;
					}
				n4++;
				}
			n3++;
			}
		n2++;
		}
	n1++;
	}
}
