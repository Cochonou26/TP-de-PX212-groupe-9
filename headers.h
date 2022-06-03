typedef struct deplacement{
	int *nbMouvements;
	int *nbPoussees
	char *mouvement;
	char *poussee;
	deplacement *next;	
}deplacement;

char *[][] lectureTableau(int niveau); // renvoie le niveau
void afficherNiveau(char *niveau[][]); // affiche le tableau sur le terminal
//char gestionEntree(?);
char verifDeplacement(char *niveau[][]); // renvoie un "booléen"
void deplacement (char *niveau[][], char dep, int xJoueur, int yJoueur); // modifie le niveau
char detecReussite(char *niveau[][]); // renvoit un booléen
void comptage(deplacement *dep, char incM, char incP);
void annulerDeplacement(deplacement *trajet);
void sauvegardePartie(FILE *fichierSauvegarde);
void sauvegardeSolution(FILE *fichierSolutions);
