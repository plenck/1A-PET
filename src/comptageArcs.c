#include "graphe.h"

int comptageArcs(GRAPH G,int nbsommets){
	int i,S=0;
	L_ARC p,c;
	for(i=0;i<nbsommets;i=i+1)
	{
		c=G[i].voisins;
		if(c==NULL)  {
			S=S;
		}
		for(p=c;!listeArcVide(c);p=p->suiv){
			S=S+1;
		}
	}
	return S;
}
