#include <stdio.h>
#include <stdlib.h>


////matriz começa em [1][1] e não [0][0]


////////////////////
//dimensior Matriz//
////////////////////
int dimensionarMatriz(int n, int m){
	return n*m;
}
///////////////////////
//zerando a matriz////
//////////////////////
void zerarMat(int vet[],int TAM){
	int k;
	for(k=0;k<TAM;k++)
	{
		vet[k]=0;
	}
}
//////////////////////////
//imprimir matriz zerada//
//////////////////////////
//atualização: adicionei tabulação
void imprimirMatrizZerada(int vet[],int linha,int coluna){
	int i, cont=0;
	for(i=0;i<linha*coluna;i++){
		if(cont==coluna){
			printf("\n");
			cont=0;
		}
		printf("%d\t",vet[i]);
		cont++;
	}
}

//adicionar elemento

void adicionarNaMatriz(int vet[], int valor,int linha, int coluna,int quantidadeDeColuna){
	int num;
	num=linha*quantidadeDeColuna+coluna;
	vet[num]=valor;
}

//imprimir matriz preenchida
//modificação: alterei a condição do for, adicionei tabulação e coloquei um else no cont++ (ta dando um erro onde fica algumas posições do vetor na inserção)
void imprimirMatPreenchida(int vet[],int linha,int coluna,int totalColunas){
	int i, cont=0;
	for(i=0;i<coluna;i++){
		printf("%d\t",vet[linha*totalColunas+coluna]);
		if(cont==coluna){
			printf("\n");
			cont=0;
		}else{
			cont++;
		}
	}

}

void main(){
	int linha,coluna,n,x,y,j,i;
	printf("Digite a quantidade de linhas e colunas: ");
	scanf("%d%d",&linha,&coluna);
	int TAM =  dimensionarMatriz(linha,coluna);
	int vet[TAM];
	zerarMat(vet,TAM);
	imprimirMatrizZerada(vet,linha,coluna);
	printf("\nInforme o numero que deseja adicionar e qual sua posicao: ");
	scanf("%d%d%d",&n,&x,&y);
	while(n!=0){
		adicionarNaMatriz(vet,n,x,y,coluna);
		printf("Informe o numero que deseja adicionar e qual sua posicao: ");
		scanf("%d%d%d",&n,&x,&y);
	}
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			imprimirMatPreenchida(vet,i,j,coluna);
		}
		printf("\n");
	}
	getch();
}
