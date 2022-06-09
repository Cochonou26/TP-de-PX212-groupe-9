#include "global.h"

/**
 * @brief La fonction vient prendre le numéro du niveau ainsi que les mouvements stockés dans la pile de la structure de déplacement pour les 
 * stocker dans un fichier sauvegarde.txt.
 * 
 * @param pile 
 * @param numNiveau 
 * @return int 
 */
int sauvegarderTableau(Dep *pile, int numNiveau);

/** @brief Cette fonction a pour but de verifier l'existance d'un fichier de sauvegarde.
 * 
 * @return int 
 */
int verifierSauvegarde();

/**
 * @brief Cette fonction permet de relancer le jeu à l'état dans lequel il a été sauvegardé 
 * à l'aide du fichier sauvegarde.txt créé précédemment.
 * 
 * @param pile 
 * @param pNiveau 
 * @param compteurCoups 
 * @return int 
 */
int repriseSauvegarde(Dep *pile, Niveau *pNiveau, int *compteurCoups);

/**
 * @brief Dans cette fonction nous réalisons un enregistrement de la solution trouvée pour un niveau et 
 * nous stockons cet enregistrement dans un fichier nommé enregistrement.txt.
 * 
 * @param pile 
 * @param numNiveau 
 * @return int 
 */
int enregistrement(Dep *pile, int numNiveau);

/**
 * @brief Cette fonction permet de récupérer le numéro du niveau dont les déplacements ont étés sauvegardés à l'aide de la 
 * fonction sauvegarderTableau.
 * 
 * @return int 
 */
int chercherNiveau();
