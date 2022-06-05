#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "lectureTableau.h"
#include "util.h"

/**
 * Retourne la longueur du nombre max de niveaux
 * Inclus dans la longueur les caractères '\n' et '\0'
 */
int longNbNiveaux(char *fichierNiveaux)
{
	FILE *rfp;
	char *strMaxLevel = "MAXLEVEL ", *strComp;
	char longStrMaxLevel = strlen(strMaxLevel);
	int c, l = 2;
	
	rfp = efopen(fichierNiveaux, "r");
	strComp = emalloc(sizeof(char) * (longStrMaxLevel + 1));
	
	while ((c = fgetc(rfp)) != EOF){
		if (c == ';'){
			fgets(strComp, longStrMaxLevel + 1, rfp); //Obtenir metadonnee
			if (!strcmp(strComp, strMaxLevel)){ // Si ";MAXLEVEL "
				while ((c = fgetc(rfp)) != '\n') // Comptage nombre de caracteres
					l++;
				efclose(rfp);
				return l;
			}
		}
	}
	return 1;
}

int trouverNiveau(char *fichierNiveaux, int niveau, FILE **rfpp)
{
	char *strNiveau = "LEVEL ", *strNumero, *strComp;
	char longStrNiveau = strlen(strNiveau);
	int c, maxStrNumero;

	if ((maxStrNumero = longNbNiveaux(fichierNiveaux)) == 1)
		perror("Nombre max de niveaux non trouvé");
	strNumero = emalloc(sizeof(char) * maxStrNumero);
	snprintf(strNumero, maxStrNumero, "%d\n", niveau); // Création str num niveau
	strComp = emalloc(sizeof(char) * (longStrNiveau));
	*rfpp = efopen(fichierNiveaux, "r");
	
	while ((c = fgetc(*rfpp)) != EOF){
		if (c == ';'){
			fgets(strComp, longStrNiveau + 1, *rfpp); //Obtenir metadonnee
			if (!strcmp(strComp, strNiveau)){ // Si ";LEVEL "
				fgets(strComp, maxStrNumero, *rfpp); // Obtenir numero
				if (!strcmp(strComp, strNumero)) // Si bon numero
					return 0;
			}
		}

	}
	return 1;
}

int *tailleNiveau(char *fichierNiveaux, int niveau)
{
	FILE *rfp;
	int nLignes = 0, nColonnes = 0, *tableauTaille;
	int c, colonnesTemp = 0;

	if (trouverNiveau(fichierNiveaux, niveau, &rfp) == 1)
		perror("Niveau non trouvé");
	
	//Comptage taille niveau
	while (((c = fgetc (rfp)) != EOF) && (c != ';')){
		if (c == '\n'){
			nLignes++;
			nColonnes = MAX(colonnesTemp, nColonnes);
			colonnesTemp = 0;
		}
		else
			colonnesTemp++;
	}
	if (c == EOF){
		nLignes++;
		nColonnes = MAX(colonnesTemp, nColonnes);
	}

	efclose(rfp);
	
	tableauTaille = emalloc(2*sizeof(int));
	tableauTaille[0] = nLignes;
	tableauTaille[1] = nColonnes;
	return tableauTaille;
}

char *** lireNiveau(char *fichierNiveaux, int niveau, int nLignes, int nColonnes)
{
	FILE *rfp = NULL;
	char ***tabNiveau = NULL;
	int iLigne, iColonne;
	int c;
	
	if (trouverNiveau(fichierNiveaux, niveau, &rfp) == 1)
		perror("Niveau non trouvé");

	// Allocation memoire du tableau
	tabNiveau = emalloc(sizeof(char **)*nLignes);
	for (iLigne = 0; iLigne < nLignes; iLigne++)
		tabNiveau[iLigne] = emalloc(sizeof(char *)*nColonnes);
	
	// Remplissage du tableau
	for (iLigne = 0; iLigne < nLignes; iLigne++){
		for (iColonne = 0; iColonne < (nColonnes + 1); iColonne++){ // + 1 pour '\n'
			c = fgetc(rfp);
			tabNiveau[iLigne][iColonne] = emalloc(sizeof(char));
			*tabNiveau[iLigne][iColonne] = c;
			if (c == '\n')
				break;
		}
	}

	efclose(rfp);
	return tabNiveau;
}

