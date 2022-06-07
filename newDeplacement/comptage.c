void main {
;
}
 
void comptage(deplacement *dep, char incM, char incP){
	if (incM)
		dep->nbMouvements = dep->next->nbMouvements + 1;
	if (incP)
		dep->nbPousees = dep->next->nbPousees + 1;
}

