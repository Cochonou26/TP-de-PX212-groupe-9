#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "deplacement.h"

int
sauvegarderNiveau(char *fSauvegarde, int numNiveau, Dep *pile, char *mode)
{
	FILE *wfp;
	int longStrNumNiveau;
	char *strNumNiveau;
	Dep *tampon;

	wfp = efopen(fSauvegarde, mode);
	longStrNumNiveau = (int)log10(numNiveau) + 1;
        strNumNiveau = emalloc(sizeof(char) * (longStrNumNiveau + 1));
        snprintf(strNumNiveau, longStrNumNiveau + 1, "%d", numNiveau);
	
	if (fputc('!', wfp) == EOF){
		free(strNumNiveau);
		efclose(wfp);
		return 1;
	}
	if (fputs(strNumNiveau, wfp) == EOF){
		free(strNumNiveau);
		efclose(wfp);
		return 1;
	}
	if (fputc(';', wfp) == EOF){
		free(strNumNiveau);
		efclose(wfp);
		return 1;
	}
	
	while (pile->prev != NULL){
		tampon = pile;
		pile = pile->prev;
		if (fputc(tampon->direction + 48, wfp) == EOF){
			free(strNumNiveau);
			efclose(wfp);
			return 1;
		}
	}
	if (fputc('\n', wfp) == EOF){
		free(strNumNiveau);
		efclose(wfp);
		return 1;
	}
	free(strNumNiveau);
	efclose(wfp);
	return 0;
}

int
detecterSauvegarde(char *fSauvegarde)
{
	FILE *rfp;
	
	rfp = fopen(fSauvegarde, "r");
	if (rfp == NULL)
		return 1;
	if (fgetc(rfp) == EOF){
		efclose(rfp);
		return 1;
	}
	efclose(rfp);
	return 0;
}

int
repriseSauvegarde(char *fSauvegarde, Niveau *pNiveau, Dep **pile, int *compteurCoups)
{
	FILE *rfp;
	int c;

	if (detecterSauvegarde(fSauvegarde)){
		printf("Aucun déplacement sauvegardé\n");
		return 1;
	}	
	rfp = efopen(fSauvegarde, "r");
	fseek(rfp, -2, SEEK_END);
	while ((c = fgetc(rfp)) != ';'){
		if (c == EOF){
			efclose(rfp);
			return 1;
		}
		deplacement(pNiveau, c - 48, pile, compteurCoups, 0, fSauvegarde);
		fseek(rfp, -2, SEEK_CUR);
	}
	return 0;
}

int
detecterNumNiveau(char *fSauvegarde)
{
	FILE *rfp;
	int c, longStrNumNiveau, numNiveau;
	char *strNumNiveau;

	if (detecterSauvegarde(fSauvegarde)){
		printf("Pas de sauvegarde trouvée");
		return 0;
	}
	longStrNumNiveau = 0;
	rfp = fopen(fSauvegarde, "r");
	if ((c = fgetc(rfp)) == EOF){
		printf("Pas de numéro de niveau dans la sauvegarde\n");
		fclose(rfp);
		return 0;
	}

	for (longStrNumNiveau = 0; (c = fgetc(rfp)) != ';'; longStrNumNiveau++){
		if (c == EOF){
			printf("Pas de numéro de niveau dans la sauvegarde\n");
			fclose(rfp);
			return 0;
		}
	}
	strNumNiveau = emalloc(sizeof(char) * (longStrNumNiveau + 1));
	fseek(rfp, 1, SEEK_SET);
	fgets(strNumNiveau, longStrNumNiveau + 1, rfp);
	numNiveau = (int)strtol(strNumNiveau, NULL, 10);
	free(strNumNiveau);
	fclose(rfp);
	return numNiveau;
}
