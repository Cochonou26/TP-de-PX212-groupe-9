void main(){
;
}

void deplacement (char *niveau[][], char dep, int xJoueur, int yJoueur){
	switch (dep){
		case 1: // haut
			switch (*niveau[yJoueur + 1][xJoueur]){
				case '#': //deplacement impossible
					break;
				case ' ': 
				case '.': // mouvement sans poussee
					*niveau[++yJoueur][xJoueur] = '@';
					break;
				case '$':
					if (*niveau[yJoueur + 2][xJoueur] == '#') // deplacement impossible
						break;
					*niveau[yJoueur + 2][xJoueur] = '$'; //deplacement avec poussee
					*niveau[++yJoueur][xJoueur] = '@';
					break;
				case default:
					printf("erreur deplacement\n");
					break;
			}
		case 2: // bas
			switch (*niveau[yJoueur - 1][xJoueur]){
				case '#': //deplacement impossible
					break;
				case ' ': 
				case '.': // mouvement sans poussee
					*niveau[--yJoueur][xJoueur] = '@';
					break;
				case '$':
					if (*niveau[yJoueur - 2][xJoueur] == '#') // deplacement impossible
						break;
					*niveau[yJoueur - 2][xJoueur] = '$'; //deplacement avec poussee
					*niveau[--yJoueur][xJoueur] = '@';
					break;
				case default:
					printf("erreur deplacement\n");
					break;
			}
		case 3: // droite
			switch (*niveau[yJoueur][xJoueur + 1]){
				case '#': //deplacement impossible
					break;
				case ' ': 
				case '.': // mouvement sans poussee
					*niveau[yJoueur][++xJoueur] = '@';
					break;
				case '$':
					if (*niveau[yJoueur][xJoueur + 2] == '#') // deplacement impossible
						break;
					*niveau[yJoueur][xJoueur + 2] = '$'; //deplacement avec poussee
					*niveau[yJoueur][++xJoueur] = '@';
					break;
				case default:
					printf("erreur deplacement\n");
					break;
			}
		case 4: // gauche
			switch (*niveau[yJoueur][xJoueur - 1]){
				case '#': //deplacement impossible
					break;
				case ' ': 
				case '.': // mouvement sans poussee
					*niveau[yJoueur][--xJoueur] = '@';
					break;
				case '$':
					if (*niveau[yJoueur][xJoueur - 2] == '#') // deplacement impossible
						break;
					*niveau[yJoueur][xJoueur - 2] = '$'; //deplacement avec poussee
					*niveau[yJoueur][xJoueur--] = '@';
					break;
				case default:
					printf("erreur objet deplacement\n");
					break;
			}
		case default:
			printf("erreur deplacement");
	}
}
