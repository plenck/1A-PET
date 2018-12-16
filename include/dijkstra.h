#ifndef _DIJKSTRA
#define _DIJKSTRA

#include "graphe.h"
#include "liste.h"
/*Dijkstra*/

void affichePcc(Liste PCC, int nbrs);
Liste dijkstra(GRAPH G, int nbrs, T_SOMMET root, T_SOMMET target);
T_SOMMET sommetDePccMin(Liste *C,unsigned int* PCC);

void AffichageDijkstragraphe2(Liste l1,T_SOMMET a,T_SOMMET b);
void equivalentnumero(GRAPH G,T_SOMMET* a,T_SOMMET* b,int c,int d,int nbrs);
#endif
