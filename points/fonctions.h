#include "util.h"

void afficherNiveau(char ***tableauNiveau, int nLignes, int nColonnes);
int deplacement (niveau *pNiveau, char dep);
niveau *creerNiveau(char *fichierNiveaux, int numNiveau);
int configureTerminal();
int litClavier();
int remplacerObjectif(niveau * pNiveau);
int *tailleNiveau(int numNiveau, FILE *rfp);
int trouverNiveau(int numNiveau, FILE *rfp);
