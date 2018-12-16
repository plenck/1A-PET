#include"graphe.h"
#include"liste.h"
void AffichageDijkstragraphe2(Liste l1,T_SOMMET a,T_SOMMET b)
{
	Liste p;
	p=l1;
	if(liste_vide(p))
	{
		printf("votre point de destination est inaccessible à partir de votre point de depart");
	}
	printf("A partir de votre position actuelle:%s\n",a.nom);
	printf("Le plus court chemin jusqu'au %s est le suivant:\n",b.nom);

	for(p=p->suiv;!liste_vide(p);p=p->suiv)
	{
		printf("->%s\n",(p->val).nom);
	}
}
