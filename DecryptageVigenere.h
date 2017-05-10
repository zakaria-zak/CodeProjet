#ifndef DEF_DEF
#define DEF_DEF

#include "Fonctions.h"
#include "AnalyseFrequentielle.h"

#endif

gchar* DecryptageVigenere(gchar* TexteClair);
gchar* DecryptageVig(gchar* texteCrypte, gchar* safecle);
int Kasiski(ANALYSE freq, gchar* TexteCrypte);
void indiceMutuelle(int cle[], int kasiski, ANALYSE freq, RESSOURCESLANGUE prob, gchar** safecle); //MODIF : int* car renvoie un tableau d'entier. utiliser tabdynamique(malloc)
gchar* decrypteur( int T[], int kasiski, gchar* TexteCrypte);
ANALYSE AnalyseFreq(gchar* TextClair);
RESSOURCESLANGUE TabRessource();
