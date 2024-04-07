#include<stdio.h>

char d;
FILE *p;
FILE *l;

int main(){
	p=fopen("musica","r");
	l=fopen("tusica","w");
	while( (fscanf(p,"%c",&d))!=EOF ){
		fprintf(l,"%c : %d ",d,d);
		if(d==32)fprintf(l,"\n");
		if(d==10)fprintf(l,"\n\n\n");
	}
}
