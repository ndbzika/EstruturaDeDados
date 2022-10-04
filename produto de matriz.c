#include <stdio.h>
#include <locale.h>

int dimensionaMatriz(int linha, int coluna){
	return linha*coluna;
}

void zeraMatriz(int vet[],int tamanho){
	int k;
	for(k=0;k<tamanho;k++){
		vet[k]=0;
	}
}


void imprimeMatriz(int vet[], int linha, int coluna){
	int i,j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			printf("%d\t",vet[i * coluna + j]);
		}
		printf("\n");
	}
}


void adicionaElemento(int vet[], int valor, int linha, int coluna,int totalColunas){
	vet[((linha - 1) * totalColunas) + (coluna - 1)] = valor;
}

int buscaElemento(int vet[], int linha, int coluna,int totalColunas){
	return vet[((linha - 1) * totalColunas) + (coluna - 1)];
}

void produto_Matriz( int *vet_1, int *vet_2,int linha,int coluna){
	int produto,i,j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			int a=i,b=j;
			produto = vet_1[a++]*vet_2[b++]+vet_1[b++]*vet_2[a++];
			printf("%d\t",produto);
		}
		printf("\n");
	}
}

void main(){
	
	int x=3,y=2;
	
	int vet1[dimensionaMatriz(x, y)];
	int vet2[dimensionaMatriz(y, x)];

	// zerando
	zeraMatriz(vet1,dimensionaMatriz(x, y));
	zeraMatriz(vet2,dimensionaMatriz(y, x));
//	zeraMatriz(vet3);
	
	imprimeMatriz(vet1, x, y);
	printf("\n");
	imprimeMatriz(vet2, y, x);
	printf("\n");
	
	getch();
	// montando
	adicionaElemento(vet1, 2, 1, 1, y);
	adicionaElemento(vet1, 1, 1,2, y);
	adicionaElemento(vet1, 0, 2, 1, y);
	adicionaElemento(vet1, 3, 2, 2, y);
	adicionaElemento(vet1, 1, 3, 1, y);
	adicionaElemento(vet1, 1, 3, 2, y);
	printf("Matriz 1: \n");
	imprimeMatriz(vet1, x, y);
	getch();
	
	adicionaElemento(vet2, 0, 1, 1, x);
	adicionaElemento(vet2, 2, 2, 1, x);
	adicionaElemento(vet2, 3, 1, 2, x);
	adicionaElemento(vet1, 1, 2, 2, x);
	adicionaElemento(vet1, 3, 1, 3, x);
	adicionaElemento(vet1, 1, 2, 3, x);
	printf("Matriz 2: \n");
	imprimeMatriz(vet2, y, x);
	printf("\n");
	getch();
	
	produto_Matriz(vet1,vet2,x,x);
	getch();
	}
