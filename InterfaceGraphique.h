#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"
#include <stdlib.h>
#include <gtk/gtk.h>
#define hauteur 500
#define largeur 500
GtkWidget *Fenetre;
int langue=0;

#endif

//dans un autre fichier
void ConvertisseurTableau(gchar T[],int *TailleTexte,gchar* Texte);
gchar* ConvertisseurChar(char T[],int TailleTexte);
gchar* CryptageSubstitution(gchar* TexteClair);
gchar* DecryptageSubstitution(gchar* TexteClair);
gchar* CryptageVigenere(gchar* TexteClair, gchar* Cle);
gchar* DecryptageVigenere(gchar* TexteClair);
gchar* LireFichier(const gchar* chemin);
void Enregistrer (GtkWidget *p_widget, GtkWidget *text );
void RecupererChemin(GtkWidget *bouton, GtkWidget *file_selection);
void ChoisirFichier()
//interface
void ViderContenaire(GtkContainer * container);
void MenuResultatSubstitution(GtkWidget *Fenetre, gchar* Text_crypt);
void MenuResultatVigenere(GtkWidget *Fenetre, gchar* Text_crypt, gchar* cle);
void MenuResultatAnalyse(GtkWidget *Fenetre);
void MenuResultatDecryptageSubstitution(GtkWidget *Fenetre, gchar* Text_crypt , gchar* cle);
void MenuResultatDecryptageVigenere(GtkWidget *Fenetre, gchar* Text_crypt , gchar* cle);
void BoiteDialogueSubstitution(GtkWidget *Fenetre);
void BoiteDialogueVigenere(GtkWidget *Fenetre);
void BoiteDialogueAnalyse(GtkWidget *Fenetre);
void BoiteDialogueDecryptageSubstitution(GtkWidget *Fenetre);
void BoiteDialogueDecryptageVigenere(GtkWidget *Fenetre);
void MenuDecryptageVigenere(GtkWidget *Fenetre);
void MenuDecryptageSubstitution(GtkWidget *Fenetre);
void MenuCryptageVigenere(GtkWidget *Fenetre);
void MenuCryptageSubstitution(GtkWidget *Fenetre);
void MenuAnalyseFrequentielle(GtkWidget *Fenetre);
void MenuDecryptage(GtkWidget *Fenetre);
void MenuCryptage(GtkWidget *Fenetre);
void MenuPrincipal(GtkWidget *Fenetre);
