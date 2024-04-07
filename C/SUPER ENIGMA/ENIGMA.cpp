#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

char start;
char identidade[68]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef! ghijklmnop,q.r0123456789stuvw?xyz"};
char rotor[10][68]={"cSzDGhE5iw !?Y0PelBV9Tb1N,8WApQrKLvFIsxR64tdZ27fOXq3nHm.aUjoygJMkuC","jv RZr0!37upl9WPmD?t8nOhzEiw1og2CHeXaA5MQVdLy.qFGcfI6k4JUNsTKBbSx,Y","lh1ce6!to3xW7RnfsNa.g4LXqjSbD?EPkGUBmZ!AiOIz2YT8yC,JV5FMr9QHuwvdK0p","v3TauX59eZmS,N7kciLCqn?FlJDjQpIzt280RbPYKVodMU4yh6 B.G1OgHx!EAwWsrf","kR2x! U4QV.qs9XoIBznGJ6Owibapm?rFEhgZvA,dTPclLKf10C8H7W53NMutjYeDyS","H?xVjaMAJI1tGpsm.y3k0D9dncFlZX4v2ri8gETbPYqN,oQ UK!Se56whWOLuf7BCRz","91qbRcLvYTiGwo!6hE.Jzrx4IeuDFpZ50OsQKlmjk2Nd8CSV BntXfPy,Ag3aHM?W7U","s,jDR9Wybc8SU1r?dELZMXGV2TaIJQtvzuwihCmlk3.0B4oOpNYnq576KFAe fgPxH!","a4xIX!ToDKJ dU2rRQiGNh1Et,AbjMukLF9VScf?vyHsZ8wP7WOzB650qgpYem.lCn3","buDCKVn3rxEt7PdN2w6cqFkivy8ATO. fpo9X?W,0Gg!lUeIm1QHs5SMah4LBYRjJZz"};
char refletor[6][68]={"zoYlPWKe2pGch nEbUZiR?F8CSdQLaHsN6uMT3rDvOBJ.x,kw1Ij47!5Xyftgm0Vq9A","wfF1,Cpn6ecd2VZ?TWyQrNRbgOvXKLJB8oYlk5ihqH GEm0U.DMsujIx!t394aAP7Sz","q7W0GuEz2,p9vbhX? t5!oCPZYjN.ym8RUlOsa6ge3VKJAc1DrIn4TkBfLiSFMwQxdH","kH5zd9RB7es?.TPO,GYNm n8S1bagEJjV3cpyfAoUWlhQtMw2Z0!vCxIXFKqu4rL6iD","gb2Q1F3P?vn, twHDrjf.z405mdBhayTMkAcxS!sZK pLuURXECGWY9876lNqJOIieV","!smwWIqYFTLKX34oh2yJ1ZEMHVantlep8A6Q0r5dCbPf?GxjiURNOkg7 9BcvuD,.Sz"};
char plugboard[2][68]={"zsMWUaPqudlNCLgG 4m.EhD5v6F?rJn0Q,OV987KSetp!HTcfw32RXZkjiBoIY1bxyA","!T.Wtfpyj,UXvrQkO?uBK DL1zoi638FVA9wbIP245aGJsCN7Yldmnc0egqESMhRxHZ"};
int rotor_direita=0,rotor_central=1,rotor_esquerda=2,giro_direita=0,giro_esquerda=0,giro_central=0,plugboard_principal=0,refletor_principal=0;
int numero,cont;
char tecla, mensagem[1000];
FILE *arq;

int converte_tecla(char letra){														//converte teclas para numeros
	int numero;
	if((letra>=65)and(letra<=90)){
		numero=letra-65;
	}else if((letra>=97)and(letra<=102)){
		numero=letra-71;
	}else if((letra>=103)and(letra<=112)){
		numero=letra-69;
	}else if(letra==113){
		numero=letra-68;
	}else if(letra==114){
		numero=letra-67;
	}else if((letra>=115)and(letra<=119)){
		numero=letra-57;
	}else if((letra>=120)and(letra<=122)){
		numero=letra-56;
	}else{
		numero=letra;
	}
	return(numero);
}

