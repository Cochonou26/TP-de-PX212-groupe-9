#include <stdio.h>
#include "tailleNiveau.h"

void afficherNiveau(char ***tableauNiveau, int nLignes, int nColonnes){
	int iLigne, iColonne;
	char c;

	for (iLigne = 0; iLigne < nLignes; iLigne++){
		for (iColonne = 0; iColonne < nColonnes; iColonne++){
			c =*tableauNiveau[iLigne][iColonne];
			printf("%c", c);
			if (c == '\n')
				break;
		}
	}
}
