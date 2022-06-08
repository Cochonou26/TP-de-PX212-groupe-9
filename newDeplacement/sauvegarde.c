#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

int sauvegarderTableau(Dep *pile, int numNiveau){

  FILE* wfp=NULL;

  wfp=efopen("sauvegarde.txt","w+");
  fputs(numNiveau,wfp);
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
  rfp=fopen("sauvegarde.txt","r");
  if (rfp==NULL){
    fclose(rfp);
    return 1;
  }
  efclose(rfp);
  return 0;
}


int repriseSauvegarde(Dep *pile, Niveau *pNiveau, int *compteurCoups){

  FILE* rfp=NULL;
  rfp=efopen("sauvegarde.txt","r");
  char *mvts=emalloc(sizeof(char));
  fseek(rfp,-1,SEEK_END);
  mvts=fgetc(rfp);
  while (mvts!=NULL){
    deplacement(pNiveau,*mvts,&pile, compteurCoups);
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
  wfp=efopen("enregistrement.txt","w");
  fputs(numNiveau,wfp);
  while (tampon->prev!=NULL){
    fputc(tampon->direction,wfp);
    tampon=tampon->prev;
  }
  efclose(wfp);
  return 0;
}


int chercherNiveau(){
  FILE* rfp=NULL;
  int numNiveau=0;
  int compteur=0;
  char* strNumNiveau;
  rfp=efopen("sauvegarde.txt","r");

  while(fgetc(rfp)!=';'){
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
