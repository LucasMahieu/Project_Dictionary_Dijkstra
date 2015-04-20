//
//  liste.h
//  
//
//  Created by Lucas MAHIEU le 18.04.15.
//
//

#ifndef _liste_h
#define _liste_h




//Ici l'element est un T_SUCC
typedef T_SUCC ELEMENT;

// Je m'inspire de ce qu'il était fait pour les liste mais avec des 'lsucc' ce que l'on pourrait appeler des 'suivant' ou des 'prochain' des 'successeurs' quoi ^^
typedef struct lsucc {
	ELEMENT val;
	struct lsucc* suiv;
}* L_SUCC;

typedef L_SUCC Liste;  // pour bien comprendre que notre type 'Liste' d'avant c'est bien la meme chose que  'L_SUCC'.
typedef L_SUCC L_SOMMET; // ici c'est pareil un liste est une liste



Liste creer_liste(void);
int est_vide(Liste L);
Liste rech(ELEMENT e, Liste L);
Liste rech_chaine(char* chaine, Liste L);
Liste ajout_tete(ELEMENT e, Liste L);
int taille_liste(Liste l);
void visualiser_liste(Liste L);
// d'autre fnctions de listes sont dispo dans le TD9

#endif
