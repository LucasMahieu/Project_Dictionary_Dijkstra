//
//  liste_succ.c
//  
//
//  Created by Lucas MAHIEU on 18/04/2015.
//
//

#include "../Headers/main.h"


Liste creer_liste(void) {
	return NULL;
}

int est_vide(Liste L) {
	return !L;
}

Liste ajout_tete(ELEMENT e, Liste L)
{
	Liste p=(Liste) calloc(1,sizeof(*p));
	if (p==NULL) return NULL;
	p->val=e;
	p->suiv=L;
	return p;
}


Liste rech_chaine(char* chaine, Liste L)
{   Liste p=L;
	while(!est_vide(p)&&(compare_chaine(chaine,&(p->val))!=0)) p=p->suiv;
	return p;
}

Liste rech(ELEMENT e, Liste L)
{   Liste p=L;
	while(!est_vide(p)&&(compare(&(p->val),&e)!=0)) p=p->suiv;
	return p;
}


int taille_liste(Liste l) {
	int i=0;
	while(!est_vide(l)) {
		l=l->suiv;
		++i;
	}
	return i;
}

void visualiser_liste(Liste L)
{   Liste p=L;
	while(!est_vide(p)) {
		affiche(&(p->val));
		p=p->suiv;
	}
}