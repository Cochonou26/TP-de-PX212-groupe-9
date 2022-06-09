#include <stdio.h>
#include "retourArriere.h"
#include "sauvegarde.h"

int deplacement(Niveau *pNiveau, char dep, Dep **pile, int *compteurCoups, int *numNiveau){
	switch (dep){
		case 1: // haut
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur - 1][pNiveau->cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(1,0, pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == ARRIVE)) // Deplacement impossible
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] = CAISSE; // Deplacement avec poussee
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(1,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 2: // bas
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur + 1][pNiveau->cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(2,0,pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == ARRIVE)) // Deplacement impossible
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] = CAISSE; // Deplacement avec poussee
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(2,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 3: // droite
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][++(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(3,0,pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == ARRIVE)) // Deplacement impossible
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] = CAISSE; // Deplacement avec poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][++(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(3,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 4: // gauche
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][--(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(4,0,pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur -  2] == ARRIVE)) // Deplacement impossible
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] = CAISSE; // Deplacement avec poussee
					(pNiveau->tabNiveau)[pNiveau->lJoueur][--(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(4,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1;
			}
		case 114 : //touche r retour en arriere
			retourArriere(pNiveau, pile);
			(*compteurCoups)--;
			return 0;
		case 127 : //touche suppression reinitialisation
			 while (((*pile)->prev) != NULL) {
				retourArriere(pNiveau, pile);
			 }
			 *compteurCoups = 0;
			return 0;
		case 115 : //touche s sauvegarde
			sauvegarderTableau(pile, numNiveau);
			numNiveau=89;
			return 2;
		default:
			return 1;
	}
	return 1;
}
