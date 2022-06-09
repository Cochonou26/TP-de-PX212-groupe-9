#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "util.h"

int empilerDeplacement(char direc,char depCaisse, Dep  **pile) {   //Fonction pour empiler un déplacement dans la pile de type Dep (cours)
	Dep *deplacement;	
	deplacement= emalloc(sizeof(Dep));
	deplacement->prev = *pile;
	deplacement->direction = direc;
	deplacement->caisse = depCaisse;
	*pile = deplacement;
	return 0;
}


int retourArriere(Niveau *pNiveau, Dep **pile) {   //Fonction pour annuler le coup précédent
	Dep *deplacement;
	
	if ((*pile)->prev == NULL)    //pas de déplacement précédent -> situation initiale
		return 0;

	deplacement = *pile;    //dépilage du dernier déplacement
	*pile = deplacement->prev;    //Connexion de Head avec le deuxième élément
	if (deplacement->direction == 1) { //direction du déplacement dépilé
		if (deplacement->caisse==0) { //On vérifie si il y a eu une poussée ou pas, puis on inverse le déplacement dépilé
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
		if (deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur - 1][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
	}
	if (deplacement->direction == 2) {
		if (deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
		if (deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur + 1][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
		}
	}
	if (deplacement->direction == 3) {
		if (deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
		}
		if (deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 1] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
		}
	}
	if (deplacement->direction == 4) {
		if (deplacement->caisse==0) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
		}
		if (deplacement->caisse== 1) {
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
			(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 1] = SOL;
			(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
		}
	}
	else{
		free(deplacement); //on libère la mémoire utilisée pour le déplacement dépilé
		return 1;
	}
	free(deplacement);
	return 0;
}
