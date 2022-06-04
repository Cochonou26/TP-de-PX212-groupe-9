#include <stdio.h>

// Macro permettant de trouver le max de deux nombres
#define MAX(a,b) (a>b?a:b)

void *emalloc(unsigned int n);
FILE *efopen(const char *fichier, const char *mode);
void efclose(FILE *stream);

