int main(int argc, int *argv[]){
	while (!finJeu){
		lireNiveau();
		afficherNiveau();
		while (!reussiteNiveau){
			switch (litEntree();){
				case 115: //touche S pour sauvegarder
					sauvergardePartie(FILE *fichierSauvegarde);
					break;
				case 114: //touche R pour recommencer
					reinitialiserNiveau(); // a voir pour affichage / reset
					break;
				case 127: //touche echap pour annuler
					annulerCoup(); // a voir pour affichage / reset
					break;
				case 1:    //ici on utiise la fonction dans deplacement.c (haut)
				case 2:    //bas
				case 3:    //gauche
				case 4:    //droite
					gestionDeplacement();
					comptage();
					detectionReussite();
				case default:
					afficherNiveau();
			}
		}
	}
	return 0;
}
