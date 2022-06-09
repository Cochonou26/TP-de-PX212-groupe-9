#include <stdio.h>
#include "retourArriere.h"

int deplacement(Niveau *pNiveau, char dep, Dep **pile, int *compteurCoups){
	switch (dep){
		case 1: // flèche directionnelle haut
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur - 1][pNiveau->cJoueur]){
				case MUR: // Deplacement impossible car mur devant
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussée (seul le joueur se déplace)
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(1,0, pile); //premier argument : direction ; deuxième argument : poussée ou non
					(*compteurCoups)++; //incrémentation compteur de coups 
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] == ARRIVE)) // Deplacement impossible (mur, caisse, étoile)
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur - 2][pNiveau->cJoueur] = CAISSE; // Deplacement avec poussée (le joueur et la caisse se déplacent)
					(pNiveau->tabNiveau)[--(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(1,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 2: // flèche directionnelle bas
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur + 1][pNiveau->cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussée
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(2,0,pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] == ARRIVE)) // Deplacement impossible(mur, caisse, étoile) 
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur + 2][pNiveau->cJoueur] = CAISSE; // Deplacement avec poussée
					(pNiveau->tabNiveau)[++(pNiveau->lJoueur)][pNiveau->cJoueur] = JOUEUR;
					empilerDeplacement(2,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 3: // flèche directionnelle droite
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussée
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][++(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(3,0,pile);
					(*compteurCoups)++;
					return 0;
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] == ARRIVE)) // Deplacement impossible (mur, caisse, étoile)
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur + 2] = CAISSE; // Deplacement avec poussée
					(pNiveau->tabNiveau)[pNiveau->lJoueur][++(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(3,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 4: // flèche directionnelle gauche
			switch ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussée
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][--(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(4,0,pile);
					(*compteurCoups)++;
					return 0;	
				case ARRIVE:
				case CAISSE:
					if (((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] == MUR) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] == CAISSE) || ((pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur -  2] == ARRIVE)) // Deplacement impossible (mur, caisse, étoile)
						return 0;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur] = SOL;
					(pNiveau->tabNiveau)[pNiveau->lJoueur][pNiveau->cJoueur - 2] = CAISSE; // Deplacement avec poussée 
					(pNiveau->tabNiveau)[pNiveau->lJoueur][--(pNiveau->cJoueur)] = JOUEUR;
					empilerDeplacement(4,1,pile);
					(*compteurCoups)++;
					return 0;
				default:
					return 1;
			}
		case 114 : //touche r retour en arriere
			retourArriere(pNiveau, pile); 
			(*compteurCoups)--; //décrémentation unitaire du compteur de coups 
			return 0;
		case 127 : //touche suppression reinitialisation
			 while (((*pile)->prev) != NULL) {     //vidage de la pile de déplacement
				retourArriere(pNiveau, pile);
			 }
			 *compteurCoups = 0; //reinitialisation du compteur de coups 
			return 0;
		default:
			return 1;
	}
	return 1;
}
