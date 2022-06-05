#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


void *emalloc(unsigned int nbits){
	void *p;
	
	if ((p = malloc(nbits)) == NULL)
		perror("malloc");
	return p;
}

FILE *efopen(const char *fichier, const char *mode){
	FILE *fp;

	if ((fp = fopen(fichier, mode)) == NULL)
		perror("fopen");
	return fp;
}

void efclose(FILE *stream){
	if (fclose(stream) == EOF)
		perror("fclose");
}