int dentro_do_intervalo(char a){													//testa se a letra é valida
	if((a>=65)and(a<=90)){
		return(1);
	}else if((a>=97)and(a<=122)){
		return(1);
	}else if((a>=48)and(a<=57)){
		return(1);
	}else if((a>=32)and(a<=33)){
		return(1);
	}else if(a==44){
		return(1);
	}else if(a==46){
		return(1);
	}else if(a==63){
		return(1);
	}else{
		return(0);
	}
}

int escreve_pecas(int peca){														//apenas escreve as peças disponiveis, sendo 0 para rotores, 2 para refletores, 1 ou outros para plugboards
	int cont1;
	printf("\n");
	switch(peca){
		case 0:
			for(cont1=0;cont1<=9;cont1++){
				printf("%d : %s\n",cont1,rotor[cont1]);
			}
		break;
		case 2:
			for(cont1=0;cont1<=5;cont1++){
				printf("%d : %s\n",cont1,refletor[cont1]);
			}
		break;
		default:
			for(cont1=0;cont1<=1;cont1++){
				printf("%d : %s\n",cont1,plugboard[cont1]);
			}
		break;
	}
}

int alterar_manual(int ident,int peca){												//alterar manualmente as peças, sendo 0 para rotores, 2 para refletores, 1 ou outros para plugboards
	int control,tecla,a,b,teste,tester[67];
	b=0;
	for(teste=0;teste<=66;teste++){
		tester[teste]=219;
		if(peca==0){
			rotor[ident][teste]=219;
		}else if(peca==2){
			refletor[ident][teste]=219;
		}else{
			plugboard[ident][teste]=219;
		}
	}
	for(control=66;control>=0;control--){
		a=1;
		system("cls");
		if(peca==0){
			printf("Digite cada um dos 67 caracteres sem repeticao para criar um rotor\n");
			printf("\n%s\n",rotor[ident]);
		}else if(peca==2){
			printf("Digite cada um dos 67 caracteres sem repeticao para criar um refletor\n");
			printf("\n%s\n",refletor[ident]);
		}else{
			printf("Digite cada um dos 67 caracteres sem repeticao para criar um plugboard\n");
			printf("\n%s\n",plugboard[ident]);
		}
		while(a){
			a=0;
			tecla=getch();
			if(dentro_do_intervalo(tecla)){
				for(teste=0;teste<=66;teste++){
					if(tester[teste]==tecla)a=1;
				}
				if(a==1)printf("\n caracter repetido, digite outro\n");
			}else{
				printf("\ncaracter nao permitido\n");
				a=1;
			}
		}
		if(peca==0){
			rotor[ident][b]=tecla;
		}else if(peca==2){
			refletor[ident][b]=tecla;
		}else{
			plugboard[ident][b]=tecla;
		}
		tester[b]=tecla;
		b++;
	}
	system("cls");
	if(peca==0){
		printf("\nbem sucedido\n\nnovo rotor:%s\n\nAPERTE ENTER PARA VOLTAR",rotor[ident]);
	}else if(peca==2){
		printf("\nbem sucedido\n\nnovo refletor:%s\n\nAPERTE ENTER PARA VOLTAR",refletor[ident]);
	}else{
		printf("\nbem sucedido\n\nnovo plugboard:%s\n\nAPERTE ENTER PARA VOLTAR",plugboard[ident]);
	}
	getch();
}

