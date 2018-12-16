CFLAGS= -Wall -c -g -I.

all : partie1 testDijkstra pcc

partie1 : partie1.o lectureFichier.o graphe.o afficherGraphe.o 
	gcc -o $@ $^

testDijkstra : graphe.o lectureFichier.o dijkstra.o  testDijkstra.o  liste.o  
	gcc -o $@ $^


pcc : graphe.o lectureFichier.o dijkstra.o liste.o reseauroutieramericain.o AffichageDijkstragraphe2.o equivalentnumero.o
	gcc -o $@ $^

%.o : %.c
	gcc $(CFLAGS) $<

clean :
	rm -f *.o 

