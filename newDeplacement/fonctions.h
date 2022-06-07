
#include "retourArriere.h"

void afficherNiveau(char ***tableauNiveau, int nLignes, int nColonnes);
int deplacement (niveau *pNiveau, char dep, Dep **pile);
niveau *creerNiveau(char *fichierNiveaux, int numNiveau);
int configureTerminal();
int litClavier();

