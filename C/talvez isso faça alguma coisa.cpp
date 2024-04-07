#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
void mgotoxy(int x,int y)
{
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
int main(){
	char labirinto[24][30]{{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};
	int x,y,cont,quallado;
	system("MODE con cols=30 lines=24");
    srand((unsigned)time(NULL));
    for(y=3;y<=19;y+=2){
    	for(x=3;x<=25;x+=2){
    		for(cont=0;cont<=1;cont++){
    			quallado=(rand()%4);
    			if(quallado==0)labirinto[y][x+1]=' ';
    			if(quallado==1)labirinto[y][x-1]=' ';
    			if(quallado==2)labirinto[y+1][x]=' ';
    			if(quallado==3)labirinto[y-1][x]=' ';
    		}
		}
	}
	x=1;
	for(y=3;y<=19;y+=2){
    	for(cont=0;cont<=1;cont++){
    		quallado=(rand()%3);
    		if(quallado==0)labirinto[y][x+1]=' ';
    		if(quallado==1)labirinto[y-1][x]=' ';
    		if(quallado==2)labirinto[y+1][x]=' ';	
    	}
	}
	x=27;
	for(y=3;y<=19;y+=2){
    	for(cont=0;cont<=1;cont++){
    		quallado=(rand()%3);
    		if(quallado==0)labirinto[y][x-1]=' ';
   		 	if(quallado==1)labirinto[y-1][x]=' ';
    		if(quallado==2)labirinto[y+1][x]=' ';
		}
	}
	y=1;
	for(x=3;x<=25;x+=2){
    	quallado=(rand()%3);
    	if(quallado==0)labirinto[y][x+1]=' ';
    	if(quallado==1)labirinto[y][x-1]=' ';
    	if(quallado==2)labirinto[y+1][x]=' ';
	}
	y=21;
	for(x=3;x<=25;x+=2){
    	quallado=(rand()%3);
    	if(quallado==0)labirinto[y][x+1]=' ';
    	if(quallado==1)labirinto[y][x-1]=' ';
    	if(quallado==2)labirinto[y-1][x]=' ';
	}
	labirinto[21][2]=' ';
	labirinto[2][27]=' ';
    for(y=0;y<=22;y++){
		for(x=0;x<=29;x++){
			if(labirinto[y][x]=='X'){
				printf("%c",219);	
			}else{
				printf(" ");
			}
		}
	}
	getch();
}
