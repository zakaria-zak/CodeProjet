#ifndef DEF_DEF
#define DEF_DEF

#include "Fonctions.h"
#include "AnalyseFrequentielle.h"

#endif

int longueurChaine(const char* chaine);

int Kasiski(ANALYSE freq, gchar* texteCrypte);

void indiceMutuelle(int cle[], int kasiski, ANALYSE freq, RESSOURCESLANGUE prob, gchar safecle[]);

RESSOURCESLANGUE TabRessource();

ANALYSE AnalyseFrequentielle(gchar* TextClair);

void DecryptageVigenere(gchar* resultat, gchar* texteCrypte, gchar savecle[]);
