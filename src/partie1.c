#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
	printf("debut de la fonction main\n");
	int nbrs;
	int nbarc;	
	/*nbrs=nbSommets("monfichier.txt");*/
	GRAPH G;
	G=lectureFichier("monfichier.txt", &nbrs,&nbarc);
	printf("lectureFichier effectuée\n");
	printf("nbrs= %d\n", nbrs);	
	printf("nbrarcs= %d\n", nbarc);
	if (G==NULL)
	{
		return 1;
	}
	else 
	{
		printf("contenu du graphe :\n");
		afficherGraphe(G, nbrs, nbarc);
	}
}	
