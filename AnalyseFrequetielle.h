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
