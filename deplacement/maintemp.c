#include <stdio.h>
#include "deplacement.h"
#include "lectureTableau.h"
#include "affichageTableau.h"
#include "io.c"

int main(int argc, char *argv[]){
	int dep;
	int niveau;
	char *fichierNiveaux = "levels.lvl";
	char ***tableauNiveau;
	int *tableauTaille;
	int nLignes, nColonnes;
	int lJoueur = 8, cJoueur = 11, *plJoueur, *pcJoueur;

	plJoueur = &lJoueur;
	pcJoueur = &cJoueur;

	/*if (argc != 1){
		if (*argv[1] - 48 > 0)
			niveau = *argv[1] - 48;
		else{
			printf("erreur, format: main <niveau>\n");
			return 1;
		}
	}else{
		printf("erreur, format: main <niveau>\n");
		return 1;
	}
	*/
	niveau = 1;

	tableauTaille = tailleNiveau(fichierNiveaux, niveau);
	nLignes = tableauTaille[0];
	nColonnes = tableauTaille[1];
/*	tableauNiveau = lireNiveau(fichierNiveaux, niveau, nLignes, nColonnes);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 1, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 3, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 3, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 3, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 3, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	deplacement(tableauNiveau, 3, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);                   //test manuel
	deplacement(tableauNiveau, 2, plJoueur, pcJoueur);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);  */
	
	while (1) {  //1 tant que la condition de reussite est pas codée
		printf("\033[H\033[2J"); //equivalent au system clear (le prof prefere)
		dep = litEntree();
		deplacement(tableauNiveau, dep, plJoueur, pcJoueur);
		afficherNiveau(tableauNiveau, nLignes, nColonnes);
	}	
	return 0;
}