int alterar_random(int ident,int peca){												//cria uma nova peça aleatoria, sendo 0 para rotores, 1 para refletores, 2 ou outros para plugboards
	int control,random,a,teste,tester[68],b;
	for(teste=0;teste<=66;teste++){
		tester[teste]=219;
	}
	for(control=0;control<=66;control++){
		a=1;
		if(tester[control]==219){
			while(a){
				a=0;
				random=(rand()%67);
				b=random;
				switch(random){
					case 0:
						random=65;
					break;
					case 1:
						random=66;
					break;
					case 2:
						random=67;
					break;
					case 3:
						random=68;
					break;
					case 4:
						random=69;
					break;
					case 5:
						random=70;
					break;
					case 6:
						random=71;
					break;
					case 7:
						random=72;
					break;
					case 8:
						random=73;
					break;
					case 9:
						random=74;
					break;
					case 10:
						random=75;
					break;
					case 11:
						random=76;
					break;
					case 12:
						random=77;
					break;
					case 13:
						random=78;
					break;
					case 14:
						random=79;
					break;
					case 15:
						random=80;
					break;
					case 16:
						random=81;
					break;
					case 17:
						random=82;
					break;
					case 18:
						random=83;
					break;
					case 19:
						random=84;
					break;
					case 20:
						random=85;
					break;
					case 21:
						random=86;
					break;
					case 22:
						random=87;
					break;
					case 23:
						random=88;
					break;
					case 24:
						random=89;
					break;
					case 25:
						random=90;
					break;
					case 26:
						random=97;
					break;
					case 27:
						random=98;
					break;
					case 28:
						random=99;
					break;
					case 29:
						random=100;
					break;
					case 30:
						random=101;
					break;
					case 31:
						random=102;
					break;
					case 32:
					break;
					case 33:
					break;
					case 34:
						random=103;
					break;
					case 35:
						random=104;
					break;
					case 36:
						random=105;
					break;
					case 37:
						random=106;
					break;
					case 38:
						random=107;
					break;
					case 39:
						random=108;
					break;
					case 40:
						random=109;
					break;
					case 41:
						random=110;
					break;
					case 42:
						random=111;
					break;
					case 43:
						random=112;
					break;
					case 44:
					break;
					case 45:
						random=113;
					break;
					case 46:
					break;
					case 47:
						random=114;
					break;
					case 48:
					break;
					case 49:
					break;
					case 50:
					break;
					case 51:
					break;
					case 52:
					break;
					case 53:
					break;
					case 54:
					break;
					case 55:
					break;
					case 56:
					break;
					case 57:
					break;
					case 58:
						random=115;
					break;
					case 59:
						random=116;
					break;
					case 60:
						random=117;
					break;
					case 61:
						random=118;
					break;
					case 62:
						random=119;
					break;
					case 63:
					break;
					case 64:
						random=120;
					break;
					case 65:
						random=121;
					break;
					case 66:
						random=122;
					break;
				}
				for(teste=0;teste<=66;teste++){
					if(tester[teste]==random)a=1;
				}
			}
			if(peca==0){
				rotor[ident][control]=random;
				rotor[ident][b]=identidade[control];
			}else if(peca==2){
				refletor[ident][control]=random;
				refletor[ident][b]=identidade[control];
			}else{
				plugboard[ident][control]=random;
				plugboard[ident][b]=identidade[control];
			}
			tester[control]=random;
			tester[b]=identidade[control];
		}
	}
	if(peca==0){
		printf("\nbem sucedido\n\nnovo rotor:%s\n\nAPERTE ENTER PARA VOLTAR",rotor[ident]);
	}else if(peca==2){
		printf("\nbem sucedido\n\nnovo refletor:%s\n\nAPERTE ENTER PARA VOLTAR",refletor[ident]);
	}else{
		printf("\nbem sucedido\n\nnovo plugboard:%s\n\nAPERTE ENTER PARA VOLTAR",plugboard[ident]);
	}
	getch();
}

