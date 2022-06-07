#include "util.h"

typedef struct Dep {
	char *direction;
	char *caisse;
	struct Dep *prev;
}Dep;

int empilerDeplacement(char direc, char depCaisse, Dep *pile);
int retourArriere(niveau *pNiveau, Dep *pile);
