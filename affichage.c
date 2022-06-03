#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int afficheTableau(int niveau){
  FILE* fichier=NULL;
  char *lecture=malloc(MAXSIZE*sizeof(char));
  char *level=malloc(MAXSIZE*sizeof(char));
  fichier=fopen("levels.lvl","r");
  if (fichier==NULL){
    printf("%s","Erreur dans l'ouverture des fichiers");
    free(lecture);
    free(level);
    fclose(fichier);
    return 0;
  }

  sprintf(level,";LEVEL %d",niveau);


  while(strcmp(lecture,level)!=0 && fgets(lecture,MAXSIZE,fichier)!=NULL){
    if ((lecture[strlen(lecture)-1]=='\n')){
      lecture[strlen(lecture)-1]='\0';
    }
  }

  while (fgets(lecture,MAXSIZE,fichier)!=NULL){
    if (lecture[0]==';') {
      break;
    }
    printf("%s",lecture);
  }

  free(lecture);
  free(level);
  fclose(fichier);
  return 0;
}
