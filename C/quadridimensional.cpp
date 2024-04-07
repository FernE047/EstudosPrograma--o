#include<windows.h>
#include<stdio.h>
#include<conio.h>
#define TAMANHO 5

char matriz[TAMANHO][TAMANHO][TAMANHO][TAMANHO],visao[TAMANHO][TAMANHO][TAMANHO],dir;
int xu,yu,zu,wu,z,graf;

void mgotoxy(int xm,int ym)
{	COORD p={xm,ym};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int menu (int xa,int ya,int za,int wa,int g){				//coloca valores na matriz, caso uma posição seja igual a tamanho então todas as posições daquela variavel será mudada de valor, por exemplo se xa==tamanho então todos os xa de 0 a n(tamanho) que corresponde a seus respectivos za,ya,wa serão trocados de valor
	if(xa==TAMANHO){
		if(ya==TAMANHO){
			if(za==TAMANHO){
				if(wa==TAMANHO){							//xa,ya,wa,za
					for(xa=0;xa<=(TAMANHO-1);xa++){
						for(ya=0;ya<=(TAMANHO-1);ya++){
							for(wa=0;wa<=(TAMANHO-1);wa++){
								for(za=0;za<=(TAMANHO-1);za++){
									matriz[xa][ya][za][wa]=g;
								}
							}
						}
					}
				}else{								//xa,ya,za
					for(ya=0;ya<=(TAMANHO-1);ya++){
						for(za=0;za<=(TAMANHO-1);za++){
							for(xa=0;xa<=(TAMANHO-1);xa++){
								matriz[xa][ya][za][wa]=g;
							}
						}
					}
				}
			}else if(wa==TAMANHO){						//xa,ya,wa
				for(ya=0;ya<=(TAMANHO-1);ya++){
					for(wa=0;wa<=(TAMANHO-1);wa++){
						for(xa=0;xa<=(TAMANHO-1);xa++){
							matriz[xa][ya][za][wa]=g;
						}
					}
				}
			}else{									//xa,ya
				for(xa=0;xa<=(TAMANHO-1);xa++){
					for(ya=0;ya<=(TAMANHO-1);ya++){
						matriz[xa][ya][za][wa]=g;
					}
				}
			}
		}else if(za==TAMANHO){
			if(wa==TAMANHO){								//xa,wa,za
				for(xa=0;xa<=(TAMANHO-1);xa++){
					for(wa=0;wa<=(TAMANHO-1);wa++){
						for(za=0;za<=(TAMANHO-1);za++){
							matriz[xa][ya][za][wa]=g;
						}
					}
				}
			}else{									//xa,za
				for(xa=0;xa<=(TAMANHO-1);xa++){
					for(za=0;za<=(TAMANHO-1);za++){
						matriz[xa][ya][za][wa]=g;
					}
				}
			}
		}else if(wa==TAMANHO){							//xa,wa
			for(xa=0;xa<=(TAMANHO-1);xa++){
				for(wa=0;wa<=(TAMANHO-1);wa++){
					matriz[xa][ya][za][wa]=g;
				}
			}
		}else{										//xa
			for(xa=0;xa<=(TAMANHO-1);xa++){
				matriz[xa][ya][za][wa]=g;
			}
		}
	}else if(ya==TAMANHO){
		if(za==TAMANHO){
			if(wa==TAMANHO){								//ya,wa,za
				for(ya=0;ya<=(TAMANHO-1);ya++){
					for(wa=0;wa<=(TAMANHO-1);wa++){
						for(za=0;za<=(TAMANHO-1);za++){
							matriz[xa][ya][za][wa]=g;
						}
					}
				}
			}else{									//ya,za
				for(ya=0;ya<=(TAMANHO-1);ya++){
					for(za=0;za<=(TAMANHO-1);za++){
						matriz[xa][ya][za][wa]=g;
					}
				}
			}
		}else if(wa==TAMANHO){							//ya,wa
			for(wa=0;wa<=(TAMANHO-1);wa++){
				for(ya=0;ya<=(TAMANHO-1);ya++){
					matriz[xa][ya][za][wa]=g;
				}
			}
		}else{										//ya
			for(ya=0;ya<=(TAMANHO-1);ya++){
				matriz[xa][ya][za][wa]=g;
			}
		}
	}else if(za==TAMANHO){
		if(wa==TAMANHO){									//wa,za
			for(wa=0;wa<=(TAMANHO-1);wa++){
				for(za=0;za<=(TAMANHO-1);za++){
					matriz[xa][ya][za][wa]=g;
				}
			}
		}else{										//za
			for(za=0;za<=(TAMANHO-1);za++){
				matriz[xa][ya][za][wa]=g;
			}
		}
	}else if(wa==TAMANHO){								//wa
		matriz[xa][ya][za][wa]=g;
	}else{											//NOTHING
		matriz[xa][ya][za][wa]=g;
	}
}

int zescreve(){
    for(yu=0;yu<TAMANHO;yu++){
    	for(xu=0;xu<TAMANHO;xu++){
			mgotoxy(xu,yu);
        	printf("%c",visao[xu][yu][z]);
    	}
    }
}

int main(){
	for(xu=0;xu<=(TAMANHO-1);xu++){			//limpa o mundo
		for(yu=0;yu<=(TAMANHO-1);yu++){
			for(wu=0;wu<=(TAMANHO-1);wu++){
				for(zu=0;zu<=(TAMANHO-1);zu++){
					matriz[xu][yu][zu][wu]=32;
				}
			}
		}
	}
	while(1){								//criação do mundo
		printf("X:");
		scanf("%d",&xu);
		if((xu>TAMANHO)or(xu<0)){
			break;
		}else{
			printf("Z:");
			scanf("%d",&zu);
			if((zu>TAMANHO)or(zu<0)){
				break;
			}else{
				printf("W:");
				scanf("%d",&wu);
				if((wu>TAMANHO)or(wu<0)){
					break;
				}else{
					printf("Y:");
					scanf("%d",&yu);
					if((yu>TAMANHO)or(yu<0)){
						break;
					}else{
						printf("GRAFICO ASCII:");
						scanf("%d",&graf);
						if(graf==0)graf=219;			
						menu(xu,yu,zu,wu,graf);
					}
				}	
			}
		}		
	}
	system("cls");
	while(1){
		dir=getch();
		if(dir=='H'){			//cima 
		}else if(dir=='P'){		//baixo
		}else if(dir=='s'){		//vis_DOWN
		}else if(dir=='w'){		//vis_UP
		}else if(dir=='a'){		//vis_LEFT
		}else if(dir=='d'){		//vis_RIGHT
		}else{
			break;
		}
	}
}
