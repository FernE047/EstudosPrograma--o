#include<stdio.h>
int main(){
	int b,n;
	FILE *arq=fopen("raizes","w");
	for(b=2;b<=500;b++){
		n=0;
		while(((2*n)+(n*n/b))<b){
			n++;
		}
		fprintf(arq,"base %d: %d\n",b,n-1);
	}
}
