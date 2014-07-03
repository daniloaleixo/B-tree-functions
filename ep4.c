#include <stdlib.h>
#include <stdio.h>


#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
	int ordemArvore, opcao = 0;

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
			else if(opcao == 1)
			{
				printf("ok\n");
			}
		}
		

	} else {
		printf("\nModo de utilização:\n\n");
		printf("	ep4 \n\n");
	}


	return 0;
}