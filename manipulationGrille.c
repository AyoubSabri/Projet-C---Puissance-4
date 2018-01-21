/*
	Programme écrit par Ayoub SABRI
	Novembre 2017 - Polytech Sorbonne
*/

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
	
	if (coups_joues % 2 == 0) // C'est au joueur n. 1 de jouer
	{
		grille[NB_LIG_GRILLE_MODELE - DECALAGE - nbDeJetonsColonne(choixJoueur) ][choixJoueur + DECALAGE] = JAUNE; 
	}
	else // C'est au joeur n. 2 de jouer
	{
		grille[NB_LIG_GRILLE_MODELE - DECALAGE - nbDeJetonsColonne(choixJoueur) ][choixJoueur + DECALAGE] = ROUGE; 
	}
}