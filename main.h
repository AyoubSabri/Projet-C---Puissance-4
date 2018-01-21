#include <stdio.h>
#include <stdbool.h>

#define CONFIGURATION_GAGNANTE 4
#define DECALAGE CONFIGURATION_GAGNANTE - 1

#define NB_COL_GRILLE_VUES 7
#define NB_COL_GRILLE_MODELE NB_COL_GRILLE_VUES + 2*DECALAGE

#define NB_LIG_GRILLE_VUES 6
#define NB_LIG_GRILLE_MODELE NB_LIG_GRILLE_VUES + 2*DECALAGE

#define NB_MAX_COUPS_JEU NB_LIG_GRILLE_VUES * NB_COL_GRILLE_VUES + 2

#define JAUNE 1
#define ROUGE -1
#define VIDE 0

int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];
int nb_jetons_colonne[NB_COL_GRILLE_VUES];

int jouerCoupPuissance4(void);
bool estCoupInvalide(int colonneJouee);
int jouerPartiePuissance4(void);
bool estCoupGagnant(int choixJoueur);





