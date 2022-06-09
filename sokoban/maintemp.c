#include <stdio.h>
#include "global.h"
#include "lectureTableau.h"
#include "affichageTableau.h"
#include "deplacement.h"
#include "io.h"
#include "util.h"

int main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	Niveau *pNiveau;
	Dep *pile;
	pile = emalloc(sizeof(Dep));
	pile->prev = NULL;

	numNiveau = 88;

	if ((pNiveau = creerNiveau(fichierNiveaux, numNiveau)) == NULL) // Creation niveau
		printf("Erreur création niveau %d\n", numNiveau);

	if (configureTerminal())
		printf("Erreur configuration terminal\n");
	printf("\033[H\033[2J");
	afficherNiveau(pNiveau);

	while (1) {  //1 tant que la condition de reussite est pas codée
		printf("\033[H\033[2J"); //equivalent au system clear
		if (deplacement(pNiveau, litClavier(), &pile))
			printf("Erreur déplacement\n");
		afficherNiveau(pNiveau);
	}
	freeNiveau(pNiveau);
	return 0;
}
