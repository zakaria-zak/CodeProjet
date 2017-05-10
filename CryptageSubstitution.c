#include "CryptageSubstitution.h"

gchar* CryptageSubstitution(gchar* TexteClair)
{ 
	int taille;
	ConvertisseurTableau(TexteClair,&taille,TexteClair);
    return TexteClair;
}
