#include "global.h"

int remplacerObjectifs(Niveau *pNiveau){

  int iCible;

  for (iCible = 0; iCible < pNiveau->nCibles; iCible++){
    if (pNiveau->tabNiveau[pNiveau->tabCibles[iCible][0]][pNiveau->tabCibles[iCible][1]] == SOL){
      pNiveau->tabNiveau[pNiveau->tabCibles[iCible][0]][pNiveau->tabCibles[iCible][1]] = CIBLE;
    }
    if (pNiveau->tabNiveau[pNiveau->tabCibles[iCible][0]][pNiveau->tabCibles[iCible][1]] == CAISSE){
      pNiveau->tabNiveau[pNiveau->tabCibles[iCible][0]][pNiveau->tabCibles[iCible][1]] = ARRIVE;
    }
  }
  return 0;
}
