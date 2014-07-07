/* **********************************************
*						*
*	EP4 - ESTRUTURA DE DADOS 		*
*						*
*	Prof. Andre Fujita 			*
*						*
*	Danilo Aleixo Gomes de Souza		*
*	n USP 7972370				*
*						*
*	Julio Cesar Seki			*
*	n USP 7991145 				*
*						*
*********************************************** */

#include "StringOps.h"


#define TRUE 1
#define FALSE 0

/* Estrutura da arvore */
typedef struct node 
{
	int numChaves;
	int *chaves;
	struct node **filhos;
} Node;


/* prototipo das funcoes */
int *inserirVetor(int *vetor, int chave);
Node *criaNode();
Node *inserir(Node *raiz, int chave);
void imprime(Node *raiz);


/* variaveis globais */
int ordemArvore;



int main(int argc, char **argv)
{
	Node *raiz = NULL;
	int opcao = 0;
	int chaveAInserir;

	if(argc == 1)
	{
		/* Condicao para conseguirmos um valor valido para a ordem */
		while(TRUE)
		{
			printf("Digite a ordem da arvore B\n");
			scanf("%d", &ordemArvore);
			if(ordemArvore > 0) 
				break;
			else 
				printf("Valor invalido, por favor digite um valor valido!\n");
		}

		/* loop principal */
		while(TRUE)
		{
			printf("Digite o que gostaria de fazer: \n");
			printf("(1) Buscar\n");
			printf("(2) Inserir\n");
			printf("(3) Remover uma chave\n");
			printf("(4) Finalizar processo\n");
			printf("--------------------------------\n");
			scanf("%d", &opcao);

			/* caso 4 */
			if(opcao == 4) break;

			/* caso 2 >>>>BUSCAR */
			else if(opcao == 2)
			{
				printf("Digite a chave do no que deseja inserir\n");
				scanf("%d", &chaveAInserir);
				raiz = inserir(raiz, chaveAInserir);
			}
			imprime(raiz);
		}
		

	} else {
		printf("\nModo de utilização:\n\n");
		printf("	ep4 \n\n");
	}


	return 0;
}

Node *criaNode ()
{
	Node *novo = malloc(sizeof(Node));
	novo->numChaves = 0;
	novo->chaves = malloc(ordemArvore * sizeof(int));
	novo->filhos = malloc(ordemArvore * sizeof(Node*));
	return novo;
}

Node *recursao(Node *aux, int chave)
{
	if(aux->numChaves <= 0)
		return aux;
	else {
		int menor = aux->chaves[0];
		int maior = aux->chaves[aux->numChaves - 1];
		if(chave > menor && chave < maior)	
			return aux;
		else if(chave < menor){
			if(aux->numChaves < ordemArvore) return aux;
			else if(aux->filhos[0] != NULL) recursao(aux->filhos[0], chave);
			else return aux;
		} 
		else if(chave > maior)
		{
			if(aux->numChaves < ordemArvore) return aux;
			else if(aux->filhos[aux->numChaves - 1] != NULL) recursao(aux->filhos[ordemArvore - 1], chave);
			else return aux;
		}
	}
	return NULL;
}

Node *inserir(Node *raiz, int chave)
{
	Node *praInserir;
	Node *novoElemento = criaNode();

	if(raiz == NULL)
	{
		novoElemento->numChaves = 1;
		novoElemento->chaves[0] = chave;
		return novoElemento;
	} else {
		praInserir = recursao(raiz, chave);
		if(praInserir->numChaves == ordemArvore)
		{
			/* precisa fazer */
		} else {
			praInserir->chaves = inserirVetor(praInserir->chaves, chave);
		}
	}
	return raiz;
}

int *inserirVetor(int *vetor, int chave)
{
	int *novoVetor = malloc(ordemArvore * sizeof(int));
	int cont =  0, i;
	for(i = 0; vetor[i] < chave && i < ordemArvore; i++)
		novoVetor[cont++] = vetor[i];
	novoVetor[cont++] = chave;
	for(i = 0; i < ordemArvore; i++)
		novoVetor[cont++] = vetor[i + 1];

	return novoVetor;
}

void imprime(Node *raiz)
{
	int i;
	if(raiz != NULL)
	{
		printf("\n\n");
		printf("Valor da raiz: ");
		for(i = 0; i < raiz->numChaves; i++)
			printf("%d ", raiz->chaves[i]);
		printf("\n" );
	}
	for(i = 0; i < raiz->numChaves; i++)
	{
		if(raiz->filhos[i] != NULL) imprime(raiz->filhos[i]);
	}
	printf("\n\n");
}