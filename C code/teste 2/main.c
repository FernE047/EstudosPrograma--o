#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
int main()
{
    int by,bx,bum=0,x,d=2,cx[300]={1,2},cy[300]={7,7},t=1,pont=0,mx,my,cond=1;
    char tecla='a';
    system("MODE con cols=27 lines=20");
    for(x=0;x<18;x++)
    {
		mgotoxy(0,x);
        printf("%c",219);
    }
    for(x=0;x<26;x++)
    {
		mgotoxy(x,0);
        printf("%c",219);
    }
    for(x=0;x<18;x++)
    {
		mgotoxy(26,x);
        printf("%c",219);
    }
    for(x=0;x<27;x++)
    {
		mgotoxy(x,18);
        printf("%c",219);
    }
    srand(time(NULL));
    mx=(rand()%25)+1;
    my=(rand()%17)+1;
    bx=(rand()%23)+2;
    by=(rand()%15)+2;
    while(tecla!='s')
    {   while(tecla!='s'&&!(tecla=kbhit()))
        {   for(x=t;x>0;x--)
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }
            if(d==0)cx[0]--;
            if(d==1)cy[0]--;
            if(d==2)cx[0]++;
            if(d==3)cy[0]++;
            mgotoxy(cx[t],cy[t]);
            printf(" ");
            if(mx==cx[0]&&my==cy[0])
            {
				t++;
				pont+=10;
                mx=(rand()%25)+1;
                my=(rand()%17)+1;
                mgotoxy(0,19);
                printf("pontuacao:%d",pont);
			}
            mgotoxy(cx[0],cy[0]);
            printf("%c",219);
            mgotoxy(mx,my);
            printf("%c",254);
            if(bum>=15){
            	mgotoxy(bx,by);
				printf("B");
				mgotoxy(bx-1,by);
				printf("B");
				mgotoxy(bx+1,by);
				printf("B");
            	mgotoxy(bx,by+1);
				printf("B");
            	mgotoxy(bx,by-1);
				printf("B");
            	mgotoxy(bx-1,by-1);
				printf("B");
            	mgotoxy(bx+1,by+1);
				printf("B");
            	mgotoxy(bx+1,by-1);
				printf("B");
            	mgotoxy(bx-1,by+1);
				printf("B");
				if(bum<=18){
					bum++;
				}else{
					bum=0;
				}
			}else if(bum==0){
            	mgotoxy(bx,by);
				printf(" ");
				mgotoxy(bx-1,by);
				printf(" ");
				mgotoxy(bx+1,by);
				printf(" ");
            	mgotoxy(bx,by+1);
				printf(" ");
            	mgotoxy(bx,by-1);
				printf(" ");
            	mgotoxy(bx-1,by-1);
				printf(" ");
            	mgotoxy(bx+1,by+1);
				printf(" ");
            	mgotoxy(bx+1,by-1);
				printf(" ");
            	mgotoxy(bx-1,by+1);
				printf(" ");
  				cond=0;
				while(cond==0){
				    bx=(rand()%23)+2;
  					by=(rand()%15)+2;
  					cond=1;
  					for(x=1;x<t;x++){
  						if(bx!=cx[x]&&bx!=cx[x]-1&&bx!=cx[x]+1&&by!=cy[x]&&by!=cy[x]-1&&by!=cy[x]+1){
  							if(cond!=0){
								cond=1;
							}
						}else{
							cond=0;
						}
					}
  				}
				bum++;
			}else{
				bum++;
			}
            mgotoxy(bx,by);
            printf("%c",208);
            Sleep(100);
            for(x=1;x<t;x++)
            {
				if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='s';
            }
            if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
			for(x=1;x<t;x++){
				if((((bx-1==cx[x]&&by-1==cy[x])||(bx+1==cx[x]&&by+1==cy[x])||(bx-1==cx[x]&&by+1==cy[x])||(bx+1==cx[x]&&by-1==cy[x])||(bx+1==cx[x]&&by==cy[x])||(bx==cx[x]&&by+1==cy[x])||(bx-1==cx[x]&&by==cy[x])||(bx==cx[x]&&by-1==cy[x]))&&bum>=16)||(bx==cx[x]&&by==cy[x])){
					tecla='s';
				}
			}
        }
        if(tecla!='s')tecla=getch();
        if(tecla=='K')d=0;
        if(tecla=='H')d=1;
        if(tecla=='M')d=2;
        if(tecla=='P')d=3;
        if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
    }
    getch();
}
