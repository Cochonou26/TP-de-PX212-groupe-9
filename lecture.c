#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int lectureTableau(int niveau, int **matrice){
  FILE* fichier=NULL;
  char *lecture=malloc(MAXSIZE*sizeof(char));
  char *level=malloc(MAXSIZE*sizeof(char));
  int i=0;
  int compteur=0;
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
    strcpy(matrice[compteur],lecture);
    compteur++;
  }

//Retirer le free tableau lors de l'implémentation finale, et le passer en paramètre

  free(lecture);
  free(level);
  fclose(fichier);
  return 0;
}
