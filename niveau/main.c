#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int
main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	niveau *pNiveau;

	numNiveau = 88;
	if ((pNiveau = creerNiveau(fichierNiveaux, numNiveau)) == NULL)
		printf("Erreur création niveau %d\n", numNiveau);
	afficherNiveau(pNiveau->tabNiveau, pNiveau->nLignes, pNiveau->nColonnes);
	freeNiveau(pNiveau);
	return 0;
}
