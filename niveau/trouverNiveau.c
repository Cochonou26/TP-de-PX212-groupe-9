#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "trouverNiveau.h"
#include "util.h"

void trouverNiveau(char *fichierNiveaux, int niveau, FILE **rfpp){
	char *strNiveau, *s;

	if ((strNiveau = malloc(sizeof(char)*20)) == NULL)
		perror("malloc");
	sprintf(strNiveau, ";LEVEL %d\n",niveau);
	printf("niveau : %s", strNiveau);

	if ((*rfpp = fopen(fichierNiveaux, "r")) == NULL)
		perror("fopen");
	if ((s = malloc(sizeof(char)*MAXSIZE)) == NULL)
		perror("malloc");
	while (fgets(s, MAXSIZE, *rfpp) != NULL){
		if (!strcmp(s, strNiveau))
			break;
	}
}
