#include "retourArriere.h"


int deplacement (niveau *pNiveau, char dep, Dep *pile){
	int *lJoueur, *cJoueur;
	char ***tabNiveau;

	lJoueur = pNiveau->lJoueur;
	cJoueur = pNiveau->cJoueur;
	tabNiveau = pNiveau->tabNiveau;

	switch (dep){
		case 1: // haut
			switch (*tabNiveau[*lJoueur - 1][*cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
					empilerDeplacement(1,0, &pile);
					return 0;
				case CAISSE:
					if ((*tabNiveau[*lJoueur - 2][*cJoueur] != SOL) && (*tabNiveau[*lJoueur - 2][*cJoueur] != CIBLE)) // Deplacement impossible
						return 0;
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur - 2][*cJoueur] = CAISSE; // Deplacement avec poussee
					*tabNiveau[--(*lJoueur)][*cJoueur] = JOUEUR;
					empilerDeplacement(1,1,pile);
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 2: // bas
			switch (*tabNiveau[*lJoueur + 1][*cJoueur]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL:
				case CIBLE: // Deplacement sans poussee
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
					empilerDeplacement(2,0,pile);
					return 0;
				case CAISSE:
					if ((*tabNiveau[*lJoueur + 2][*cJoueur] != SOL) && (*tabNiveau[*lJoueur + 2][*cJoueur] != CIBLE)) // Deplacement impossible
						return 0;
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur + 2][*cJoueur] = CAISSE; // Deplacement avec poussee
					*tabNiveau[++(*lJoueur)][*cJoueur] = JOUEUR;
					empilerDeplacement(2,1,pile);
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 3: // droite
			switch (*tabNiveau[*lJoueur][*cJoueur + 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussee
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur][++(*cJoueur)] = JOUEUR;
					empilerDeplacement(3,0,pile);
					return 0;
				case CAISSE:
					if ((*tabNiveau[*lJoueur][*cJoueur + 2] != SOL) && (*tabNiveau[*lJoueur][*cJoueur + 2] != CIBLE)) // Deplacement impossible
						return 0;
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur][*cJoueur + 2] = CAISSE; // Deplacement avec poussee
					*tabNiveau[*lJoueur][++(*cJoueur)] = JOUEUR;
					empilerDeplacement(3,1,pile);
					return 0;
				default:
					return 1; // Erreur deplacement
			}
		case 4: // gauche
			switch (*tabNiveau[*lJoueur][*cJoueur - 1]){
				case MUR: // Deplacement impossible
					return 0;
				case SOL: 
				case CIBLE: // Deplacement sans poussee
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur][--(*cJoueur)] = JOUEUR;
					empilerDeplacement(4,0,pile);
					return 0;
				case CAISSE:
					if ((*tabNiveau[*lJoueur][*cJoueur - 2] != SOL) && (*tabNiveau[*lJoueur][*cJoueur - 2] != CIBLE)) // Deplacement impossible
						return 0;
					*tabNiveau[*lJoueur][*cJoueur] = SOL;
					*tabNiveau[*lJoueur][*cJoueur - 2] = CAISSE; // Deplacement avec poussee
					*tabNiveau[*lJoueur][--(*cJoueur)] = JOUEUR;
					empilerDeplacement(4,1,pile);
					return 0;
				default:
					return 1;
			}
		case 114 : //touche r réinitialisation
			retourArriere(pNiveau, pile);
			return 0;
		default:
			return 1;
	}
	return 1;
}
