#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "util.h"
#include "deplacement.h"

int sauvegarderTableau(Dep *pile, int numNiveau){

  FILE* wfp=NULL;

  wfp=efopen("sauvegarde.txt","w+");
  char stockage[2];
  sprintf(stockage,"%d",numNiveau);
  fputs(stockage[0],wfp);
  fputc(';',wfp);
  Dep *tampon=pile;
  while (pile->prev!=NULL){
    fputc(pile->direction,wfp);
    pile=pile->prev;
    free(tampon);
    tampon=pile;
  }
  efclose(wfp);
  return 0;
}

int verifierSauvegarde(){

  FILE* rfp=NULL;
  rfp=fopen("enregistrement.txt","r");
  if (fgetc(rfp)==EOF){
    fclose(rfp);
    return 1;
  }
  efclose(rfp);
  return 0;
}


int repriseSauvegarde(Dep *pile, Niveau *pNiveau, int *compteurCoups){

  FILE* rfp=NULL;
  rfp=efopen("enregistrement.txt","r");
  char *mvts=emalloc(100*sizeof(char));
  fseek(rfp,-1,SEEK_END);
  mvts[0]=fgetc(rfp);
  while (*mvts!=EOF){
    deplacement(pNiveau,litSauvegarde(*mvts),&pile, compteurCoups);
    fseek(rfp,-2,SEEK_CUR);
    *mvts=fgetc(rfp);
  }
  free(mvts);
  efclose(rfp);
  return 0;
}


int enregistrement(Dep *pile, int numNiveau){
  FILE* wfp=NULL;
  Dep* tampon=pile;
  char stockage[20];
  int numDirection;
  wfp=efopen("enregistrement.txt","a");
  sprintf(stockage,"%d",numNiveau);
  fputc(stockage[0],wfp);
  fputc(';',wfp);
  while (tampon->prev!=NULL){
    numDirection=(int)tampon->direction;
    fputc(numDirection,wfp);
    tampon=tampon->prev;
  }
  fputc('\n',wfp);
  efclose(wfp);
  return 0;
}


int chercherNiveau(){
  FILE* rfp=NULL;
  int numNiveau=0;
  int compteur=0;
  char* strNumNiveau;
  rfp=efopen("enregistrement.txt","r");

  while(fgetc(rfp)!=(';' || EOF)){
    compteur++;
  }

  strNumNiveau=emalloc(sizeof(char)*compteur+1);
  fseek(rfp,0,SEEK_SET);
  fgets(strNumNiveau,compteur+1,rfp);
  numNiveau=(int)strtol(strNumNiveau,NULL,10);

  efclose(rfp);
  free(strNumNiveau);
  return numNiveau;
}
