#ifndef DEF_DEF
#define DEF_DEF

#include "definitions.h"

#endif

void initialise(Arc G[V][V]);
char* nomSommet(int indiceSommet);
int indiceSommet(char nomSommet[]);
char* nomArc(int indiceArc);
void lectureGraphe(char* nomFichier, Arc G[V][V]);
void afficheGraphe(Arc G[V][V]);


gchar* DecryptageVigenere(gchar* TexteCrypte);
int Kasiski(ANALYSE freq, gchar* TexteCrypte);
int* indiceMutuelle(int kasiski, ANALYSE freq, ANALYSE ressource); //MODIF : int* car renvoie un tableau d'entier. utiliser tabdynamique(malloc)
gchar* decrypteur( int T[], int kasiski, gchar* TexteCrypte);