int rotores_menu(){																	//menu principal para rotores
	char menu=1,opcao,numero[45];
	int novo;
	system("cls");
	srand(time(NULL));
	while(menu){
		printf("1-configurar posicoes de rotores\n");
		printf("2-configurar rotores extras\n");
		printf("3-ver rotores\n");
		printf("\n0-VOLTAR\n");
		opcao=1;
		menu=getch();
		system("cls");
		switch(menu){
			case '0':
				return(6);
			break;
			case '1':
				while(opcao){
					system("cls");
					printf("opcoes-definicao\n");
					printf("1-rotor direito : %d\n",rotor_direita);
					printf("2-giro direito  : %d\n",giro_direita);
					printf("3-rotor central : %d\n",rotor_central);
					printf("4-giro central  : %d\n",giro_central);
					printf("5-rotor esquerdo: %d\n",rotor_esquerda);
					printf("6-giro esquerdo : %d\n\n",giro_esquerda);
					printf("7-ver rotores\n");
					printf("\n0-VOLTAR\n\n");
					printf("qual opcao?\n");
					opcao=getch();
					switch(opcao){
						case'1':
							escreve_pecas(0);
							printf("\nQual opcao escolhe para substituir o rotor direito?\n");
							opcao=getch();
							novo=opcao-48;
							if((novo>=0)and(novo<=9)){
								rotor_direita=novo;
							}else{
								printf("\nopcao inexistente, tecle enter e tente novamente\n");
								getch();
							}
						break;
						case'2':
							printf("\nQual o novo valor do giro direito?\n");
							scanf("%s",&numero);
							giro_direita=atoi(numero);
							if(giro_direita<0)giro_direita=-giro_direita;
							if(giro_direita/67>=1)giro_direita=giro_direita%67;
						break;
						case'3':
							escreve_pecas(0);
							printf("\nQual opcao escolhe para substituir o rotor central?\n");
							opcao=getch();
							novo=opcao-48;
							if((novo>=0)and(novo<=9)){
								rotor_central=novo;
							}else{
								printf("\nopcao inexistente, tecle enter e tente novamente\n");
								getch();
							}
						break;
						case'4':
							printf("\nQual o novo valor do giro central?\n");
							scanf("%s",&numero);
							giro_central=atoi(numero);
							if(giro_central<0)giro_central=-giro_central;
							if(giro_central/67>=1)giro_central=giro_central%67;
						break;
						case'5':
							escreve_pecas(0);
							printf("\nQual opcao escolhe para substituir o rotor esquerdo?\n");
							opcao=getch();
							novo=opcao-48;
							if((novo>=0)and(novo<=9)){
								rotor_esquerda=novo;
							}else{
								printf("\nopcao inexistente, tecle enter e tente novamente\n");
								getch();
							}
						break;
						case'6':
							printf("\nQual o novo valor do giro esquerdo?\n");
							scanf("%s",&numero);
							giro_esquerda=atoi(numero);
							if(giro_esquerda<0)giro_esquerda=-giro_esquerda;
							if(giro_esquerda/67>=1)giro_esquerda=giro_esquerda%67;
						break;
						case'7':
							escreve_pecas(0);
							getch();
						break;
						default:
							opcao=0;
						break;
					}
				}
			break;
			case '2':
				system("cls");
				escreve_pecas(0);
				printf("\nAPERTE OUTRA TECLA PARA VOLTAR");
				printf("\n\nqual rotor deseja alterar?\n");
				menu=getch();
				opcao=(((menu>=48)and(menu<=57))?0:1);
				novo=menu-48;
				system("cls");
				printf("1-entrada manual\n");
				printf("2-entrada aleatoria (ALTAMENTE RECOMENDAVEL)\n");
				printf("\n0-VOLTAR\n");
				while(!opcao){
					opcao=getch();
					if(opcao=='1'){
						alterar_manual(novo,0);
					}else if(opcao=='2'){
						alterar_random(novo,0);						
					}else if(opcao!='0'){
						printf("\nentrada invalida\n\n");
						opcao=0;
					}			
				}
			break;
			case '3':
				escreve_pecas(0);
				printf("\n0-VOLTAR\n\n");
				getch();
			break;
			default:
				return(6);
			break;
		}
		if(opcao!='3')menu=1;
		system("cls");
	}
}

