#include<stdio.h>
int main(){
	char matriz[11][21];
	int count=0,count2=0;
	for (count=0;count<=9;count++){
		for(count2=0;count2<=19;count2++){
			if(count<8){
				matriz[count][count2]=' ';
			}else{
				matriz[count][count2]='X';
			}
		}
	}
	matriz[3][5]=2;
	for (count=0;count<=9;count++){
		for (count2=0;count2<=19;count2++){
			if(count2==19){
				printf("%c\n",matriz[count][count2]);
			}else{
				printf("%c",matriz[count][count2]);
			}
		}
	}
}
