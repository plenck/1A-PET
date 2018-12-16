#ifndef _GRAPHE
#define _GRAPHE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
	int arrivee;
	double cout;
} T_ARC;

typedef struct lsucc{
	T_ARC val;
	struct lsucc* suiv;
} *L_ARC;

typedef struct{
	char nom[128];
	int champs; //0 si on est dans C, 1 si on est dans S blablabla
	double x,y;
	char line[128];
	int numero;
	L_ARC voisins; //L_ARC est un pointeur vers la cellule suivante
} T_SOMMET;





typedef T_SOMMET* GRAPH; 

/*Ensemble des fonctions d'action sur les graphes*/
L_ARC creerListeArc();
int listeArcVide(L_ARC lArc);
void visualiserListeArc(L_ARC lArc);
L_ARC ajoute_arc(T_ARC  e, L_ARC lArc);
L_ARC supprime_arc(L_ARC lArc ) ;
void libererListeArc(L_ARC lArc);


/*Fonctions necessaires à la partie 1*/
void afficherGraphe(GRAPH G, int nbsommets,int nbarcs);
GRAPH lectureFichier(const char* filename,int* nbrS, int *nbrA);   
int nbSommets(const char *filename);


#endif