int pecas_menu(int qual){															//menu principal para refletores
	char menu=1,opcao,numero[45];
	int novo;
	system("cls");
	srand(time(NULL));
	while(menu){
		escreve_pecas(qual+1);
		if(qual)printf("\nrefletor principal:%d",refletor_principal);
		if(!qual)printf("\nplugboard principal:%d",plugboard_principal);
		printf("\n\nESCOLHA UMA OPCAO ABAIXO");
		if(qual)printf("\n\n1-alterar refletor principal\n");
		if(!qual)printf("\n\n1-alterar plugboard principal\n");
		if(qual)printf("2-configurar refletor extras\n");
		if(!qual)printf("2-configurar plugboard extras\n");
		printf("\n0-VOLTAR\n");
		opcao=1;
		menu=getch();
		system("cls");
		switch(menu){
			case '0':
				return(6);
			break;
			case '1':
				while(opcao){
					escreve_pecas(qual+1);
					if(qual)printf("\nQual opcao escolhe para substituir o refletor principal?\n");
					if(!qual)printf("\nQual opcao escolhe para substituir o plugboard principal?\n");
					opcao=getch();
					novo=opcao-48;
					if(((novo>=0)and(novo<=5)and(qual==1))or((novo>=0)and(novo<=1)and(qual==0))){
						if(qual)refletor_principal=novo;
						if(!qual)plugboard_principal=novo;
						opcao=0;
					}else{
						printf("\nopcao inexistente, tecle enter e tente novamente\n");
						getch();
					}
				}
			break;
			case '2':
				system("cls");
				escreve_pecas(qual+1);
				printf("\nAPERTE OUTRA TECLA PARA VOLTAR");
				if(qual)printf("\n\nqual refletor deseja alterar?\n");
				if(!qual)printf("\n\nqual plugboard deseja alterar?\n");
				menu=getch();
				if(qual)opcao=(((menu>=48)and(menu<=53))?0:1);
				if(!qual)opcao=(((menu>=48)and(menu<=49))?0:1);
				novo=menu-48;
				system("cls");
				printf("1-entrada manual\n");
				printf("2-entrada aleatoria (ALTAMENTE RECOMENDAVEL)\n");
				printf("\n0-VOLTAR\n");
				while(!opcao){
					opcao=getch();
					if(opcao=='1'){
						alterar_manual(novo,(qual+1));
					}else if(opcao=='2'){
						alterar_random(novo,(qual+1));						
					}else if(opcao!='0'){
						printf("\nentrada invalida\n\n");
						opcao=0;
					}			
				}
			break;
			default:
				return(6);
			break;
		}
		if(opcao!='3')menu=1;
		system("cls");
	}
}

int load(){																			//carrega os estados salvos
	int a,b,passer;
	arq=fopen("save/save","r");
	for(b=0;b<=9;b++){
		for(a=0;a<=66;a++){
			fscanf(arq,"%d",&rotor[b][a]);
		}
	}
	for(b=0;b<=5;b++){
		for(a=0;a<=66;a++){
			fscanf(arq,"%d",&refletor[b][a]);
		}
	}
	for(b=0;b<=1;b++){
		for(a=0;a<=66;a++){
			fscanf(arq,"%d",&plugboard[b][a]);
		}
	}
	fscanf(arq,"%d",&rotor_direita);
	fscanf(arq,"%d",&rotor_central);
	fscanf(arq,"%d",&rotor_esquerda);
	fscanf(arq,"%d",&giro_direita);
	fscanf(arq,"%d",&giro_esquerda);
	fscanf(arq,"%d",&giro_central);
	fscanf(arq,"%d",&plugboard_principal);
	fscanf(arq,"%d",&refletor_principal);
	fclose(arq);
}

