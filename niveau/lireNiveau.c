#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "lireNiveau.h"
#include "trouverNiveau.h"

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
		for (iColonne = 0; iColonne < nColonnes; iColonne++){
			if ((c = fgetc(rfp)) != EOF){
				if ((tabNiveau[iLigne][iColonne] = malloc(sizeof(char))) == NULL)
					perror("malloc");
				*tabNiveau[iLigne][iColonne] = c;
				if (c == '\n')
					break;
			}
		}
	}

	if (fclose(rfp) == EOF)
		perror("fclose");
	printf("lignes : %d\ncolonnes : %d\n",nLignes, nColonnes);
	return tabNiveau;
}
