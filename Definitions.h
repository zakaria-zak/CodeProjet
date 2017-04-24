#ifndef DEF_DEF
#define DEF_DEF

#endif



//definition du nombre de sommets et du nombre d'arcs du graphe orienté représentant la carte
#define V 6		//nombre de sommets
#define E 7		//nombre d'arcs

typedef struct arc Arc;

struct arc
{
	char*  nom;		//noms des arcs, liste de noms à laquelle on ajoute un element à chaque nouveau arc
	char* depart;	//nom sommet depart
	char* arrivee;	//nom sommet arrivee
	int poids;	
	int nbArcs;		//nombre d'arcs reliant le sommet de depart au sommet d'arrivee
};

struct parc{
	int sommet;
	int poid;
	int parcouru;
	};
typedef struct parc parcour;

struct ante{
	int sommet;
	int pere;
	};
typedef struct ante antecedant;

	Arc G[V][V];
