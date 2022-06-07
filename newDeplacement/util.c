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
freeNiveau(niveau *pNiveau)
{
	int iLigne, iColonne;

	for (iLigne = 0; iLigne < pNiveau->nLignes; iLigne++){
		for (iColonne = 0; iColonne < pNiveau->nColonnes + 1; iColonne++){
			free(pNiveau->tabNiveau[iLigne][iColonne]);
		}
		free(pNiveau->tabNiveau[iLigne]);
	}
	free(pNiveau->tabNiveau);
	free(pNiveau->lJoueur);
	free(pNiveau->cJoueur);
	free(pNiveau);
}

