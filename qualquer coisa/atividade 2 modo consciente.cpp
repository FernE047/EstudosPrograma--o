#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	int numeros[5][3],pos,pos2;
	char a;
	printf("ola!!! meu nome e XARVIS e eu exibo a ordem inversa\nde qualquer lista de numeros que voce digitar\n ");
	a=getch();
	for(pos=0;pos<=4;pos++){
		for(pos2=0;pos2<=2;pos2++){
			if(pos2==0){
				printf("digite um numero qualquer\n");
			}else if(pos2==1){
				printf("por favor, digite mais um numero\n");
			}else{
				printf("sr. digite apenas mais numero para acabar essa serie\n");
			}
			scanf("%d",&numeros[pos][pos2]);
		}
		printf("serie %d memorizada com sucesso, digite a proxima serie\n\n\n\n",pos);
	}
	printf("desculpe-me, meu vocabulario nao e muito extenso por isso as frases repetidas\n");
	a=getch();
	system("cls");
	printf("estou tentando me esforcar para lembrar da sequencia.\n,mas sao muitos numeros, preciso de uma mao, por favor digite uma tecla\n");
	a=getch();
	system("cls");
	printf("hmmm, gracas a sua ajuda me lembrei, sera que e essa a ordem inversa da sua\n sequencia:\n");
	for(pos=4;pos>=0;pos--){
		for(pos2=2;pos2>=0;pos2--){
			printf("%d\n",numeros[pos][pos2]);
		}
	}
	printf("acertei!!! agora que cumpri o objetivo da minha vida te dou um tchau e digo:\nate a proxima\nagradecemos a sua preferencia\n");
	system("pause");
}
