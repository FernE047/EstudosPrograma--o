#include<stdio.h>
int main(){
	FILE *arq=fopen("AAAA","r");
	char info[13];
	while((fgets(info, sizeof(info), arq))!=NULL){
		printf("%s",info);
	}
}
