all: ski

run:	ski
		./ski
		
ski: 	main.o graphe.o fonctions.o
			gcc -g -Wall main.o graphe.o fonctions.o -o ski
		
main.o:	main.c graphe.h fonctions.h 
		gcc -c -Wall main.c

graphe.o:	graphe.c fonctions.h
				gcc -c -Wall graphe.c

fonctions.o:	fonctions.c definitions.h graphe.h
				gcc -c -Wall fonctions.c

clean:
	rm *.o
	rm ski
