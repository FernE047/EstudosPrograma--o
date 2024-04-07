#include<stdio.h>
int main(){
	int b,n,n1,n2;
	FILE *arq=fopen("raizes 2 digitos","w");
	for(b=2;b<=100;b++){
		n=0;
		while(((2*n)+((n*n)/(b*b))<(b*b))){
			n++;
		}
		n--;
		n1=n/b;
		n2=n%b;
		fprintf(arq,"base %d:\n\n numero 1: %d\n numero 2: %d\n\n\n",b,n1,n2);		
	}
}
