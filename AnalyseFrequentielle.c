#include "AnalyseFrequentielle.h"
/*
ANALYSE analyse_frequentielle_zak(char* chaine){

ANALYSE a;	
//   PARTIE 1 :           compte le nb de caracteres du texte et remplir "ANALYSE.nb":        
	a.nb=strlen(chaine);
// FIN PARTIE 1



//   PARTIE 2 :           compte le nb d'occurences de chaque lettre et remplir "ANALYSE.occ":        
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	
	int i,j,compteur;
	for(i=0;i<25;i++)
	{
		compteur=0;
			for(j=0;j<a.nb;j++)
			{
				if(alphabet[i]==chaine[j])
				compteur++;
			}
			a.occ[i]=compteur;
	}
// FIN PARTIE 2

int taille_tab_di = a.nb-1;


char tmp1[2];
char tmp2[2];
char tmp3[2];

int k = 0;

	for(i=0; i<taille_tab_di; i++)
	{
		tmp1[0] = chaine[i];
		tmp1[1] = '\0';
		
		tmp2[0] = chaine[i+1];
		tmp2[1] = '\0';
				
		
		strcat(tmp1, tmp2);
		
		int ok = 1;
		
		for (j = 0; j < k ; j++)
		{
			if ( strcmp(a.di[j].nom,tmp1) == 0)
			{
				ok =0;
				a.di[j].frequence +=1;
			}
		}
		
		if (ok == 1)
		{
			strcpy(a.di[k].nom, tmp1);
			a.di[k].frequence =1;
			k++;
		}
	}
	
//////////////////////
	
int taille_tab_tri = a.nb - 2;
k = 0;

	for(i=0; i<taille_tab_tri; i++)
	{
		tmp1[0] = chaine[i];
		tmp1[1] = '\0';
		
		tmp2[0] = chaine[i+1];
		tmp2[1] = '\0';
				
		tmp3[0] = chaine[i+2];
		tmp3[1] = '\0';
				
		
		strcat(tmp1, tmp2);
		strcat(tmp1, tmp3);
		
		int ok = 1;
		
		for (j = 0; j < k ; j++)
		{
			if ( strcmp(a.tr[j].nom,tmp1) == 0)
			{
				ok =0;
				a.tr[j].frequence +=1;
			}
		}
		
		if (ok == 1)
		{
			strcpy(a.tr[k].nom, tmp1);
			a.tr[k].frequence =1;
			k++;
		}
	}
	strcpy(a.pgor,a.tr[0].nom);
	int indice=0;
	for (i = 1; i < k; i++)
	{
		if(a.tr[i].frequence > a.tr[indice].frequence)
		{
			indice = i; 
			strcpy(a.pgor,a.tr[i].nom);
		} 
	}
	
	return a;
}
*/
