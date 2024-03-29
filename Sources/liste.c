//
//  liste_succ.c
//  
//
//  Created by Lucas MAHIEU on 18/04/2015.
//
//

#include "../Headers/main.h"

Liste Creer_Liste(void) { return NULL; }

int Est_Vide(Liste L) { return !L; }

// ajout en tete dans une liste 'L_SUCC' d'un element de type char* 
T_SUCC Ajout_Tete(char* e, L_SUCC L,int taille_mots){
	int i=0;
	T_SUCC p;
	if ((p=(T_SUCC)calloc(1,sizeof(*p)))==NULL) return NULL;
	if (((p->mot)=(char*)calloc(30,sizeof(*(p->mot))))==NULL) return NULL;
	for (i=0; i<taille_mots; i++) ((p->mot)[i]=e[i]);
	p->Liste_succ=L;
	return p;
}

// ajout en tete dans une  liste de L_SUCC d'un element de type T_SUCC
L_SUCC Ajout_Tete_L_SUCC(T_SUCC e, L_SUCC L){
	L_SUCC p;
	if ((p=(L_SUCC)calloc(1,sizeof(*p)))==NULL) return NULL;
	p->val=e;
	p->suiv=L;
	return p;
}


L_SUCC Rech_Chaine(char* chaine, L_SUCC L)
{   L_SUCC p=L;
	int k=0;
	while( (p) && (strcmp(chaine,p->val->mot)!=0) ) {
	p=(p->suiv);
	}
	return p;
}


int Taille_Liste(Liste l) {
	int i=0;
	while(!Est_Vide(l)) {
		l=l->suiv;
		++i;
	}
	return i;
}

void Visualiser_Liste(L_SUCC L)
{   L_SUCC p=L;
	while(p) {
		printf("%s \n",((p->val)->mot));
		p=p->suiv;
	}
}



