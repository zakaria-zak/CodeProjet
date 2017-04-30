all: dcrypt

run:	dcrypt
		./dcrypt
		
dcrypt:		main.o InterfaceGraphique.o Fonctions.o AnalyseFrequentielle.o CryptageSubstitution.o CryptageVigenere.o DecryptageSubstitution.o DecryptageVigenere.o
			gcc -g -Wall main.o InterfaceGraphique.o Fonctions.o AnalyseFrequentielle.o CryptageSubstitution.o CryptageVigenere.o DecryptageSubstitution.o DecryptageVigenere.o -o dcrypt

main.o:	main.c InterfaceGraphique.h
		gcc -c -Wall main.c

InterfaceGraphique.o:	InterfaceGraphique.c Fonctions.h AnalyseFrequentielle.h CryptageSubstitution.h CryptageVigenere.h DecryptageSubstitution.h DecryptageVigenere.h
				gcc -c -Wall InterfaceGraphique.c

CryptageSubstitution.o:	CryptageSubstitution.c Fonctions.h
				gcc -c -Wall CryptageSubstitution.c

CryptageVigenere.o:	CryptageVigenere.c Fonctions.h
				gcc -c -Wall CryptageVigenere.c

DecryptageSubstitution.o:	DecryptageSubstitution.c Fonctions.h AnalyseFrequentielle.h
				gcc -c -Wall DecryptageSubstitution.c

DecryptageVigenere.o:	DecryptageVigenere.c Fonctions.h AnalyseFrequentielle.h
				gcc -c -Wall DecryptageVigenere.c

AnalyseFrequentielle.o:	AnalyseFrequentielle.c Fonctions.h
				gcc -c -Wall AnalyseFrequentielle.c

Fonctions.o:	Fonctions.c Definitions.h 
				gcc -c -Wall Fonctions.c

clean:
	rm *.o
	rm dcrypt
