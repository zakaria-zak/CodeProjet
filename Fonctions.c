#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "string.h"

void RetirerCarSpecMajuscule(gchar chaine[], gchar copy[])
{
    int i,j = 0, lg;
    lg = strlen(chaine);
    
    for(i=0; i<lg; i++)
    {	
        if(chaine[i] != ' ' && chaine[i] != '\t' && chaine[i] != '\'' && chaine[i] != '\"') // Si c'ets pas un des ces caractere
        {
            copy[j] = chaine[i];
            
            if(copy[j] > 64 && copy[j] < 91) // Si C'est une majuscule
			{
				copy[j] = chaine[i] + 32;
			}
			
            j++;
        }
    }
    copy[j] = '\0';
}

void ConvertisseurTableau(gchar T[],int *TailleTexte,gchar* Texte){
	
	int i,j=0,doute = 0;
	gchar Tab[strlen(Texte)];
	RetirerCarSpecMajuscule(Texte,Tab);
	int taille = strlen(Tab);
	*TailleTexte = taille;
	
	for(i=0;i<taille;i++){
		gchar c = Tab[i];
		
		if(doute){
			doute = 0;
			if(c == -85 || c == -86 || c == -87 || c == -88){
				T[j] = 'e';
				j++;
			}
			else if(c == -92 || c == -94 || c == -96){
				T[j] = 'a';
				j++;
			}
			else if(c == -68 || c == -69){
				T[j] = 'u';
				j++;
			}
			else if(c == -81 || c == -82){
				T[j] = 'i';
				j++;
			}
		}
		else{
			doute = c == -61;
			if(doute) continue;
			T[j] = c;
			j++;
		}
	}
	T[j] = '\0';
	 
}

int main(){
	
	gchar* copie = "SaLUUUt j'apelle  L'ANalyse de Tkt pas c'est la folie Ras   eëêéèaäâàuüûiïî";
	gchar Newtab[strlen(copie)];
	int taille;
	ConvertisseurTableau(Newtab,&taille,copie);
	
	printf("\n %s \n", Newtab);
	
		
	
	return 0;
}
