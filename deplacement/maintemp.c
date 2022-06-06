#include <stdio.h>
#include "fonctions.h"

int main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	niveau *pNiveau;

	numNiveau = 88;

	if ((pNiveau = creerNiveau(fichierNiveaux, numNiveau)) == NULL) // Creation niveau
		printf("Erreur création niveau %d\n", numNiveau);

	if (configureTerminal())
		printf("Erreur configuration terminal\n");
	printf("\033[H\033[2J");
	afficherNiveau(pNiveau->tabNiveau, pNiveau->nLignes, pNiveau->nColonnes);

	while (1) {  //1 tant que la condition de reussite est pas codée
		printf("\033[H\033[2J"); //equivalent au system clear (le prof prefere)
		if (deplacement(pNiveau, litClavier()))
			printf("Erreur déplacement\n");
		afficherNiveau(pNiveau->tabNiveau, pNiveau->nLignes, pNiveau->nColonnes);
	}
	freeNiveau(pNiveau);
	return 0;
}
