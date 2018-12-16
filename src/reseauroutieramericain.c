#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>
#include"liste.h"
#include"dijkstra.h"
int main()
{

GRAPH G;
T_SOMMET a;
T_SOMMET b;
Liste l1;
int depart,arrivee;
int nbrs,nbarc;
G=lectureFichier("graphe2.txt", &nbrs,&nbarc);
/*printf("fin de lecture\n");*/
printf("Rentrez le numéro de sommet de depart\n");
printf("depart:\n");
scanf("%d",&depart);
printf("arrivée:\n");
scanf("%d",&arrivee);
equivalentnumero(G,&a,&b,depart,arrivee,nbrs); /*fonction qui renvoie les sommets qui correspondent aux indices depart et arrivee*/
/*printf("Debut du Dijkstra\n");*/
l1=dijkstra(G,nbrs,a,b); /*liste de T-SOMMETS*/
/*printf("fin du Dijkstra\n");*/	
AffichageDijkstragraphe2(l1,a,b);
return 0;
}
