#include "CryptageVigenere.h"

void CryptageVigenere(gchar* resultat,gchar* texteClair,gchar* Cle)
{
   int i;
   gchar a,b,c;
   int length = strlen(Cle);
		for ( i = 0; i < strlen(texteClair); i++)
		{
			a= texteClair[i] - 97;
			b= Cle[i%length] - 97;
			c = (a+b) ;
			if(c > 25)
				c=c-26;
			resultat[i] = c + 97;
		}
}
