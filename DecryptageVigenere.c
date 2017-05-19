#include "DecryptageVigenere.h"

int Kasiski(ANALYSE freq, gchar* texteCrypte){

	int i,j,kas,taillepgor;
	
	taillepgor = strlen(freq.pgor);
	
	int nbrpgor = 0;
	int distance[10];
	
	for (i = 0; i < strlen(texteCrypte); i++)
	{
		for (j = 0; j < taillepgor; j++)
		{
			if(freq.pgor[j] == texteCrypte[i]){
				if(j == taillepgor-1){
					distance[nbrpgor] = i-(taillepgor-1);
					nbrpgor++;
				}
				i++;
			}
			else if(texteCrypte[i] == freq.pgor[0]){
				j=0;
				i++;
			}
			else break;
		}
		
	}
	kas = distance[0];
	j=0;
	for (i = 1; i < nbrpgor+1; i++)
	{
		//kas = pgcd(kas,distance[i]);
		j++;
	}
	
	
	return kas;
}
	
void indiceMutuelle(int cle[], int kasiski, ANALYSE freq, RESSOURCESLANGUE prob, gchar safecle[])
{ 
	float mg[25][kasiski];
	int w; // w = n/m
	int i,j;
	double VraiIndice;
	w = freq.nb/kasiski;
	for (j = 0; j < kasiski; j++)	//Ici, remplissage tableau Mg avec les indices de coincidences 
	{
		for (i = 0; i < 25; i++)
		{
					mg[i][j] = (prob.occ[i]*freq.occ[i+j])/w;
		}
	}
	
	i =0; j=0;
	for(j=0;j<kasiski;j++){   //ici on selectionne la valeurs de chaque ligne la plus proche de 0.065 
		VraiIndice	= 2;//on initialise a une grande valeur pour être sur que la premiere valeur du tableau soit affecter a Vraiindice(a modifier si on a temps)
		for (i = 0; i < 25; i++)
		{
			if(fabs(mg[i][j] - 0.065) < VraiIndice){
				VraiIndice = fabs(mg[i][j] - 0.065);
					cle[j] = i; 		
			}
		}
	}	
			
	
	
//affecter la valeur de fin a safecle
for (i = 0; i <kasiski ; i++)
{
	safecle[i] = cle[i] + 97;
}

printf(" \n valeur tableau mg: %f \n", mg[0][0]);	
printf(" \n valeur tableau mg: %f \n", mg[0][1]);
printf(" \n valeur tableau mg: %f \n", mg[1][2]);
printf(" \n valeur tableau mg: %f \n", mg[1][3]);
printf(" \n valeur tableau mg: %f \n", mg[0][0]);
}
gchar* decrypteur( int cle[], int kasiski, gchar* texteCrypte){

	return texteCrypte;
	}
