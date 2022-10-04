#include<stdio.h>
#include<locale.h>

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
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
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


void somaMatriz(int vet1,int vet2, int vet3){
	// adicionando matriz e armazenando valor no vetor
	int i,j;
	for ( i = 1; i <= l; i++)
	{
		for ( j = 1; j <= c; j++)
		{
			int valor = buscaElemento(vet1, i, j) + buscaElemento(vet2, i, j);
			adicionaElemento(vet3, valor, i, j);
		}
	}
	
}

void main(){
	dimensionaMatriz(3, 3);
	int vet1[tam];
	int vet2[tam];
	int vet3[tam];
	// zerando
	zeraMatriz(vet1);
	zeraMatriz(vet2);
	zeraMatriz(vet3);
	
	imprimeMatriz(vet1, l, c);
	imprimeMatriz(vet2, l, c);
	imprimeMatriz(vet3, l, c);
	
	getch();
	// montando
	adicionaElemento(vet1, 15, 1, 1);
	adicionaElemento(vet1, 25, 2, 2);
	adicionaElemento(vet1, 35, 3, 3);
	printf("Matriz 1: \n");
	imprimeMatriz(vet1, l, c);
	getch();
	
	adicionaElemento(vet2, 5, 1, 1);
	adicionaElemento(vet2, 5, 2, 2);
	adicionaElemento(vet2, 5, 3, 3);
	printf("Matriz 2: \n");
	imprimeMatriz(vet2, l, c);
	getch();
	
	somaMatriz(vet1,vet2,vet3);
	printf("Matriz soma:\n");
	imprimeMatriz(vet3, l, c);
	
	getch();
}