int save(){																			//salva os estados atuais
	int a,b;
	arq=fopen("save/save","w");
	for(b=0;b<=9;b++){
		for(a=0;a<=66;a++){
			fprintf(arq,"%d ",rotor[b][a]);
		}
	}
	for(b=0;b<=5;b++){
		for(a=0;a<=66;a++){
			fprintf(arq,"%d ",refletor[b][a]);
		}
	}
	for(b=0;b<=1;b++){
		for(a=0;a<=66;a++){
			fprintf(arq,"%d ",plugboard[b][a]);
		}
	}
	fprintf(arq," %d %d %d %d %d %d %d %d",rotor_direita,rotor_central,rotor_esquerda,giro_direita,giro_esquerda,giro_central,plugboard_principal,refletor_principal);
	fclose(arq);
}

int total(){																		//cria uma configuração nova completa
	int a,b,c;
	for(b=0;b<=2;b++){
		if(b==0){
			c=9;
		}else if(b==1){
			c=1;
		}else{
			c=5;
		}
		for(a=0;a<=c;a++){
			alterar_random(a,b);
		}
	}
}

int main(){
	start='?';
	for(cont=0;cont<=998;cont++){
		mensagem[cont]=219;
	}
	while(start){																	//menu
		printf("1-rotores\n");
		printf("2-refletores\n");
		printf("3-plugboard\n");
		printf("4-carregar/salvar configuracoes\n");
		printf("5-criar nova configuracao total\n");
		printf("0-SAIR\n");
		printf("\nAPERTE ENTER PARA INICIAR O PROGRAMA\n");
		start=getch();
		switch(start){
			case '0':
				exit(0);
			break;
			case '1':
				start=rotores_menu();
			break;
			case '2':
				start=pecas_menu(1);
			break;
			case '3':
				start=pecas_menu(0);
			break;
			case '4':
				system("cls");
				printf("1-salvar configuracoes\n");
				printf("2-carregar configuracoes\n");
				printf("\n0-VOLTAR\n");
				start=getch();
				if(start=='1'){
					save();
				}else if(start=='2'){
					load();
				}
				printf("\n\nbem sucedido\n\nAPERTE ENTER PARA VOLTAR");
				start=getch();
				system("cls");
			break;
			case'5':
				system("cls");
				printf("Voce tem certeza?\n\n");
				printf("1-SIM\n");
				printf("0-NAO\n\n");
				start=getch();
				if(start=='1'){
					total();
				}
				system("cls");
			break;
			default:
				start=0;
			break;
		}
	}
	cont=0;
	while(1){
		system("cls");
		tecla=0;
		printf("mensagem:\n\n%s \n\n",mensagem);
		if(cont==999){
			printf("mensagem completa\n\n");
		}
		while(!(dentro_do_intervalo(tecla))){
			tecla=getch();
			if(tecla==';')break;
		}
		if(tecla==';')break;
		if(cont==999)break;
		numero=converte_tecla(tecla);
		tecla=plugboard[plugboard_principal][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		if((giro_direita+numero)<=66){
			numero=numero+giro_direita;
		}else{
			numero=numero+giro_direita-67;			
		}
		tecla=rotor[rotor_direita][numero];
		giro_direita++;
		if(giro_direita%67==0)giro_direita=0;
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=rotor[rotor_central][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=rotor[rotor_esquerda][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=refletor[refletor_principal][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=rotor[rotor_esquerda][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=rotor[rotor_central][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=rotor[rotor_direita][numero];
		printf("%c\n",tecla);
		numero=converte_tecla(tecla);
		tecla=plugboard[plugboard_principal][numero];
		printf("%c\n",tecla);
		mensagem[cont]=tecla;
		cont++;
	}
}
