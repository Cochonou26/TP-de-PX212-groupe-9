#include <stdio.h>
#include <stdlib.h>
#include "lectureTableau.h"
#include "affichageTableau.h"

int
main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	niveau *pNiveau;
	/*
	if (argc != 1){
		if (*argv[1] - 48 > 0)
			numNiveau = *argv[1] - 48;
		else{
			printf("erreur, format: main <numNiveau>\n");
			return 1;
		}
	}else{
		printf("erreur, format: main <numNiveau>\n");
		return 1;
	}
	*/
	numNiveau = 1;
	pNiveau = creerNiveau(fichierNiveaux, numNiveau);
	afficherNiveau(pNiveau->tabNiveau, pNiveau->nLignes, pNiveau->nColonnes);
	freeNiveau(pNiveau);
	return 0;
}
