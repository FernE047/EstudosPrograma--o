#include<stdio.h>
int main(){
	int f;
	f=0;
	while(f<256){
		printf("%d:%c\n",f,f);
		f++;
	}
}
