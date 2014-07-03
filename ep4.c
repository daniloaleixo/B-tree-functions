#include "StringOps.h"


#define TRUE 1
#define FALSE 0

/* Estrutura da arvore */
typedef struct no
{
    int chave;
    struct no *esq,*dir;
}No;



int main(int argc, char **argv)
{
	No *raiz;
	int ordemArvore, opcao = 0;
	int chaveAInserir;

	if(argc == 1)
	{
		/* Condicao para conseguirmos um valor valido para a ordem */
		while(TRUE)
		{
			printf("Digite a ordem da arvore B\n");
			scanf("%d", &ordemArvore);
			if(ordemArvore > 0) break;
			else printf("Valor invalido, por favor digite um valor valido!\n");
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
				inserir(raiz, chaveAInserir);
			}
		}
		

	} else {
		printf("\nModo de utilização:\n\n");
		printf("	ep4 \n\n");
	}


	return 0;
}


void inserir(No *raiz, int chave)
{
	No *aux;
	No *novoElemento = malloc(sizeof(No));
	novoElemento->esq = NULL;
	novoElemento->dir = NULL;

	if(raiz == NULL)
	{
		raiz = novoElemento;
	} 
	else {
		aux = raiz;
		while(novoElemento->chave < aux->chave)
		{
			if(aux->esq == NULL) aux->esq = novoElemento;
			else aux = aux->esq;
		}
		aux = raiz;
		while(novoElemento->chave > aux->chave)
		{
			if(aux->dir == NULL) aux->dir = novoElemento;
			else aux = aux->dir;
		}
	}
}