#include<windows.h>
#include<stdio.h>
#include<conio.h>

int tabdirecao[8][8];
int tabpreencher[8][8];
int xdecisao[64],ydecisao[64];
int conty,contx,x=0,y=0,passos=0,dir;



int main(){
	for(conty=0;conty<=7;conty++){
		for(contx=0;contx<=7;contx++){
			tabdirecao[contx][conty]=8;
			tabpreencher[contx][conty]=0;
		}
	}
	for(contx=0;contx<=63;contx++){
		xdecisao[contx]=0;
		ydecisao[contx]=0;
	}
	passos=0;
	do{
		dir=tabdirecao[x][y];
		switch(dir){
			xdecisao[passos]=x
			ydecisao[passos]=y
			case 8:
				if((y>=2)and(x>=1)){
					if(tabpreencher[x-1][y-2]==0){
						passos++
						tabdirecao[x][y]++;
						
					}else{
						
					}
				}else{
					
				}
			break;
			case 7:
				if((y>=2)and(x<=6)){
					
				}else{
					
				}
			break;
			case 6:
				if((y>=1)and(x<=5)){
					
				}else{
					
				}
			break;
			case 5:
				if((y<=6)and(x<=5)){
					
				}else{
					
				}
			break;
			case 4:
				if((y<=5)and(x<=6)){
					
				}else{
					
				}
			break;
			case 3:
				if((y<=5)and(x>=1)){
					
				}else{
					
				}
			break;
			case 2:
				if((y<=6)and(x>=2)){
					
				}else{
					
				}
			break;
			case 1:
				if((y>=1)and(x>=2)){
					
				}else{
					
				}
			break;
			case 0:
				
			break;
		}
		system("cls");	
	}while(passos!=63);
}


