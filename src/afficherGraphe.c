#include<stdio.h>
#include<stdlib.h>
#include"graphe.h"
void afficherGraphe(GRAPH G,int nbsommets,int nbarcs)
{
	int e;
	double b,c,f;
	char *d,*r;/*rajouter la variable line(char* line)*/
	L_ARC p;
	printf("nombresommets=%d,nombrearcs=%d\n",nbsommets,nbarcs);
	int i=0;
	printf("sommets du graphe\n");	
	printf("nombre,x,y,nomdel'arret\n");
	for(i=0;i<nbsommets;i=i+1)
	{
		b=G[i].x;
		c=G[i].y;
		d=G[i].nom;
		r=G[i].line;
		printf("%d %lf %lf %s %s\n",i,b,c,d,r); /*Pour afficher un char* on va mettre un %s à la place de %c*/
	}


	printf("arêtes du graphe: Départ Arrivée cout\n");
	for(i=0;i<nbsommets;i=i+1)
	{	
		p=G[i].voisins;
		while(p!=NULL)	
		{
			e=(p->val).arrivee;  
			f=(p->val).cout;
			printf("%d %d %lf\n",i,e,f);
			p=p->suiv;
		}				
	}
}

