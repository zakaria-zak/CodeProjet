
#include <stdlib.h>
#include <gtk/gtk.h>

typedef struct phoneme{
	int frequence;
	gchar* nom;
}PHONEME;
typedef struct analyse{ 
	int nb; 
	float occ[25];
	PHONEME di[25]; 
	PHONEME tr[25];
	gchar* pgor;
}ANALYSE;
typedef struct ressourceslangue{
	float occ[25];
	PHONEME di[25];
	PHONEME tr[25];
}RESSOURCESLANGUE;
int Kasiski(ANALYSE freq, gchar* texteCrypte){
	return 4;
}
	
void indiceMutuelle(int cle[], int kasiski, ANALYSE freq, RESSOURCESLANGUE prob, gchar* safecle)
{ 
	int mg[25][kasiski];
	int i,j;
	for (j = 0; j < kasiski; j++)
	{
		for (i = 0; i < 25; i++)
		{
					
		}
	}
cle[0]=12;
cle[1]=2;
cle[2]=7;
}
gchar* decrypteur( int cle[], int kasiski, gchar* texteCrypte){
	int test; test =1;
	}
RESSOURCESLANGUE TabRessource(){
	RESSOURCESLANGUE tabre;
	int i;
	for (i = 0; i < 25; i++)
	{
		tabre.occ[i] = 2;	
	};
	return tabre;
}
ANALYSE AnalyseFrequentielle(gchar* TextClair){
	int i;
	ANALYSE freq;
	freq.occ[0] = 0.01;  freq.occ[14] = 0.14;
	freq.occ[1] = 0.02;  freq.occ[15] = 0.15;
	freq.occ[2] = 0.03;  freq.occ[16] = 0.16;
	freq.occ[3] = 0.04;  freq.occ[17] = 0.17;
	freq.occ[4] = 0.05;  freq.occ[18] = 0.18;
	freq.occ[5] = 0.06;  freq.occ[19] = 0.19;
	freq.occ[6] = 0.07;  freq.occ[20] = 0.2;
	freq.occ[7] = 0.08;  freq.occ[21] = 0.21;
	freq.occ[8] = 0.09;  freq.occ[22] = 0.22;
 	freq.occ[9] = 0.1;   freq.occ[23] = 0.23;
	freq.occ[10] = 0.11; freq.occ[24] = 0.24;
	freq.occ[11] = 0.12; freq.occ[25] = 0.25;
	freq.occ[12] = 0.13; 

		
	return freq;
};
gchar* DecryptageVigenere(gchar* texteCrypte, gchar* safecle){
	RESSOURCESLANGUE don;
	ANALYSE req;
	int i,kasiski;
		
	don = TabRessource();  // remplie la structure avec les proba de la langue choisi.
	req = AnalyseFrequentielle(texteCrypte); //remplie la structure avec les fréquences du texte
	kasiski = Kasiski(req, texteCrypte); //recupere le PGOR (ou tri) et le texte clair, retourne taille cle
	int cle[kasiski];
	indiceMutuelle(cle, 3, req, don, safecle);
	decrypteur(cle, kasiski, texteCrypte);
		
	for (i = 0; i < 3; i++){
		printf(" \n valeur cle[%d] = %d \n", i, cle[i]); // printf(" \n cle[0] = %d \n", cle[0]);
	}
printf(" \n  premiere valeur des proba : %f \n", don.occ[0]);
printf(" \n  premiere valeur des fréquences : %f \n", req.occ[0]);
printf(" \n  taille de la clef : %d \n", kasiski); 
	return texteCrypte;
}

int main(int argc, char **argv)
{
	gchar texteCrypte, sauvegardecle;
	//texteCrypte = "coucou"; // COMMENT DECLARER LE TEXTE ? (pointeur ou pas?)
	DecryptageVigenere( &texteCrypte, &sauvegardecle); 
	return 0; 
}	
