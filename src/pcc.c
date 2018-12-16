#include "graphe.h"
#include "liste.h"
#include "dijkstra.h"

void affichePcc(Liste PCC, int nbrs){
	printf("Liste des plus court chemins:\n");
	printf("[");
	while (!liste_vide(PCC)){
		printf("%d; ",(PCC->val).numero);
		PCC=supprimer_tete (PCC);
		}
	printf("\n]\n");
	return;
}

int main(){
	GRAPH G;
	int nbrs,i,j,nbra;
	G=lectureFichier("grapheNewYork.csv", &nbrs, &nbra);
	printf("1. lecture fichier effectuée\n\n");
	Liste PCC;
	printf("entrez le numero du point de départ\n");
	scanf("%d",&i);
	printf("entrez le numero du point d'arrivée\n");
	scanf("%d",&j);
	PCC= dijkstra(G,nbrs,G[i],G[j]);
	printf("sommet a parcourir\n");
	visualiser(PCC);		
	return 0;
	
}
