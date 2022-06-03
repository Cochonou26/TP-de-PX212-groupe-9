#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "tailleNiveau.h"
#include "trouverNiveau.h"
#include "util.h"

int *tailleNiveau(char *fichierNiveaux, int niveau){
	FILE *rfp = NULL;
	char *s;
	int nLignes = 0, nColonnes = 0;
	int *tableauTaille;

	trouverNiveau(fichierNiveaux, niveau, &rfp);
	if ((s = malloc(sizeof(char)*MAXSIZE)) == NULL)
		perror("malloc");
	//comptage du nombre de lignes et de colonnes
	while ((fgets(s, MAXSIZE, rfp) != NULL) && (s[0] != ';')){
		nColonnes = MAX(nColonnes, strlen(s) - 1);
		nLignes++;
	}
	if (fclose(rfp) == EOF)
		perror("fclose");

	if ((tableauTaille = malloc(2*sizeof(int))) == NULL)
		perror("malloc");
	tableauTaille[0] = nLignes;
	tableauTaille[1] = nColonnes;
	return tableauTaille;
}

