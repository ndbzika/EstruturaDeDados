#include <stdio.h>
#include <locale.h>

int l,c,tam;

void dimensionaMatriz(int linha, int coluna){
	l=linha;
	c=coluna;
	tam=linha*coluna;
}

void zeraMatriz(int vet[]){
	int k;
	for(k=0;k<tam;k++){
		vet[k]=0;
	}
}


void imprimeMatriz(int vet[], int m, int n){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%d\t",vet[i * c + j]);
		}
		printf("\n");
	}
}


void adicionaElemento(int vet[], int valor, int linha, int coluna){
	vet[((linha - 1) * c) + (coluna - 1)] = valor;
}

int buscaElemento(int vet[], int linha, int coluna){
	return vet[((linha - 1) * c) + (coluna - 1)];
}

void produto_Matriz( int *vet_1, int *vet_2){
	int produto,i,j;
	++l;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			int a=i,b=j;
			produto = vet_1[a++]*vet_2[b++]+vet_1[b++]*vet_2[a++];
			printf("%d\t",produto);
		}
		printf("\n");
	}
}

void main(){
	dimensionaMatriz(3, 2);
	int vet1[tam];
	dimensionaMatriz(2, 3);
	int vet2[tam];
//	int vet3[tam];
	// zerando
	zeraMatriz(vet1);
	zeraMatriz(vet2);
//	zeraMatriz(vet3);
	
	imprimeMatriz(vet1, ++l, --c);
	printf("\n");
	imprimeMatriz(vet2, --l, ++c);
	printf("\n");
//	imprimeMatriz(vet3, l, c);
//	printf("\n");
	
	getch();
	// montando
	adicionaElemento(vet1, 2, 1, 1);
	adicionaElemento(vet1, 1, 1,2);
	adicionaElemento(vet1, 0, 2, 1);
	adicionaElemento(vet1, 3, 2, 2);
	adicionaElemento(vet1, 1, 3, 1);
	adicionaElemento(vet1, 1, 3, 2);
	printf("Matriz 1: \n");
	imprimeMatriz(vet1, ++l, --c);
	getch();
	
	adicionaElemento(vet2, 0, 1, 1);
	adicionaElemento(vet2, 2, 2, 1);
	adicionaElemento(vet2, 3, 1, 2);
	adicionaElemento(vet1, 1, 2, 2);
	adicionaElemento(vet1, 3, 1, 3);
	adicionaElemento(vet1, 1, 2, 3);
	printf("Matriz 2: \n");
	imprimeMatriz(vet2, --l, ++c);
	printf("\n");
	getch();
	
	produto_Matriz(vet1,vet2);
	getch();
	}
