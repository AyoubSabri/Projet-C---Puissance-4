#include <stdio.h>
#include "manipulationGrille.h"
#include "main.h"

extern int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];
extern int nb_jetons_colonne[NB_COL_GRILLE_VUES];
extern int coups_joues;

/*
Je donne à la fonction les cordonnées d'une case et elle renvoie son contenu (-1,1,0)
*/

int demanderCouleurDeLaCaseXY(int absVue, int ordVue)
{
	return grille[absVue][ordVue];
}

int nbDeJetonsColonne(int numColonne)
{
	return nb_jetons_colonne[numColonne]; 
}

void ajouterJeton(int choixJoueur)
{
	
	if (coups_joues % 2 == 0) // turno giocatore 1 JAUNE
	{
		grille[NB_LIG_GRILLE_MODELE - DECALAGE - nbDeJetonsColonne(choixJoueur) ][choixJoueur + DECALAGE] = JAUNE; 
	}
	else // turno giocatore 2 ROUGE
	{
		grille[NB_LIG_GRILLE_MODELE - DECALAGE - nbDeJetonsColonne(choixJoueur) ][choixJoueur + DECALAGE] = ROUGE; 
	}
}