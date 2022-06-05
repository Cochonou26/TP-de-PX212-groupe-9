#include "util.h"

int deplacement (char ***tableauNiveau, char dep, int *lJoueur, int *cJoueur){
	switch (dep){
		case 1: // haut
			switch (*tableauNiveau[*lJoueur - 1][*cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
					return 0;
				case CAISSE:
					if ((*tableauNiveau[*lJoueur - 2][*cJoueur] != SOL) && (*tableauNiveau[*lJoueur - 2][*cJoueur] != CIBLE)) // Deplacement impossible
						return 0;
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur - 2][*cJoueur] = CAISSE; // Deplacement avec poussee
					*tableauNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 2: // bas
			switch (*tableauNiveau[*lJoueur + 1][*cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
					return 0;
				case CAISSE:
					if ((*tableauNiveau[*lJoueur + 2][*cJoueur] != SOL) && (*tableauNiveau[*lJoueur + 2][*cJoueur] != CIBLE)) // Deplacement impossible
						return 0;
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur + 2][*cJoueur] = CAISSE; // Deplacement avec poussee
					*tableauNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 3: // droite
			switch (*tableauNiveau[*lJoueur][*cJoueur + 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussee
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur][++(*cJoueur)] = JOUEUR;
					return 0;
				case CAISSE:
					if ((*tableauNiveau[*lJoueur][*cJoueur + 2] != SOL) || (*tableauNiveau[*lJoueur][*cJoueur + 2] != CIBLE)) // Deplacement impossible
						return 0;
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur][*cJoueur + 2] = CAISSE; // Deplacement avec poussee
					*tableauNiveau[*lJoueur][++(*cJoueur)] = JOUEUR;
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 4: // gauche
			switch (*tableauNiveau[*lJoueur][*cJoueur - 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussee
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur][--(*cJoueur)] = JOUEUR;
					return 0;
				case CAISSE:
					if ((*tableauNiveau[*lJoueur][*cJoueur - 2] != SOL) && (*tableauNiveau[*lJoueur][*cJoueur - 2] != CIBLE)) // Deplacement impossible
						return 0;
					*tableauNiveau[*lJoueur][*cJoueur] = SOL;
					*tableauNiveau[*lJoueur][*cJoueur - 2] = CAISSE; // Deplacement avec poussee
					*tableauNiveau[*lJoueur][--(*cJoueur)] = JOUEUR;
					return 0;
				default:
					return 1;
			}
		default:
			return 1;
	}
	return 1;
}
