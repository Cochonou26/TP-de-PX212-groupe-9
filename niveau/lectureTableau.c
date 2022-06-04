#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "lectureTableau.h"
#include "util.h"

void trouverNiveau(char *fichierNiveaux, int niveau, FILE **rfpp){
	char *strNiveau, *s;

	if ((strNiveau = malloc(sizeof(char)*(MAXSTRNIVEAU+ strlen(";LEVEL ")))) == NULL)
		perror("malloc");
	snprintf(strNiveau, MAXSTRNIVEAU + strlen(";LEVEL "), ";LEVEL %d\n",niveau);
	if ((*rfpp = fopen(fichierNiveaux, "r")) == NULL)
		perror("fopen");
	if ((s = malloc(sizeof(char)*MAXSIZE)) == NULL)
		perror("malloc");
	while (fgets(s, MAXSIZE, *rfpp) != NULL){
		if (!strcmp(s, strNiveau))
			break;
	}
}

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

char *** lireNiveau(char *fichierNiveaux, int niveau, int nLignes, int nColonnes){
	FILE *rfp = NULL;
	char ***tabNiveau = NULL;
	int iLigne, iColonne;
	int c;
	
	trouverNiveau(fichierNiveaux, niveau, &rfp);
	//allocation memoire du tableau
	if ((tabNiveau = malloc(sizeof(char **)*nLignes)) == NULL)
		perror("malloc");
	for (iLigne = 0; iLigne < nLignes; iLigne++){
		if ((tabNiveau[iLigne] = malloc(sizeof(char *)*nColonnes)) == NULL)
			perror("malloc");
	}
	
	//remplissage du tableau
	for (iLigne = 0; iLigne < nLignes; iLigne++){
		for (iColonne = 0; iColonne < (nColonnes + 1); iColonne++){ // + 1 pour '\n'
			c = fgetc(rfp);
			if ((tabNiveau[iLigne][iColonne] = malloc(sizeof(char))) == NULL)
				perror("malloc");
			*tabNiveau[iLigne][iColonne] = c;
			if (c == '\n')
				break;
		}
	}

	if (fclose(rfp) == EOF)
		perror("fclose");
	return tabNiveau;
}

