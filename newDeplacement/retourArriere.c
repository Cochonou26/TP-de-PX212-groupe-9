#include <stdlib.h>
#include <stdio.h>
#include "retourArriere.h"


int empilerDeplacement(char direc,char depCaisse, Dep  **pile) {
	Dep *deplacement; 
	deplacement= emalloc(sizeof(Dep));
	deplacement->direction = emalloc(sizeof(char));
	deplacement->caisse = emalloc(sizeof(char));
	deplacement->prev = *pile;
	*deplacement->direction = direc;
	*deplacement->caisse = depCaisse;
	*pile = deplacement;
	return 0;
}


int retourArriere(niveau *pNiveau, Dep **pile) {
	int *lJoueur, *cJoueur;
	char ***tabNiveau;

	lJoueur = pNiveau->lJoueur;
	cJoueur = pNiveau->cJoueur;
	tabNiveau = pNiveau->tabNiveau;


	Dep *deplacement;
	deplacement = *pile;
	*pile = deplacement->prev;
	if (*deplacement->direction == 1) {
		if (*deplacement->caisse==0) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[*lJoueur + 2][*cJoueur] = CAISSE;
			*tabNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
		}
	}
	if (*deplacement->direction == 2) {
		if (*deplacement->caisse==0) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[*lJoueur - 2][*cJoueur] = CAISSE;
			*tabNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
		}
	}
	if (*deplacement->direction == 3) {
		if (*deplacement->caisse==0) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[(*lJoueur)][--(*cJoueur)] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[*lJoueur][*cJoueur - 2] = CAISSE;
			*tabNiveau[(*lJoueur)][--(*cJoueur)] = JOUEUR;
		}
	}
	if (*deplacement->direction == 4) {
		if (*deplacement->caisse==0) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[(*lJoueur)][++(*cJoueur)] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			*tabNiveau[*lJoueur][*cJoueur] = SOL;
			*tabNiveau[*lJoueur][*cJoueur + 2] = CAISSE;
			*tabNiveau[(*lJoueur)][++(*cJoueur)] = JOUEUR;
		}
	}
	else return 1;
	free(deplacement);
	return 0;
}
