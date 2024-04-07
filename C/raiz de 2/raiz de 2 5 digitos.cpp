#include<stdio.h>
int main(){
	int b,n,n1,n2,n3,n4,n5;
	FILE *arq=fopen("raizes 5 digitos","w");
	for(b=2;b<=25;b++){
		n=0;
		while(((2*n)+((n*n)/(b*b*b*b*b))<(b*b*b*b*b))){
			n++;
		}
		n--;
		n1=n/(b*b*b*b);
		n2=(n/(b*b*b))%b;
		n3=(n/(b*b))%b;
		n4=(n/b)%b;
		n5=n%b;
		fprintf(arq,"base %d:\n\n numero 1: %d\n numero 2: %d\n numero 3: %d\n numero 4: %d\n numero 5: %d\n\n\n",b,n1,n2,n3,n4,n5);		
	}
}
