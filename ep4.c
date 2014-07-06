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
typedef struct no
{
    int chave;
    int numChaves; /*sempre que houver a fusao ou divisao de um no, esse valor devera ser alterado*/
    struct no *esq,*dir;
}No;

/*Prototipos das funcoes*/
No *inserir(No *raiz, int chave);
void imprime(No *raiz);


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
			if(ordemArvore > 0) 
			{
				system("clear");
				break;
			}
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

			/* caso 2 >>>>Inserir */
			if(opcao == 2)
			{
				printf("Digite a chave do no que deseja inserir\n");
				scanf("%d", &chaveAInserir);
				raiz = inserir(raiz, chaveAInserir);
				imprime(raiz);
			}

			/* caso 4 */
			else if(opcao == 4) break;
		}
		

	} else {
		printf("\nModo de utilização:\n\n");
		printf("	ep4 \n\n");
	}


	return 0;
}

No *inserir(No *raiz, int chave)
{
	No *aux;
	No *novoElemento = malloc(sizeof(No));
	novoElemento->chave = chave;
	novoElemento->esq = NULL;
	novoElemento->dir = NULL;

	if(raiz == NULL) /*caso a raiz esteja vazia, basta tornar o novo elemento como raiz*/
	{
		raiz = novoElemento;
	} 
	else {
		aux = raiz;
		if(chave < aux->chave)
		{
			if(aux->esq == NULL)
				aux->esq = novoElemento;
		}
		if(chave > aux->chave)
		{
			if(aux->dir == NULL)
				aux->dir = novoElemento;
		}
	}
}

void imprime(No *raiz)
{
	if(raiz != NULL)
	{
		printf("Valor da raiz: %d\n", raiz->chave);
	}
	if(raiz->esq != NULL)
	{
		imprime(raiz->esq);
	}
	if(raiz->dir != NULL)
	{
		imprime(raiz->dir);
	}
}

