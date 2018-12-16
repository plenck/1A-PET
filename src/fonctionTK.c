#include "graphe.h"



GRAPH lectureFichier(const char *filename, int* S,int* nbrarcs){
/* Ouverture d'un fichier .txt, lecture de son contenu et enregistrement dans un graphe. Retourne ce graphe.*/ 
/*GRAPH est un tableau de T_SOMMET, pour être retourné par la fonction (conservé après son execution ce tableau doit être alloué dynamiquement*/

	int numero, dprt, rrv;//nba : nbr d'arcs, numero : n°de la ligne, dprt: numero de départ, rrv: numéro d'arrivée
	double lat, longi, cout;
	char line[128];
	char name[128];
	char discard[512];
	int i;
	T_ARC arc;
	FILE *F;
	T_SOMMET e;	
	GRAPH G;
	F=fopen(filename,"r");
	fscanf(F, "%d %d ", S, nbrarcs);
	
	/*allocation dynamique du tableau */
	G=calloc(*S, sizeof(T_SOMMET));
	 if (G == NULL){
        	exit(EXIT_FAILURE);
			return NULL;
	}
//	fgets(discard,511,F);
	fgets(discard,511,F);//discard the first unwanted string

	/* REMPLISSAGE DU TABLEAU DE SOMMET */
	for(i=0; i<*S; i++){
		
		fscanf(F,"%d %lf %lf %s %s\n", &numero, &lat, &longi, line, name);
		printf("%d %lf %lf %s %s\n",numero, lat, longi, line, name);
		strcpy(e.nom, name);
		e.numero=numero;
		strcpy(e.line,line);
		e.x=lat;
		e.y=longi;
		e.voisins=NULL;
		G[i]=e;
	}
	printf("sortie remplissage tb\n");
	fgets(discard, 511,F);//discard the second unwanted string
	fgets(discard,511,F);
	/*MISE A JOUR DES ARCS*/
	for(i=0; i<*nbrarcs; i++){
		fscanf(F, "%d %d %lf", &dprt, &rrv, &cout);
		printf("%d %d %lf\n", dprt, rrv, cout);
		arc.arrivee=rrv;
		arc.cout=cout;
		/*encapsulation*/
		/*ajout de la liste d'arc*/
		G[dprt].voisins=ajoute_arc(arc,G[dprt].voisins);
	}
	printf("fin MAJ\n");
	fclose(F);
	return G;
}

int nbSommets(const char *filename){
	int nombreSommet;
	FILE* F;
	F=fopen(filename,"r");
	fscanf(F, "%d",&nombreSommet);
	fclose(F);
	return nombreSommet;
}
/*
void afficherGraphe(GRAPH G, int* S){
	int i;
	
	for(i=0; i<*S;i++){
		printf("%d %lf %lf %s %s\n",G[i].numero, G[i].x, G[i].y, G[i].line, G[i].nom);
	}
	return;

}
*/


