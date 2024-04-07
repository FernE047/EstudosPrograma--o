#include<stdio.h>
#include<stdlib.h>
int main(){
	int maior[6][4],pos1,pos2,quant=0,menu;
	while(menu!=3){
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX  XXXXXXX  XXX     XXX   XXX     XXX     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX    XXX    XX  XXX  XXXXXXX  XXX  XX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX  X  X  X  XX  XXX  XX   XX  XXX  XX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX  XX   XX  XX       XX   XX  XXX  XX     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX  XXXXXXX  XX  XXX  XX   XX  XXX  XX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XX  XXXXXXX  XX  XXX  XX   XXX     XXX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXX     XXXX  XXX  XX      XXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXX  XXX  XXX  XXX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXX  XXX  XXX  XXX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXX  XXX  XXX  XXX  XX      XXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXX  XX   XXX  XXX  XX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXX       XXX     XXX      XXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     XXXX     XXXX    XXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XX  XXX  XX  XX  XXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XX  XXX  XXXXX  XXXXXXXXXXX");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     XXX  XXX  XXXX  XXXXXXXXXXXX");	
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XX  XXX  XXXXXXXXXXXXXXXXXX");
		printf("digite 1 para iniciar    XXXXXXXXXXXXXXXXXXXXXXXXXX  XX  XXX  XXXX  XXXXXXXXXXXX");
		printf("digite 2 para intrucoes  XXXXXXXXXXXXXXXXXXXXXX     XXXX     XXXXX  XXXXXXXXXXXX");
		printf("digite 3 para sair       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		scanf("%d",&menu);
		system("cls");
		switch(menu){
			case 1:
				for(pos1=0;pos1<=5;pos1++){
					for(pos2=0;pos2<=3;pos2++){
						printf("digite um numero\n");
						scanf("%d",&maior[pos1][pos2]);
						if(maior[pos1][pos2]>30)quant++;
					}
				}
				system("cls");
				printf("voce digitou %d numeros maiores que 30\n\n\n\n\n\n\n\n\n\n\n\n\n\n",quant);
				printf("digite 1 para voltar ao menu\ndigite 3 para sair do programa");
				scanf("%d",&menu);				
			break;
			case 2:
				printf("bem vindo ao programa \"maior que 30?\" nele voce digita 24 numeros e\n");
				printf("o programa ira calcular quantos numero digitados eram maior que 30\n");
				printf("lembrando que essa e uma versao BETA do programa, estamos angariando \n");
				printf("fundos para fazer uma interface melhor, caso queira fazer uma doacao,\n entre em contato\n");
				printf("digite 1 para voltar ao menu\ndigite 3 para sair do programa");
				scanf("%d",&menu);
			break;
			case 3:
				printf("obrigado pela preferencia e volte sempre");
			break;
		}
	}
	system("pause");
}
