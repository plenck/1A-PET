#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"graphe.h"


int voisin(T_SOMMET* G,int x,int y) /*teste si y est le voisin de x*/
{
	L_ARC c;
	c=G[x].voisins;
	while(!listeArcVide(c))
	{
		if(((c->val).arrivee)==y)
		{
			return 1;
		}
		c=c->suiv;
	}			
	return 0;
}


L_ARC voisins(T_SOMMET* G, int x)
{
	L_ARC c;
	c=G[x].voisins;
	return c;

}

int sommetValeurPccMin(Liste C, unsigned int *PCC){
	int min;
	min=PCC[C->val];
	while(!liste_vide(C)){
		if (PCC[C->val]<min){
			min=PCC[C->val];
		}
		C=C->suiv;
	}
	return min;
}	




