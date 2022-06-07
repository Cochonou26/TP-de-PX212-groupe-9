#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int remplacerObjectif(niveau * pNiveau){

  int compteur=0;

  while ((pNiveau->tabCible[compteur])!=NULL){

    if (*pNiveau->tabNiveau[pNiveau->tabCible[compteur][0]][pNiveau->tabCible[compteur][1]]==SOL){
      *pNiveau->tabNiveau[pNiveau->tabCible[compteur][0]][pNiveau->tabCible[compteur][1]]=CIBLE;
    }

    else if (*pNiveau->tabNiveau[pNiveau->tabCible[compteur][0]][pNiveau->tabCible[compteur][1]]==CAISSE){
      *pNiveau->tabNiveau[pNiveau->tabCible[compteur][0]][pNiveau->tabCible[compteur][1]]=ARRIVE;
    }

    compteur++;
    
  }

  return 1;
}