#ifndef _GLOBAL_H_
#define _GLOBAL_H_

typedef struct Niveau{
	char **tabNiveau;
	int nLignes;
	int nColonnes;
	int lJoueur;
	int cJoueur;
	int **tabCibles;
	int nCibles;
}Niveau;

typedef struct Dep {
	char direction;
	char caisse;
	struct Dep *prev;
}Dep;

enum objets{SOL = ' ', MUR = '#', CAISSE = '$', JOUEUR = '@', CIBLE = '.', ARRIVE = '*'};
enum touches{HAUT = 1, BAS = 2, DROITE = 3, GAUCHE = 4, R = 114, S = 115, SUPPR = 127};

#endif
