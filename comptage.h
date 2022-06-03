typedef struct deplacement{
	int *nbMouvements;
	int *nbPoussees
	char *mouvement;
	char *poussee;
	deplacement *next;	
}deplacement;
/**
 * *nbMouvements représente le nombre de mouvements à partir du maillon actuel
 * *nbPoussees représente le nombre de Poussees à partir du maillon actuel
 * *mouvement représente le mouvement effectué au deplacement actuel
 * *poussee représente la poussee effectuée au déplacement actuel
 */

void comptage(int *nbMouvements, int *nbPoussees);
/**
 *incrémente si nécessaire le nombre de mouvements et de poussées du trajet
 */
