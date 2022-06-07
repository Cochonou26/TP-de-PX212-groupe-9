#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

/**
 * Place le rfp donné à la fin de la métadonnee demandée
 */
int trouverMeta(char *strMeta, FILE *rfp)
{
	char *strComp;
	int c, longStrMeta;

	// Creation strComp
	longStrMeta = strlen(strMeta);
	strComp = emalloc(sizeof(char) * longStrMeta + 1);

	// Recherche meta
	while ((c = fgetc(rfp)) != EOF){
		if (c == ';'){
			fgets(strComp, longStrMeta + 1, rfp); // Obtenir meta
			if (!strcmp(strComp, strMeta)){ // Si bonne meta
				free(strComp);
				return 0;
			}
		}
	}
	free(strComp);
	return 1;
}

/**
 * Lis une ligne jusqu'au caractère '\n', à partir d'un rfp
 */
void lireLigne(FILE *rfp)
{
	int c;

	while (((c = fgetc(rfp)) != EOF) && (c != '\n'));
}

/**
 * Place le rfp donné juste avant le premier caractère du niveau demandé
 */
int trouverNiveau(int numNiveau, FILE *rfp)
{
	char *strNiveau;
	int longStrNumNiveau, c;

	// Creation strNiveau
	longStrNumNiveau = (int)log10(numNiveau) + 1;
	strNiveau = emalloc(sizeof(char) * (strlen("LEVEL ") + longStrNumNiveau + 2));
	snprintf(strNiveau, strlen("LEVEL ") + longStrNumNiveau + 2, "LEVEL %d\n", numNiveau);

	// Recherche Niveau
	if (trouverMeta(strNiveau, rfp)){
		printf("Metadonnée \"%s\" non trouvée\n", strNiveau);
		free(strNiveau);
		return 1;
	}
	free(strNiveau);

	// Traitement d'éventuelles métadonnées
	while ((c = fgetc(rfp)) != EOF){
		if (c == ';')
			lireLigne(rfp);
		else{
			fseek(rfp, -1, SEEK_CUR);
			return 0;
		}
	}
	return 1;
}

int *tailleNiveau(int numNiveau, FILE *rfp)
{
	int nLignes, nColonnes, n, *tabTaille, nColonnesTemp, compteur;
	int c;
	n=0;

	nLignes = nColonnes = nColonnesTemp = compteur = 0;

	while (((c = fgetc(rfp)) != EOF) && (c != ';')){
		n++;
		if (c == '\n'){
			nLignes++;
			nColonnes = MAX(nColonnesTemp, nColonnes);
			nColonnesTemp = 0;
		}
		else {
			if (c == CIBLE){
				compteur++;
			}
			nColonnesTemp++;
		}
	}
	if (c == EOF){ // Ce qu'il faut faire est bizarre, à regarder
		n--;
		nColonnes = MAX(nColonnesTemp, nColonnes);
	}
	if (nLignes == 0 || nColonnes == 0)
		return NULL;

	tabTaille = emalloc(4*sizeof(int));
	tabTaille[0] = nLignes;
	tabTaille[1] = nColonnes;
	tabTaille[2] = n;
	tabTaille[3] = compteur;
	printf("Dimensions niveau : %d lignes, %d colonnes\n", nLignes, nColonnes);
	return tabTaille;
}

niveau * creerNiveau(char *fichierNiveaux, int numNiveau)
{
	niveau *pNiveau;
	FILE *rfp;
	int iLigne, iColonne, *tabTaille, compteur=0, i=0;
	int c;

	pNiveau = emalloc(sizeof(niveau));
	pNiveau->lJoueur = emalloc(sizeof(int));
	pNiveau->cJoueur = emalloc(sizeof(int));

	// Positionnement de rfp avant le niveau
	rfp = efopen(fichierNiveaux, "r");
	if (trouverNiveau(numNiveau, rfp)){
		efclose(rfp);
		printf("Niveau %d non trouvé\n", numNiveau);
		return NULL;
	}

	// Determination taille niveau
	if ((tabTaille = tailleNiveau(numNiveau, rfp)) == NULL){
		efclose(rfp);
		free(tabTaille);
		printf("Taille du niveau %d non trouvée\n", numNiveau);
		return NULL;
	}

	fseek(rfp, -(tabTaille[2] + 1), SEEK_CUR); // Retour de rfp avant le niveau
	pNiveau->tabCible=emalloc(tabTaille[3]*sizeof(int*));
	for (i=0;i<tabTaille[3];i++){
		pNiveau->tabCible[i]=emalloc(2*sizeof(int));
	}

	// Affectation taille niveau
	pNiveau->nLignes = tabTaille[0];
	pNiveau->nColonnes = tabTaille[1];
	free(tabTaille);


	// Allocation mémoire du tableau
	pNiveau->tabNiveau = emalloc(sizeof(char **) * pNiveau->nLignes);
	for (iLigne = 0; iLigne < pNiveau->nLignes; iLigne++){
		pNiveau->tabNiveau[iLigne] = emalloc(sizeof(char *) * (pNiveau->nColonnes + 1)); // + 1 pour '\n'
		for (iColonne = 0; iColonne < (pNiveau->nColonnes + 1); iColonne++){
			pNiveau->tabNiveau[iLigne][iColonne] = emalloc(sizeof(char));
			*pNiveau->tabNiveau[iLigne][iColonne] = SOL;
		}
	}

	// Remplissage du tableau
	for (iLigne = 0; iLigne < pNiveau->nLignes; iLigne++){
		for (iColonne = 0; iColonne < (pNiveau->nColonnes + 1); iColonne++){
			c = fgetc(rfp);
			*pNiveau->tabNiveau[iLigne][iColonne] = c;
			if (c == JOUEUR){
				*pNiveau->lJoueur = iLigne;
				*pNiveau->cJoueur = iColonne;
			}
			else if (c == CIBLE){
				(pNiveau->tabCible[compteur][0]) = iLigne;
				(pNiveau->tabCible[compteur][1]) = iColonne;
				compteur++;
			}
			else if (c == '\n')
				break;
		}
	}

	efclose(rfp);
	return pNiveau;
}
