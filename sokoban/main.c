#include <stdio.h>
#include "global.h"
#include "lectureTableau.h"
#include "affichageTableau.h"
#include "deplacement.h"
#include "io.h"
#include "positionObjectifs.h"
#include "util.h"
#include "retourArriere.h"
#include "sauvegarde.h"

int main(int argc, char *argv[]){
	int numNiveau, *compteurCoups;
	char *fichierNiveaux = "levels.lvl";
	Niveau *pNiveau;
	Dep *pile;
	int sortie=0;

	pile = emalloc(sizeof(Dep));
	pile->prev = NULL;
	compteurCoups = emalloc(sizeof(int));
	*compteurCoups = 0;
	numNiveau = 1;
	if (!verifierSauvegarde()) numNiveau=chercherNiveau();

	for (; numNiveau <= 88; numNiveau++) {
		pNiveau = creerNiveau(fichierNiveaux, numNiveau);
		if (pNiveau == NULL) // Creation niveau
			printf("Erreur création niveau %d\n", numNiveau);

		if (configureTerminal())
			printf("Erreur configuration terminal\n");
		printf("\033[H\033[2J");
		printf("Niveau %d\nCoups : %d\n", numNiveau, *compteurCoups);
		afficherNiveau(pNiveau);

		if (!verifierSauvegarde()){
			repriseSauvegarde(&pile, pNiveau, compteurCoups);
			printf("\033[H\033[2J");
			printf("Niveau %d\nCoups : %d\n", numNiveau, *compteurCoups);
			afficherNiveau(pNiveau);
		}

		while (verifierVictoire(pNiveau) && sortie!=2) {
			if ((sortie=deplacement(pNiveau, litClavier(), &pile, compteurCoups, &numNiveau)))
				printf("déplacement non permit\n");
			printf("\033[H\033[2J"); //equivalent au system clear
			printf("NIVEAU %d\nCoups : %d\n", numNiveau, *compteurCoups);
			remplacerObjectifs(pNiveau);
			afficherNiveau(pNiveau);
		}
		if (!verifierVictoire(pNiveau)) enregistrement(pile, numNiveau);
		while ((pile->prev) != NULL){
			retourArriere(pNiveau, &pile);
		}
		freeNiveau(pNiveau);
		*compteurCoups = 0;
	}
	free(compteurCoups);
	return 0;
}