RESSOURCESLANGUE TabRessource(){
	RESSOURCESLANGUE tabre;
	int i;
	
		tabre.occ[0] = 7.68; 	/*a*/		tabre.occ[14] = 5.34;	/*o*/
		tabre.occ[1] = 0.80;    /*b*/		tabre.occ[15] = 3.24;	/*p*/	
		tabre.occ[2] = 3.32; 	/*c*/		tabre.occ[16] = 1,34;	/*q*/
		tabre.occ[3] = 3.60; 	/*d*/		tabre.occ[17] = 6.81;	/*r*/
		tabre.occ[4] = 17.76 ;	/*e*/		tabre.occ[18] = 8.23;	/*s*/
		tabre.occ[5] = 1.06; 	/*f*/		tabre.occ[19] = 7.30;	/*t*/
		tabre.occ[6] = 1.10; 	/*g*/		tabre.occ[20] = 6.05;	/*u*/
		tabre.occ[7] = 0.64; 	/*h*/		tabre.occ[21] = 1.27;	/*v*/
		tabre.occ[8] = 7.23; 	/*i*/		tabre.occ[22] = 0.17;	/*w*/
		tabre.occ[9] = 0.19; 	/*j*/		tabre.occ[23] = 0.54;	/*x*/
		tabre.occ[10] = 0.29; 	/*k*/		tabre.occ[24] = 0.21;	/*y*/
		tabre.occ[11] = 5.89; 	/*l*/		tabre.occ[25] = 0.07;	/*z*/
		tabre.occ[12] = 2.72;	/*m*/
		tabre.occ[13] = 7.61;	/*n*/
		
	return tabre;
}
ANALYSE AnalyseFrequentielle(gchar* TextClair){
	int i;
	ANALYSE freq;
	freq.occ[0] = 1.14;		/*a*/		freq.occ[14] = 3.57;	/*o*/
	freq.occ[1] = 0;	  	/*b*/		freq.occ[15] = 8.93;	/*p*/
	freq.occ[2] = 5.68;  	/*c*/		freq.occ[16] = 4.22;	/*q*/
	freq.occ[3] = 1.95;  	/*d*/		freq.occ[17] = 3.9;		/*r*/
	freq.occ[4] = 4.71;  	/*e*/		freq.occ[18] = 2.6;		/*s*/
	freq.occ[5] = 2.92;  	/*f*/		freq.occ[19] = 6.82;	/*t*/
	freq.occ[6] = 9.09;  	/*g*/		freq.occ[20] = 3.08;	/*u*/
	freq.occ[7] = 1.62;  	/*h*/		freq.occ[21] = 5.19;	/*v*/
	freq.occ[8] = 5.68;  	/*i*/		freq.occ[22] = 5.52;	/*w*/
 	freq.occ[9] = 0.16;   	/*j*/		freq.occ[23] = 4.06;	/*x*/
	freq.occ[10] = 3.25; 	/*k*/		freq.occ[24] = 5.68;	/*y*/
	freq.occ[11] = 3.25; 	/*l*/		freq.occ[25] = 2.44;	/*z*/
	freq.occ[12] = 2.44; 	/*m*/
	freq.occ[12] = 2.11; 	/*n*/
	
	freq.pgor = "abio"; //definiton du pgor
	freq.nb = 616;		// nombre de caractères dans le texte crypté
	return freq;
};
void DecryptageVigenere(gchar* resultat, gchar* texteCrypte, gchar savecle[]){
	RESSOURCESLANGUE don;
	ANALYSE req;
	int i,kasiski;
	
	don = TabRessource();  // remplie la structure avec les proba de la langue choisi.
	req = AnalyseFrequentielle(texteCrypte); //remplie la structure avec les fréquences du texte
	kasiski = Kasiski(req, texteCrypte); //recupere le PGOR (ou tri) et le texte clair, retourne taille cle
	int cle[kasiski];
	indiceMutuelle(cle, 3, req, don, savecle);  
	
	texteCrypte = decrypteur(cle, kasiski, texteCrypte);
		
	for (i = 0; i < 3; i++){
		printf(" \n valeur cle[%d] = %d \n", i, cle[i]); // printf(" \n cle[0] = %d \n", cle[0]);
	}

//printf(" \n  taille de la clef : %d \n", kasiski);
//printf(" \n  pgor trouver : %s \n", req.pgor);

strcpy(resultat,texteCrypte);
}


// CHAINE EN CLAIR:
//Titulaire du baccalaureat scientifique et actuellement en licence d'informatique, je souhaite mettre à profit le temps libre dont je dispose pendant les vacances dete. 
//Je suis donc à la recherche dune entreprise pour maccueillir de debut Juin a Septembre.
//Mon expérience professionnelle et ma formation universitaire mont transmis le sens de lorganisation et de la rigueur ainsi quune grande polyvalence et une motivation à toute épreuve
//Jespere avoir loccasion de vous présenter mon parcours mon dynamisme et ma bonne humeur lors d’un entretien En attendant un retour de votre part je reste à votre entiere disposition pour de plus amples informations 
//Je vous prie d’agreer Madame, Monsieur lexpression de ma consideration distinguee.
