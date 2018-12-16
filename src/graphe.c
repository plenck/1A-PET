#include "graphe.h"


L_ARC creerListeArc(){
	return NULL;
}
int listeArcVide(L_ARC lArc){
	return !lArc;
}

/* fonction a ajouter pour diego au besoin
void visualiserListeArc(L_ARC lArc){
}
*/
L_ARC ajoute_arc(T_ARC  e, L_ARC lArc){
	L_ARC p;
	p = calloc(1,sizeof(*p));
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
		return NULL;
    }
	p->val=e;
	p->suiv=lArc;
	return p;
}

L_ARC supprime_arc(L_ARC lArc ){	
	L_ARC p;
    if (lArc == NULL){
        return NULL;
    }

    else {
        p= lArc->suiv;
        free(lArc);
		return p;
    }

}

void libererListeArc(L_ARC l){
	if (!listeArcVide(l)){
		libererListeArc(supprime_arc(l));
	}
	return;
}
