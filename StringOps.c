#include "StringOps.h"

FILE *leEntrada (char *nomeArquivo)
{
    FILE *entrada;
    entrada = fopen(nomeArquivo, "r");
    if(entrada == NULL)
    {
        fprintf(stderr, "Nao consegui ler o arquivo!");
        exit(-1);
    }
    return entrada;
}

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n\n");
    exit(-1);
  }
  return pt;
}


char *concatenaStrings(char *original, char *add)
{

  char *novaString;
  int i = 0, j = 0;

  int tamanho = strlen(original) + strlen(add) + 1;
  novaString = malloc(tamanho*sizeof(char));

  while(original[i] != '\0')
  {
    novaString[i] = original[i];
    i++;
  }      


  while(add[j] != '\0')
  {
    novaString[i] = add[j];
    i++; j++;
  }

  novaString[tamanho - 1] = '\0';

  return novaString;
}
