int replacerObjectif(char ***tableau, int numNiveau, FILE *rfp);

typedef struct objectif{
  int lPos;
  int cPos;
  int compteur;
  objectif *next;
}objectif;
