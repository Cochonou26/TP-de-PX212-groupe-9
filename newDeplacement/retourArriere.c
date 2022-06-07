#include <stdlib.h>
#include <stdio.h>
#include "retourArriere.h"
#include "util.h"

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


int retourArriere(Niveau *pNiveau, Dep **pile) {
	Dep *deplacement;
	
	if ((*pile)->prev == NULL)
		return 0;

	deplacement = *pile;
	*pile = deplacement->prev;
	if (*deplacement->direction == 1) {
		if (*deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur - 1][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
	}
	if (*deplacement->direction == 2) {
		if (*deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur + 1][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
	}
	if (*deplacement->direction == 3) {
		if (*deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 1] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
		}
	}
	if (*deplacement->direction == 4) {
		if (*deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
		}
		if (*deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 1] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
		}
	}
	else{
		free(deplacement->caisse);
		free(deplacement->direction);
		free(deplacement);
		return 1;
	}
	free(deplacement->caisse);
	free(deplacement->direction);	
	free(deplacement);
	return 0;
}
