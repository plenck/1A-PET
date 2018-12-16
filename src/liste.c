#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


Liste creer_liste () {
	return NULL;
}

int liste_vide (Liste l) {
	return !l;
}


void visualiser (Liste l) {
	if (!liste_vide(l)) {
		printf("%d, ",(l->val).numero);
		visualiser(l->suiv);
	}
	else {
		printf("\n\n");
	}
}

Liste ajout_tete (ELEMENT e, Liste l) {
	Liste p;
	p = calloc(1, sizeof(*p));
	if (p==NULL) {
		return NULL;
	}
	p->val=e;
	p->suiv=l;
	return p;
}

Liste supprimer_tete (Liste l) {
	if (liste_vide(l)) {
		return NULL;
	}
	Liste p = l->suiv;
	
	return p;
}

void liberer (Liste l) {
	if (!liste_vide(l)) {
		liberer(supprimer_tete(l));
	}
}

Liste ajout_queue (ELEMENT e, Liste l) {
	if (liste_vide(l)) {
		return ajout_tete(e, l);
	}
	Liste p=l;
	Liste q=creer_liste();
	q=ajout_tete(e, q);
	while (!liste_vide(p->suiv)) {
		p=p->suiv;
	}
	p->suiv=q;
	return l;
}

Liste concat (Liste l1, Liste l2) {
	if (liste_vide(l1)) {
		return l2;
	}
	Liste p=l1;
	while (!liste_vide(p->suiv)) {
		p=p->suiv;
	}
	p->suiv=l2;
	return l1;
}

Liste copie (Liste l) {
	Liste p = l, q = creer_liste();
	while (!liste_vide(p)) {
		q=ajout_queue(p->val, q);
		p=p->suiv;
	}
	return q;
}

Liste supprimen (int n, Liste l) {
	/*
	*	supprime le nième élément de la liste
	*/
	if (n==0) {
		return supprimer_tete(l);
	}
	Liste p = l;
	Liste q;
	int i;
	for (i = 0; i<n-1; i++) {
		if (liste_vide(p)) {
			return l;
		}
		p=p->suiv;
	}
	if (!liste_vide(p) && !liste_vide(p->suiv)) {
		q=p->suiv;
		p->suiv = (p->suiv)->suiv;
		free(q);
	}
	return l;
}
