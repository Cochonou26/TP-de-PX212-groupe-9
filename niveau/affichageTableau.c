#include <stdio.h>
#include "affichageTableau.h"

void afficherNiveau(char ***tableauNiveau, int nLignes, int nColonnes){
	int iLigne, iColonne;
	char c;

	for (iLigne = 0; iLigne < nLignes; iLigne++){
		for (iColonne = 0; iColonne < nColonnes + 1; iColonne++){ // + 1 pour '\n'
			c = *tableauNiveau[iLigne][iColonne];
			putchar(c);
			if (c == '\n')
				break;
		}
	}
}
