#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int lectureTableau(int niveau){
  FILE* lecture=NULL;
  FILE* sauvegarde=NULL;
  char *save=malloc(sizeof(char));
  char *fichier=malloc(sizeof(char));
  char *level=malloc(sizeof(char));
  lecture=fopen("levels.lvl","r");
  sauvegarde=fopen("sauvegarde.txt","a+");
  if ((lecture==NULL)||(sauvegarde==NULL)){
    printf("%s","Erreur dans l'ouverture des fichiers");
    free(save);
    free(fichier);
    free(level);
    fclose(sauvegarde);
    fclose(lecture);
  }

  while(fgets(fichier,MAXSIZE,lecture)!=NULL){
    *fichier=fichier[(strlen(fichier))-2];
    level=strcat(";LEVEL ",niveau);
    if (strcmp(fichier,level)==0){
      fgets(fichier,MAXSIZE,lecture);
      while(fichier[0]!=';'){
        printf("%s",fichier);
        fprintf(sauvegarde,"%s",fichier);
        fgets(fichier,MAXSIZE,lecture);
      }
    }
    else;
  }

  free(save);
  free(fichier);
  fclose(sauvegarde);
  fclose(lecture);
  free(level);
  return 0;
}
