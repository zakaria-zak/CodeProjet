all: dcrypt

run:	dcrypt
		./dcrypt
		
dcrypt:		main.o graphe.o fonctions.o
			gcc -g -Wall main.o graphe.o fonctions.o -o dcrypt
		
main.o:	main.c graphe.h fonctions.h 
		gcc -c -Wall main.c

InterfaceGraphique.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

CryptageSubstitution.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

CryptageVigenere.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

DecryptageSubstitution.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

DecryptageVigenere.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

AnalyseFrequentielle.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

Fonctions.o:	fonctions.c definitions.h graphe.h
				gcc -c -Wall fonctions.c

clean:
	rm *.o
	rm dcrypt
