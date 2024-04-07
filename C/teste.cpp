#include <stdio.h>
#include <math.h>
#define ARESTAS 1
#define PRECISAO 2

int definicao[ARESTAS][3],somalt,somaresp,count,loop;
float alt[10],resp[10],vert[10],maxvert[10],recebivert[10][10];

int main(){
	for(count=0;count<=9;count++){
		maxvert[count]=0;
		for(loop=0;loop<=9;loop++){
			recebivert[count][loop]=0;
		}
	}
	for(count=0;count<=(ARESTAS-1);count++){
		for(loop=0;loop<=2;loop++){
			definicao[count][loop]=-1;
			if(loop!=0){
				while((definicao[count][loop]>9)or(definicao[count][loop]<0)){
					printf("escreva de qual vertice ele vem e para onde vai\n");
					scanf("%d",&definicao[count][loop]);
				}
			}else{
				while(definicao[count][loop]<0){
					printf("\n\nescreva a quantidade de arestas que vao na direcao da aresta %d\n",count);
					scanf("%d",&definicao[count][loop]);
				}				
			}
			if(loop==2){
				maxvert[definicao[count][1]]+=definicao[count][0];
				recebivert[definicao[count][2]][definicao[count][1]]+=definicao[count][0];
			}
		}
	}
	somaresp=PRECISAO*10;
	for(vert[0]=0;vert[0]<=PRECISAO;vert[0]++){
		for(vert[1]=0;vert[1]<=PRECISAO;vert[1]++){
			for(vert[2]=0;vert[2]<=PRECISAO;vert[2]++){
				for(vert[3]=0;vert[3]<=PRECISAO;vert[3]++){
					for(vert[4]=0;vert[4]<=PRECISAO;vert[4]++){
						for(vert[5]=0;vert[5]<=PRECISAO;vert[5]++){
							for(vert[6]=0;vert[6]<=PRECISAO;vert[6]++){
								for(vert[7]=0;vert[7]<=PRECISAO;vert[7]++){
									for(vert[8]=0;vert[8]<=PRECISAO;vert[8]++){
										for(vert[9]=0;vert[9]<=PRECISAO;vert[9]++){
											somalt=0;
											for(count=0;count<=9;count++){
												alt[count]=0;
												if(maxvert[count]==0)alt[count]+=vert[count];
												for(loop=0;loop<=9;loop++){
													alt[count]+=recebivert[count][loop]*vert[loop]/(maxvert[loop]==0?1:maxvert[loop]);
												}
												somalt+=vert[count];
											}
											if(somalt<somaresp){
												if((vert[0]==alt[0])and(vert[1]==alt[1])and(vert[2]==alt[2])and(vert[3]==alt[3])and(vert[4]==alt[4])and(vert[5]==alt[5])and(vert[6]==alt[6])and(vert[7]==alt[7])and(vert[8]==alt[8])and(vert[9]==alt[9])){
													if((vert[0]!=0)and(vert[1]!=0)and(vert[2]!=0)and(vert[3]!=0)and(vert[4]!=0)and(vert[5]!=0)and(vert[6]!=0)and(vert[7]!=0)and(vert[8]!=0)and(vert[9]!=0)){
														for(count=0;count<=9;count++){
															resp[count]=alt[count];
															somaresp=somalt;
														}
													}
												}
											}
											printf("\n%d\n%d\n\n",somalt,somaresp);
										}	
									}	
								}	
							}	
						}	
					}	
				}	
			}	
		}	
	}
	if(somaresp==PRECISAO*10){
		printf("\n\n não foi encontrada resposta dentro dessa precisao:%d",PRECISAO);
	}else{
		printf("\n\n");
		for(count=0;count<=9;count++){
			printf("%c:%d\n",count+65,resp[count]);
		}
	}
}
