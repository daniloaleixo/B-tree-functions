#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *leEntrada(char *nomeArquivo);
char *readLine(FILE *entrada);
void *mallocSafe (size_t n);
char *concatenaStrings(char *original, char *add);
