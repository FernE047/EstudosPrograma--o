// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um 
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo 
// disponível no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.

#include <windows.h>
#include <gl/glut.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

FILE *mus_a;
FILE *mus_n;
FILE *mus;
FILE *imagem;
char maior_tamanho=0,ident[1000][20],palavras,tester[20];
int quantidade_palavras=0,j,extra;
float vermelho[1000],verde[1000],azul[1000];

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	int colunas,linhas,ponto;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                  
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
	imagem=fopen("imagem_musica","r");
	for(colunas=0;colunas<quantidade_palavras;colunas++){
		for(linhas=quantidade_palavras;linhas>0;linhas--){
			fscanf(imagem,"%d ",&ponto);
			if(ponto<1000){
				glBegin(GL_POINTS);
					glColor3f(vermelho[ponto],verde[ponto],azul[ponto]);
					glVertex2i(colunas,linhas);
				glEnd(); 
			}
		}
	}	
	fclose(imagem);

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int acentuado(char pop){
	if((pop>=-64)and(pop<=-61)){
		return(1);
	}else if(pop==-57){
		return(1);		
	}else if((pop>=-55)and(pop<=-54)){
		return(1);
	}else if((pop>=-51)and(pop<=-50)){
		return(1);
	}else if((pop>=-45)and(pop<=-44)){
		return(1);
	}else if((pop>=-38)and(pop<=-37)){
		return(1);
	}else if((pop>=-32)and(pop<=-29)){
		return(1);
	}else if(pop==-25){
		return(1);
	}else if((pop>=-23)and(pop<=-22)){
		return(1);
	}else if((pop>=-19)and(pop<=-18)){
		return(1);
	}else if(pop==-12){
		return(1);
	}else if((pop>=-6)and(pop<=-5)){
		return(1);
	}else{
		return(0);
	}
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, quantidade_palavras, 0.0f, quantidade_palavras*h/w);
                   else 
                           gluOrtho2D (0.0f, quantidade_palavras*w/h, 0.0f, quantidade_palavras);
}

int preparacao(){
	char a,b=1,tamanho=0,palavra[20];
	mus_a=fopen("musica","r");
	mus_n=fopen("musica_nova","w");
	for(j=0;j<=999;j++){
		ident[j][0]=' ';
	}
	while( (fscanf(mus_a,"%c", &a))!=EOF ){
		if(((a>=65)and(a<=90))or((a>=97)and(a<=122))or(acentuado(a)))tamanho++;
		if((a>=65)and(a<=90)){
			a=a+32;
		}else if(((a<97)or(a>122))and((a<-96)or(a>-93))and(!(acentuado(a)))){
			a=32;
			if(tamanho>=maior_tamanho)maior_tamanho=tamanho;
			tamanho=0;
		}
		if((b==2)and(a==32)){
			a=65;
		}else if(b==2){
			b=1;
			fprintf(mus_n,"%c",a);
		}else{
			fprintf(mus_n,"%c",a);
		}
		if((a==32)and(b==1))b=2;
	}
	fclose(mus_a);
	fclose(mus_n);
	mus=fopen("musica_nova","r");
	while((fscanf(mus,"%s",&palavra))!=EOF)quantidade_palavras++;
	printf("maior palavra contem: %d\nquantidade de palavras:%d\n",maior_tamanho,quantidade_palavras);
	fclose(mus);
}


// Programa Principal 
int main(void)
{
	int linhas,colunas;
	int controle=0;
	preparacao();
	const int QUANTIA=quantidade_palavras+1;
	const int MAIOR=maior_tamanho+1;
	quantidade_palavras++;
	int cont=0;
	char palavras[QUANTIA][MAIOR];
	srand(time(NULL));
	mus=fopen("musica_nova","r");
	while((fscanf(mus,"%s",&palavras[cont]))!=EOF)cont++;
	fclose(mus);
	imagem=fopen("imagem_musica","w");
	for(colunas=0;colunas<QUANTIA;colunas++){
		for(linhas=0;linhas<QUANTIA;linhas++){
			if(!(strcmp(palavras[colunas],palavras[linhas]))){
				cont=-1;
				for(extra=0;extra<=18;extra++){
					tester[extra]=palavras[colunas][extra];
				}
				for(j=0;j<=999;j++){
					if(!(strcmp(tester,ident[j])))cont=j;
				}
				if(cont>=0){
					fprintf(imagem,"%d ",cont);
				}else{
					for(extra=0;extra<=18;extra++){
						ident[controle][extra]=palavras[colunas][extra];
					}
					verde[controle]=(rand()%1000);
					vermelho[controle]=(rand()%1000);
					azul[controle]=(rand()%1000);
					verde[controle]=verde[controle]/1000;
					vermelho[controle]=vermelho[controle]/1000;
					azul[controle]=azul[controle]/1000;
					printf("%f %f %f\n",verde[controle],vermelho[controle],azul[controle]);
					fprintf(imagem,"%d ",controle);
					controle++;
				}
			}else{
				fprintf(imagem,"%d ",1000);
			}
		}
	}
	fclose(imagem);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(QUANTIA+1,QUANTIA+1);
    glutInitWindowPosition(10,10);
    glutCreateWindow("musica imagem");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
}
