#include <stdio.h>
#include "lectureTableau.h"
#include "affichageTableau.h"

int main(int argc, char *argv[]){
	int niveau;
	char *fichierNiveaux = "levels.lvl";
	char ***tableauNiveau;
	int *tableauTaille;
	int nLignes, nColonnes;

	if (argc != 1 && (*argv[1] - 48 > 0))
		niveau = *argv[1] - 48;
	else{
		printf("erreur, format: main <niveau>\n");
		return 1;
	}

	tableauTaille = tailleNiveau(fichierNiveaux, niveau);
	nLignes = tableauTaille[0];
	nColonnes = tableauTaille[1];
	tableauNiveau = lireNiveau(fichierNiveaux, niveau, nLignes, nColonnes);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	return 0;
}
