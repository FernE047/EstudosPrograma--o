#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
void mgotoxy(int x,int y)
{
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
int main(){
    system("MODE con cols=19 lines=21");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
}
