#include "graphe.h"
#include "fonctions.h"
#include <stdio.h> 


int main(int argc, char* argv[])
{
	char depart[100];
	char arrivee[100];
	antecedant a[V];
	parcour p[V]; 
	lectureGraphe("graphe.txt",G);
	printf("A quel endroit vous situez vous ?\n");
	scanf("%s",depart);
	printf("A quel endroit voulez vous acceder ?\n");
	scanf("%s",arrivee);
	printf("\n\n\n");
	initialise_tableau_antecedant(a);
	initialise_tableau_parcour(p,indiceSommet(depart));
	dijstra(indiceSommet(depart),indiceSommet(arrivee),a,p);   
	return 0;
}
 //si poid arrivée==1000 demande de remonter un peu a pied car chemin inexistant
 //le poid =1000 a modifier
