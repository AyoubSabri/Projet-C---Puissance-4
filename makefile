all : puissance4

puissance4 : affichageGrille.o manipulationGrille.o main.o
	gcc -Wall affichageGrille.o manipulationGrille.o main.o -o puissance4

affichageGrille.o : affichageGrille.c affichageGrille.h
	gcc -Wall -c affichageGrille.c -o affichageGrille.o

manipulationGrille.o : manipulationGrille.c manipulationGrille.h
	gcc -Wall -c manipulationGrille.c -o manipulationGrille.o

main.o : main.c main.h
	gcc -Wall -c main.c -o main.o

clean :
	rm -rf *.o

.PHONY : all clean


