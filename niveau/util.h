#include <stdio.h>

// Macro permettant de trouver le max de deux nombres
#define MAX(a,b) (a>b?a:b)

typedef struct niveau{
	char ***tabNiveau;
	int nLignes;
	int nColonnes;
	int lJoueur;
	int cJoueur;
}niveau;

void *emalloc(unsigned int n);
FILE *efopen(const char *fichier, const char *mode);
void efclose(FILE *stream);
void error(const char *msg);
void freeNiveau(niveau *pNiveau);

enum objets{SOL = ' ', MUR = '#', CAISSE = '$', JOUEUR = '@', CIBLE = '.'};

