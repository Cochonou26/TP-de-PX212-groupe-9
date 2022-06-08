#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

int sauvegarderTableau(Dep *pile, int numNiveau){

  FILE* wfp=NULL;

  wfp=efopen("sauvegarde.txt","w+");
  fputs(numNiveau,wfp);
  while (pile->prev!=NULL){
    fputc(pile->direction,wfp);
    pile=pile->prev;
  }
  efclose(wfp);
  return 0;
}

int verifierSauvegarde(){

  FILE* rfp=NULL;
  rfp=efopen("sauvegarde.txt","r");
  efclose(rfp);
  return 0;
}

int repriseSauvegarde(Dep *pile, Niveau *pNiveau){

  FILE* rfp=NULL;
  rfp=efopen("sauvegarde.txt","r");
  char *mvts=emalloc(sizeof(char));
  mvts=fgetc(rfp);
  while (mvts!=NULL){
    deplacement(pNiveau,*mvts,&pile);
    *mvts=fgetc(rfp);
  }
  free(mvts);
  efclose(rfp);
  return 0;
}

int enregistrement(Dep *pile, int numNiveau){
  FILE* wfp=NULL;

  wfp=efopen("enregistrement.txt","w");
  fputs(numNiveau,wfp);
  while (pile->prev!=NULL){
    fputc(pile->direction,wfp);
    pile=pile->prev;
  }
  efclose(wfp);
  return 0;
}
