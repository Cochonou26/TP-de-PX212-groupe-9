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


int retourArriere(Niveau *pNiveau, Dep **pile, int *compteurCoups) {   //Fonction pour annuler le coup précédent
	Dep *deplacement;
	
	if ((*pile)->prev == NULL)    //pas de déplacement précédent -> situation initiale
		return 0;

	deplacement = *pile;    //dépilage du dernier déplacement
	*pile = deplacement->prev;	//Connexion de Head avec le deuxième élément
	switch (deplacement->direction) {
		case 1 :
			switch (deplacement->caisse) {
				case 0 : //On vérifie si il y a eu une poussée ou pas, puis on inverse le déplacement dépilé
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					return 0;
				case 1 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
					(pNiveau->tabNiveau)[pNiveau->lJoueur - 1][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					return 0;
			}
		case 2 :
			switch (deplacement->caisse) {
				case 0 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					return 0;
				case 1 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
					(pNiveau->tabNiveau)[pNiveau->lJoueur + 1][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					return 0;
			}
		case 3 :
			switch (deplacement->caisse) {
				case 0 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
					return 0;
				case 1 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 1] = SOL;
					(pNiveau->tabNiveau)[(pNiveau->lJoueur)][--(pNiveau->cJoueur)] = JOUEUR;
					return 0;
			}
		case 4 :
			switch (deplacement->caisse) {
				case 0 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
					return 0;
				case 1 :
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = CAISSE;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 1] = SOL;
					(pNiveau->tabNiveau)[(pNiveau->lJoueur)][++(pNiveau->cJoueur)] = JOUEUR;
					return 0;
			}
		default :
			free(deplacement); //on libère la mémoire utilisée pour le déplacement dépilé
			(*compteurCoups)--;
			return 1;
	}
	free(deplacement);
	(*compteurCoups)--;
	return 0;
}
