#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "lectureTableau.h"
#include "util.h"

/**
 * Retourne la longueur du nombre de niveaux max
 * Inclus dans la longueur les caractères '\n' et '\0'
 */
int longueurNbNiveaux(char *fichierNiveaux)
{
	FILE *rfp;
	char *strMaxLevel = "MAXLEVEL ", *strComparaison;
	char longueurStrMaxLevel = strlen(strMaxLevel);
	int c, l = 2;
	
	if ((rfp = fopen(fichierNiveaux, "r")) == NULL) // Ouverture fichier
		perror("fopen");
	if ((strComparaison = malloc(sizeof(char) * (longueurStrMaxLevel + 1))) == NULL)//Alloc comp
		perror("malloc");
	while ((c = fgetc(rfp)) != EOF){
		if (c == ';'){
			fgets(strComparaison, longueurStrMaxLevel + 1, rfp);
			if (!strcmp(strComparaison, strMaxLevel)){ // Si detection ";MAXLEVEL "
				while ((c = fgetc(rfp)) != '\n')
					l++;
				if (fclose(rfp) == EOF)
					perror("fclose");
				return l;
			}
		}
	}
	return 1;
}

int trouverNiveau(char *fichierNiveaux, int niveau, FILE **rfpp)
{
	char *strNiveau = "LEVEL ", *strNumero, *strComparaison;
	char longueurStrNiveau = strlen(strNiveau);
	int c, maxStrNumero;

	if ((maxStrNumero = longueurNbNiveaux(fichierNiveaux)) == 1)
		perror("longueurNbNiveaux");
	if ((strNumero = malloc(sizeof(char) * maxStrNumero)) == NULL) // Allocation num. niveau
		perror("malloc");
	snprintf(strNumero, maxStrNumero, "%d\n", niveau); // Création num. niveau
	if ((strComparaison = malloc(sizeof(char) * (longueurStrNiveau))) == NULL)//Alloc comp.
		perror("malloc");
	if ((*rfpp = fopen(fichierNiveaux, "r")) == NULL) // Ouverture fichier
		perror("fopen");
	while ((c = fgetc(*rfpp)) != EOF){
		if (c == ';'){
			fgets(strComparaison, longueurStrNiveau + 1, *rfpp);
			if (!strcmp(strComparaison, strNiveau)){ // Si detection ";LEVEL "
				fgets(strComparaison, maxStrNumero, *rfpp);
				if (!strcmp(strComparaison, strNumero)) // Si detection bon numero
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

	trouverNiveau(fichierNiveaux, niveau, &rfp);
	
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

	if (fclose(rfp) == EOF)
		perror("fclose");
	
	if ((tableauTaille = malloc(2*sizeof(int))) == NULL)
		perror("malloc");
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
	
	trouverNiveau(fichierNiveaux, niveau, &rfp);
	//allocation memoire du tableau
	if ((tabNiveau = malloc(sizeof(char **)*nLignes)) == NULL)
		perror("malloc");
	for (iLigne = 0; iLigne < nLignes; iLigne++){
		if ((tabNiveau[iLigne] = malloc(sizeof(char *)*nColonnes)) == NULL)
			perror("malloc");
	}
	
	//remplissage du tableau
	for (iLigne = 0; iLigne < nLignes; iLigne++){
		for (iColonne = 0; iColonne < (nColonnes + 1); iColonne++){ // + 1 pour '\n'
			c = fgetc(rfp);
			if ((tabNiveau[iLigne][iColonne] = malloc(sizeof(char))) == NULL)
				perror("malloc");
			*tabNiveau[iLigne][iColonne] = c;
			if (c == '\n')
				break;
		}
	}

	if (fclose(rfp) == EOF)
		perror("fclose");
	return tabNiveau;
}

