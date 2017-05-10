#ifndef DEF_DEF
#define DEF_DEF
	

#endif

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

#define TAILLEMAX 1000
#define hauteur 500
#define largeur 500

int langue;
int choix;

GtkWidget *Fenetre;

typedef struct phoneme{
	int frequence;
	gchar* nom;
}PHONEME;

typedef struct analyse{ 
	int nb;  //taille des tableaux
	float occ[25];
	PHONEME di[25]; 
	PHONEME tr[25];
	gchar* pgor;
}ANALYSE;

typedef struct ressourceslangue{
	float occ[25];
	PHONEME di[25];
	PHONEME tr[25];
}RESSOURCESLANGUE;


void RetirerCarSpecMajuscule(gchar chaine[], gchar copy[]);
void LireFichier(gchar TexteClaire[] ,int TailleMax ,const gchar* chemin);
void ConvertisseurTableau(gchar T[],int *TailleTexte,gchar* Texte);
