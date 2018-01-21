/*
	Programme écrit par Ayoub SABRI
	Novembre 2017 - Polytech Sorbonne
*/

#include <stdio.h>
#include "affichageGrille.h"
#include "main.h"

extern int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];

void afficherCase(int couleur)
{
	switch(couleur){
		case JAUNE :
			printf("[\e[1;33m*\e[0m]");
			break;
		case ROUGE :
			printf("[\e[1;31m+\e[0m]");
			break;
		case VIDE :
			printf("[ ]");
			break;
		default :
			printf("Valeur non connue");
	}
}

void afficherGrille(void){

	int i;
	int j;

	for(i = DECALAGE; i <= NB_LIG_GRILLE_MODELE - DECALAGE ; i++){
		printf("\n");
		for(j = DECALAGE; j <= NB_COL_GRILLE_MODELE - DECALAGE ; j++){
			 afficherCase(grille[i][j]);
		}	
	}
	printf("\n");

	for (int i = 0; i < NB_COL_GRILLE_VUES*3; i++)
	{
		printf("=");
	}
	printf("\n");

	for (int i = 0; i < NB_COL_GRILLE_VUES; i++)
	{
		printf("[%d]",i);
	}
	printf("\n");
}
