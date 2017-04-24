#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialise(Arc G[V][V])
{	//initialise le graphe
	int i, j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			G[j][i].nom = "";
			G[j][i].poids = 1000;
			G[j][i].depart = "Sommet inconnu";
			G[j][i].arrivee = "Sommet inconnu";
			G[j][i].nbArcs = 0;
		}
	}
}
	
char* nomSommet(int indiceSommet)
{	//prend un indice de sommet dans le tableau et retourne le nom du sommet correspondant
	if (indiceSommet==0)
		return "Pic blanc";
	if (indiceSommet==1)
		return "Grotte de glace";
	if (indiceSommet==2)
		return "Lac blanc";
	if (indiceSommet==3)
		return "Sommet 3060";
	if (indiceSommet==4)
		return "Glacier de sarenne";
	return "Sommet inconnu";
}

int indiceSommet(char nomSommet[]) //comparaison impossible 
{	//prend un indice de sommet dans le tableau et retourne le nom du sommet correspondant
	if (!strcmp(nomSommet,"younes"))
		return 0;
	if (!strcmp(nomSommet,"Grotte_de_glace"))
		return 1;
	if (!strcmp(nomSommet,"Lac_blanc"))
		return 2;
	if (!strcmp(nomSommet,"Sommet_3060"))
		return 3;
	if (!strcmp(nomSommet,"bens"))
		return 4;
	return 5;
}

char* nomArc(int indiceArc)
{	//prend un indice d'arc et retourne le nom de l'arc correspondant
	if (indiceArc==0)
		return "descente du tunnel 1";
	if (indiceArc==1)
		return "descente de la breche";
	if (indiceArc==2)
		return "descente du tunnel 2";
	if (indiceArc==3)
		return "descente du glacier";
	if (indiceArc==4)
		return "descente de sarenne";
	if (indiceArc==5)
		return "telepherique pic blanc";
	if (indiceArc==6)
		return "telesiege glacier";
	return "arc inconnu";
}

void lectureGraphe(char* nomFichier, Arc G[V][V])
{
	FILE* F = fopen(nomFichier,"r");	//doit etre deja present, sinon NULL
	
	if (F == NULL){
		printf("fichier du graphe introuvable\n");
		return;
	}
	
	int k, temps, experience = getExperience();
	
	initialise(G);
		
	for (k = 0; k < E; k++)			//boucle qui parcourt les lignes du fichier : E lignes <=> E arcs en comptant les arcs qui se repetent
	{
		int i, j, indiceArc, couleur;
		//i : indice du sommet de départ, j : indice du sommet d'arrivée
		
		fscanf(F,"%d %d %d %d %d",&i, &j, &indiceArc, &couleur, &temps);
		
		G[i][j].depart = nomSommet(i);
		G[i][j].arrivee = nomSommet(j);
		G[i][j].nbArcs++;
		G[i][j].nom = nomArc(indiceArc);
		G[i][j].poids = calculPoids(couleur,temps,experience);
		
	}
	
	fclose(F);
	
}

void afficheGraphe(Arc G[V][V])
{
	printf("\n######################################### AFFICHAGE DU GRAPHE #########################################\n");
	int i,j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			while (G[i][j].nbArcs!=0){
					printf("%s\t->\t%s\t %d arc(s) : %s de poids %d\n",G[i][j].depart,G[i][j].arrivee,G[i][j].nbArcs,G[i][j].nom,G[i][j].poids);

			}
		}
		
	}
}
