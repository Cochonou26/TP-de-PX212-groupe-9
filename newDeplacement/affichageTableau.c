#include <stdio.h>
#include "global.h"

void afficherNiveau(Niveau *pNiveau){
	int iLigne, iColonne;
	char c;

	for (iLigne = 0; iLigne < pNiveau->nLignes; iLigne++){
		for (iColonne = 0; iColonne < pNiveau->nColonnes + 1; iColonne++){ // + 1 pour '\n'
			c = pNiveau->tabNiveau[iLigne][iColonne];
			putchar(c);
			if (c == '\n')
				break;
		}
	}
}
