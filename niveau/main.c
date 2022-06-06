#include <stdio.h>
#include <stdlib.h>
#include "lectureTableau.h"
#include "affichageTableau.h"

int
main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	niveau *pNiveau;

	numNiveau = 88;
	pNiveau = creerNiveau(fichierNiveaux, numNiveau);
	afficherNiveau(pNiveau->tabNiveau, pNiveau->nLignes, pNiveau->nColonnes);
	freeNiveau(pNiveau);
	return 0;
}
