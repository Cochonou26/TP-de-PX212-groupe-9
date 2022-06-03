int main(int argc, int *argv[]){
	while (!finJeu){
		lireNiveau();
		afficherNiveau();
		while (!reussiteNiveau){
			switch (litEntree();){
				case sauvegarder:
					sauvergardePartie(FILE *fichierSauvegarde);
					break;
				case recommencer:
					reinitialiserNiveau(); // a voir pour affichage / reset
					break;
				case annuler:
					annulerCoup(); // a voir pour affichage / reset
					break;
				case up:
				case down:
				case left:
				case right:
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
