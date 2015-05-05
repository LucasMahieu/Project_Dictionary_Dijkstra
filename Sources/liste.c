//
//  liste_succ.c
//  
//
//  Created by Lucas MAHIEU on 18/04/2015.
//
//

#include "../Headers/main.h"


Liste Creer_Liste(void) {
	return NULL;
}

int Est_Vide(Liste L) {
	return !L;
}

T_SUCC Ajout_Tete(char* e, L_SUCC L,int taille_mots)   // ajout en tete de liste de L_SUCC d'un element de type char*
{
	printf("ajout tete char\n");
	int i=0;
	T_SUCC p;
	if ((p=(T_SUCC)calloc(1,sizeof(*p)))==NULL) return NULL;
	printf("calloc\n");
	for (i=0; i<taille_mots; i++) ((p->mot)[i]=e[i]);  // il faut initialiser le p->mot[i]
	p->Liste_succ=L;
	return p;
}

L_SUCC Ajout_Tete_L_SUCC(T_SUCC e, L_SUCC L)  // ajout en tete de liste de L_SUCC d'un element de type T_SUCC
{
	
	printf("ajout tete l-succ\n");
	L_SUCC p;
	if ((p=(L_SUCC)calloc(1,sizeof(*p)))==NULL) return NULL;
	printf("calloc\n");
	p->val=e;
	printf("p-va\nl");
	p->suiv=L;
	printf("p-suiv\n");
	return p;
}



L_SUCC Rech_Chaine(char* chaine, L_SUCC L)
{   L_SUCC p=L;
	while((p)&&(strcmp(chaine,(p->val)->mot)!=0)) p=p->suiv;
	return p;
}

/*Liste rech(ELEMENT e, Liste L)
{   Liste p=L;
	while(!est_vide(p)&&((&(p->mot),&e)!=0)) p=p->suiv;
	return p;
}
*/

int Taille_Liste(Liste l) {
	int i=0;
	while(!Est_Vide(l)) {
		l=l->suiv;
		++i;
	}
	return i;
}

void Visualiser_Liste(Liste L)
{   Liste p=L;
	while(!Est_Vide(p)) {
		printf("%s \n",(p->val->mot));
		p=p->suiv;
	}
}