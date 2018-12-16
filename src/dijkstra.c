#include "graphe.h"
#include "liste.h"
#include <limits.h>

T_SOMMET sommetDePccMin(Liste *C,unsigned int* PCC){
	Liste p;
	p=creer_liste();
	printf("valeur de C:");
	visualiser(*C);
	p = *C;
	printf("valeurs de p");
	visualiser(p);
	int i,compteur, tampon;
	unsigned int min;
	min = 2147483647;
	compteur = -1;
	T_SOMMET res;
	printf("Sommets a visiter:\n");
	visualiser(*C);
	if((p->suiv)==NULL){
		res = p->val;
		tampon=0;
	}
	else{	
	while(!liste_vide(p)){
		compteur+=1;
		printf("valeur de compteur:%d\n",compteur);
		i=(p->val).numero;
		printf("Noeud: %d", i);
		printf("  nom: %s\n",(p->val).nom);
		printf("PCC[%d]: %d\n\n",i,PCC[i]);
		if (PCC[i]<=min){
			min = PCC[i];
			res = p->val;
			tampon = compteur;
			printf("min = %d tampon =%d\n",min,tampon);
		}	
		p=p->suiv;
	}
	}
	liberer(p);
	printf("tampon=%d\n",tampon);
	*C=supprimen(tampon,*C);
	printf("numero du noeud retourné :%d\n",res.numero);
	return res;
}
	



Liste dijkstra(GRAPH G, int nbrs, T_SOMMET root, T_SOMMET target){
	/*===PARAMETERS===
	*G : graphe contenant tout les noeuds 
	*int root : point de départ indéxé par son numéro
	*target : point d'arrivée indéxé par son numéro
 	*
	*INITIALISATION
	*/
	int i;
	int goal;
	T_SOMMET j;
	L_ARC Larc;
	
	unsigned int PCC[nbrs];
	
	T_SOMMET pere[nbrs];
	printf("initialisation Dijkstra\n");
	Liste S, C, res;	//S:sommet dont on connait le plus court chemin à ROOT indixés  par leur numero
						//C : liste des sommets qui restent à visiter indexés par leur numéro					
	S = creer_liste();
	C = creer_liste(); 
	res = creer_liste();
	
	
	//initialisation des tableaux;
	printf("2.1 initialisation Dijkstra\n");

	for(i=0; i<nbrs; i++){
			PCC[i]=2147483647;
			pere[i].numero=-1;
			C=ajout_tete(G[i],C);
	}
	PCC[root.numero]=0;
	goal=0;	

	j=root;
	do{
		printf("+++++++boucle++++++++\n");
		//selectionner sommet de C de plus petite valeur de pcc[j]
		j = sommetDePccMin(&C,PCC);
		//suppression du sommet j de l'ensemble C (j a été visité) inclus dans sommetDePccMin()
		S=ajout_tete(j,S);
		printf("\nSommets visités:\n");
		visualiser(S);
		
		if(j.numero==target.numero) {goal =1;} 
		
		
		Larc=j.voisins;
		while (Larc != NULL){
			//si PCC[k]>PCC[j]+c[j][k]
				
			if (PCC[(Larc->val).arrivee]>PCC[j.numero]+(Larc->val).cout){	
				PCC[(Larc->val).arrivee]=PCC[j.numero]+(Larc->val).cout; // PCC[k]=PCC[j]+c[j][k]
				pere[(Larc->val).arrivee]=j ;	//pere[k]=j
			}
			Larc=Larc->suiv;
		}

	}
	while((goal==0) && (PCC[j.numero] != 2147483647)); 

	i=target.numero;
	printf("target.numero=%d\n",i);
	if(pere[i].numero==-1){
		printf("\n+++destination innaccessible+++\n\n");
		return NULL;
	}
	
	
	else{
		
		res = ajout_tete(target,res);
		
		do{	
			res=ajout_tete(pere[i],res);
			printf("pere[%d]=%d\n",i, pere[i].numero);
			i=pere[i].numero;	
		}while(i!=root.numero);
		//res = ajout_tete(root,res);	
	}
		
	return res;			

}
