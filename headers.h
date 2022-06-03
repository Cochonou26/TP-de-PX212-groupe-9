typedef struct deplacement{
	int *nbMouvements;
	int *nbPoussees
	char *mouvement;
	char *poussee;
	deplacement *next;	
}deplacement;

char *[][] lectureTableau(int niveau); // renvoie le niveau
void afficheTableau(char *niveau[][]); // affiche le tableau sur le terminal
//char gestionEntree(?);
char verifDeplacement(char *niveau[][]); // renvoie un "booléen"
void deplacement (char *niveau[][]); // modifie le niveau
char detecReussite(char *niveau[][]); // renvoit un booléen
void comptage(int *nbMouvements, int *nbPoussees);
void annulerDeplacement(deplacement *trajet);
void sauvegarder(FILE *fichierSauvegarde);
void enregistrerSolution(FILE *fichierSolutions);
