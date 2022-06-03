int main(int argc, int *argv[]){
	while (!finJeu){
		lireNiveau();
		afficherNiveau();
		while (!reussiteNiveau){
			switch (detectionTouche()){
				case rien:
					break;
				case sauvegarder:
					sauvergarderNiveau();
					break;
				case default:
					afficherNiveau();
				case up:
				case down:
				case left:
				case right:
					gestionDeplacement();
					comptage();
					detectionReussite();
					break;
				case recommencer:
					reinitialiserNiveau();
					break;
				case annuler:
					annulerCoup();
					break;
			}
			
		}
	}
	return 0;
}
