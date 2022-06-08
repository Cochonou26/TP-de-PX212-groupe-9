#include <stdio.h>
#include "global.h"
#include "lectureTableau.h"
#include "affichageTableau.h"
#include "deplacement.h"
#include "io.h"
#include "positionObjectifs.h"
#include "util.h"
#include "retourArriere.h"

int main(int argc, char *argv[]){
	int numNiveau;
	char *fichierNiveaux = "levels.lvl";
	Niveau *pNiveau;
	Dep *pile;
	pile = emalloc(sizeof(Dep));
	pile->prev = NULL;

	for (numNiveau = 1; numNiveau<=88; numNiveau++) {
		if ((pNiveau = creerNiveau(fichierNiveaux, numNiveau)) == NULL) // Creation niveau
			printf("Erreur création niveau %d\n", numNiveau);

		if (configureTerminal())
			printf("Erreur configuration terminal\n");
		printf("\033[H\033[2J");
		printf("NIVEAU %d\n", numNiveau);
		afficherNiveau(pNiveau);

		while (verifierVictoire(pNiveau)) {  //1 tant que la condition de reussite est pas codée
			printf("\033[H\033[2J"); //equivalent au system clear
			if (deplacement(pNiveau, litClavier(), &pile))
				printf("déplacement non permit\n");	
			printf("NIVEAU %d\n", numNiveau);
			remplacerObjectifs(pNiveau);
			afficherNiveau(pNiveau);
		}
		while ((pile->prev) != NULL){
			retourArriere(pNiveau, &pile);
		}
		freeNiveau(pNiveau);
	}
	return 0;
}
