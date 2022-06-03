#include "lireNiveau.h"
#include "afficherNiveau.h"
#include "tailleNiveau.h"

int main(int argc, char *argv[]){
	int niveau = 1;
	char *fichierNiveaux = "levels.lvl";
	char ***tableauNiveau;
	int *tableauTaille;
	int nLignes, nColonnes;

	tableauTaille = tailleNiveau(fichierNiveaux, niveau);
	nLignes = tableauTaille[0];
	nColonnes = tableauTaille[1];
	tableauNiveau = lireNiveau(fichierNiveaux, niveau, nLignes, nColonnes);
	afficherNiveau(tableauNiveau, nLignes, nColonnes);
	return 0;
}
