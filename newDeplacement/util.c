#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void
error(const char *msg)
{
	perror(msg);
	exit(1);
}

void *
emalloc(unsigned int nbits){
	void *p;
	
	if ((p = malloc(nbits)) == NULL)
		error("malloc");
	return p;
}

FILE *
efopen(const char *fichier, const char *mode){
	FILE *fp;

	if ((fp = fopen(fichier, mode)) == NULL)
		error("fopen");
	return fp;
}

void
efclose(FILE *stream){
	if (fclose(stream) == EOF)
		error("fclose");
}

void
freeNiveau(Niveau *pNiveau)
{
	int iLigne, iCible;

	for (iLigne = 0; iLigne < pNiveau->nLignes; iLigne++)
		free(pNiveau->tabNiveau[iLigne]);
	free(pNiveau->tabNiveau);
	for (iCible = 0; iCible < pNiveau->nCibles; iCible++)
		free(pNiveau->tabCibles[iCible]);
	free (pNiveau->tabCibles);
	free(pNiveau);
}

