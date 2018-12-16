#ifndef _LISTE
#define _LISTE

#include "graphe.h"

typedef T_SOMMET ELEMENT;

struct maille {
	ELEMENT val;
	struct maille *suiv;
};
typedef struct maille *Liste;

Liste creer_liste ();
int liste_vide (Liste l);
void visualiser (Liste l);
Liste ajout_tete (ELEMENT c, Liste l);
Liste supprimer_tete (Liste l);
void liberer (Liste l);
Liste ajout_queue (ELEMENT c, Liste l);
Liste concat (Liste l1, Liste l2);
Liste copie (Liste l);
Liste supprimen (int n, Liste l);

#endif
