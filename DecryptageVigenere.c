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
	int distance[10];
	int i,j,kas,taillepgor;
	//	for(i=0 ; i<freq.nb; i++){
	//}
	// kas =  PGCD(distance[], j)
	//SOLUTION YOUNES :
	//		ABIO . strlen => me donne la taille soit 4.
	//				strcut(4) => je découpe en morceau de 4 et je test si strcut(4) = ABIO
	//															si oui, jenregistre la position i
	//	CODE:															sinon je continu
	// taille = strlen(freq.pgor)
	// strcut(texteCrypte,taille)
	return 4;
}
	
void indiceMutuelle(int cle[], int kasiski, ANALYSE freq, RESSOURCESLANGUE prob, gchar** safecle)
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
*safecle = "coucouSAFE";
}
gchar* decrypteur( int cle[], int kasiski, gchar* texteCrypte){
	texteCrypte = "Decrypte";
	return texteCrypte;
	}
RESSOURCESLANGUE TabRessource(){
	RESSOURCESLANGUE tabre;
	int i;
	
		tabre.occ[0] = 7.11; 	/*a*/		tabre.occ[14] = 5.02;	/*o*/
		tabre.occ[1] = 1.14;    /*b*/		tabre.occ[15] = 2.49;	/*p*/	
		tabre.occ[2] = 3.18; 	/*c*/		tabre.occ[16] = 0,65;	/*q*/
		tabre.occ[3] = 3.67; 	/*d*/		tabre.occ[17] = 6.07;	/*r*/
		tabre.occ[4] = 12.10 ;	/*e*/		tabre.occ[18] = 6.51;	/*s*/
		tabre.occ[5] = 1.11; 	/*f*/		tabre.occ[19] = 5.92;	/*t*/
		tabre.occ[6] = 1.23; 	/*g*/		tabre.occ[20] = 4.49;	/*u*/
		tabre.occ[7] = 1.11; 	/*h*/		tabre.occ[21] = 1.11;	/*v*/
		tabre.occ[8] = 6.59; 	/*i*/		tabre.occ[22] = 0.17;	/*w*/
		tabre.occ[9] = 0.34; 	/*j*/		tabre.occ[23] = 0.38;	/*x*/
		tabre.occ[10] = 0.29; 	/*k*/		tabre.occ[24] = 0.46;	/*y*/
		tabre.occ[11] = 4.96; 	/*l*/		tabre.occ[25] = 0.15;	/*z*/
		tabre.occ[12] = 2.62;	/*m*/
		tabre.occ[13] = 6.39;	/*n*/
		
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
	
	freq.pgor = "abio"; //definiton du pgor
	freq.nb = 200;		// nombre de caractères dans le texte crypté
	return freq;
};
gchar* DecryptageVigenere(gchar* texteCrypte, gchar **safecle){
	RESSOURCESLANGUE don;
	ANALYSE req;
	int i,kasiski;
	//safecle = malloc(sizeof(char)*20);
	don = TabRessource();  // remplie la structure avec les proba de la langue choisi.
	req = AnalyseFrequentielle(texteCrypte); //remplie la structure avec les fréquences du texte
	kasiski = Kasiski(req, texteCrypte); //recupere le PGOR (ou tri) et le texte clair, retourne taille cle
	int cle[kasiski];
    texteCrypte = "MAJ";
	*safecle = "sauvegarde";
	indiceMutuelle(cle, 3, req, don, safecle);  // LA CHAINE SAFECLE NEST PAS MODIFIER PAR LA FONCTION
	
	texteCrypte = decrypteur(cle, kasiski, texteCrypte);
		
	for (i = 0; i < 3; i++){
		printf(" \n valeur cle[%d] = %d \n", i, cle[i]); // printf(" \n cle[0] = %d \n", cle[0]);
	}
//printf(" \n  premiere valeur des proba : %f \n", don.occ[0]);
//printf(" \n  premiere valeur des fréquences : %f \n", req.occ[0]);
//printf(" \n  taille de la clef : %d \n", kasiski);
//printf(" \n  pgor trouver : %s \n", req.pgor);

	return texteCrypte;
}

int main(int argc, char **argv)
{
	gchar *texteCrypte, **sauvegardecle, *texteDecrypte;
	texteCrypte = "Leabiotexteestabiocrypteetilvaabiofalloirsenoccuper"; 
	*sauvegardecle = "init_cle";
	texteDecrypte = DecryptageVigenere( texteCrypte, sauvegardecle); // LES CHAINES NE SONT PAS MODIFIER PAR LA FONCTION 
	
	printf(" \n  texteDecrypte trouver : %s \n", texteDecrypte); 
	printf(" \n  cle sauvegarde 4 : %s \n", *sauvegardecle); 
	
	return 0; 
}	

// LES CHAINES NE SONT PAS MODIFIER => recherche google : comment modifier une chaine de caractere passer en argument d'une fonction
//bonjourcestunmessagedetestpournotreapplicationquiapourbutdedecrypterlesmessageschiffreravecvigenerefonctionne.lemessagedoitetrelongafindepouvoirfaireuneattaqueprobabilistecorrecte
//dzrlzytniueypxiudeiphgeiuetqfvpzxtperapknevtspbykltqfvdfxfphgnvaaxgcpgdqgdwcriunlkqjtpvcgiegmiprgcihzreemqyrg.wiopwulkgoskeivcinzriljkyhgaswgskcjctvgfrglxvluwpttzfcmmntwvpgqcvgnxg
