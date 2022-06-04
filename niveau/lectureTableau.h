#include <stdio.h>
void trouverNiveau(char *fichierNiveaux, int niveau, FILE **rfp);
int *tailleNiveau(char *fichierNiveaux, int niveau);
char *** lireNiveau(char *fichierNiveaux, int niveau, int nLignes, int nColonnes);

