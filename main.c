#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"

int coups_joues = 2;

bool estCoupInvalide(int colonneJouee){
	if (nb_jetons_colonne[colonneJouee] == NB_LIG_GRILLE_VUES){
		return true;
	}
	else{
		return false;
	}
}

bool estCoupGagnant(int choixJoueur){

	int ligneActuelle = NB_LIG_GRILLE_MODELE - DECALAGE - nbDeJetonsColonne(choixJoueur) + 1;
	int count = 0;
	int i = 0;

	/* Configuration verticale descendente */

	for (i = 0; i < CONFIGURATION_GAGNANTE; i++)
	{
		if(grille[ligneActuelle + i][choixJoueur + DECALAGE] == grille[ligneActuelle][choixJoueur + DECALAGE]){
			count++;
		}
	}

	if(count == CONFIGURATION_GAGNANTE){
		return true;
	}
	else{
		count = 0;
	}

	/* Configuration horizontale */
	
	i = 0;

	while(grille[ligneActuelle][choixJoueur + DECALAGE + i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	i = 1;

	while(grille[ligneActuelle][choixJoueur + DECALAGE - i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	if(count >= CONFIGURATION_GAGNANTE){
		return true;
	}
	else{
		count = 0;
	}

	/* Configuration diagonale droite */

	i = 0;

	while(grille[ligneActuelle - i][choixJoueur + DECALAGE - i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	i = 1;

	while(grille[ligneActuelle + i][choixJoueur + DECALAGE + i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	if(count >= CONFIGURATION_GAGNANTE){
		return true;
	}
	else{
		count = 0;
	}

	/* Configuration diagonale gauche */

	i = 0;

	while(grille[ligneActuelle - i][choixJoueur + DECALAGE + i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	i = 1;

	while(grille[ligneActuelle + i][choixJoueur + DECALAGE - i] == grille[ligneActuelle][choixJoueur + DECALAGE]){
		count++;
		i++;
	}

	if(count >= CONFIGURATION_GAGNANTE){
		return true;
	}
	else{
		return false;
	}
}

int jouerCoupPuissance4(void){
	
	int colonneJouee = 0;

	afficherGrille();

	printf("\nCoups joues %d \n", (coups_joues - 2));
	
	if (coups_joues % 2 == 0){
		printf("C'est au tour du joueur 1 \n"); //Joueur avec le jeton jaune (1)
	}
	else{
		printf("C'est au tour du joueur 2 \n"); //Joueur avec le jeton rouge (-1)
	}	
	
	printf("Choisissez une colonne (entre 0 et 6) : \n");
	scanf("%d",&colonneJouee);
	
	while(colonneJouee > NB_COL_GRILLE_VUES){
		printf("Attention, colonne pas valide! Choisissez une colonne pas remplie (entre 0 et 6) : \n");
		scanf("%d",&colonneJouee);
	}

	while(estCoupInvalide(colonneJouee)){
		printf("Attention, colonne pas valide! Choisissez une colonne pas remplie (entre 0 et 6) : \n");
		scanf("%d",&colonneJouee);
	}

	ajouterJeton(colonneJouee);
	nb_jetons_colonne[colonneJouee]++;
	coups_joues++;

	return colonneJouee;
}

int jouerPartiePuissance4(void){

	int coups_max = 0;
	int joueur_gagnant = 0;

	while( (coups_max | joueur_gagnant) == 0 ){

		if (coups_joues == NB_MAX_COUPS_JEU)
		{
			coups_max = 1;
			afficherGrille();
			coups_joues++;
		}
		else{
			int colonneJouee = jouerCoupPuissance4();
			
			if(estCoupGagnant(colonneJouee))
			{
				joueur_gagnant = 1;
			}	
		}
	}

	if (coups_max)
	{
		afficherGrille();
		return printf("\nPartie terminee, nombre max de coups atteint! \n");
	}
	else if (joueur_gagnant)
	{
		if( (coups_joues - 1) % 2 == 0)
		{
			afficherGrille();
			return printf("\nPartie terminee, joueur 1 gagnant!  \n");
		}
		else
		{
			afficherGrille();
			return printf("\nPartie terminee, joueur 2 gagnant!  \n");
		}
	}
	return 0;
}

int main(void){

	jouerPartiePuissance4();

	return 0;
}