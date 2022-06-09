#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_

#include "global.h"

int sauvegarderNiveau(char *fSauvegarde, int numNiveau, Dep *pile, char *mode);
int repriseSauvegarde(char *fSauvegarde, Niveau *pNiveau, Dep **pile, int *compteurCoups);
int detecterNumNiveau(char *fSauvegarde);

#endif
