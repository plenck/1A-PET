#include"graphe.h"
void equivalentnumero(GRAPH G,T_SOMMET* a,T_SOMMET* b,int c,int d,int nbrs)
{
	int i;
	for(i=0;i<nbrs;i++)
	{
		if(G[i].numero==c)
		{
			*a=G[i];
		}
		else if(G[i].numero==d)	
		{
			*b=G[i];
		}	
	}
}
