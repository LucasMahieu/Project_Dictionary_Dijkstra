//
//  fonctions.h
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#ifndef ____fonctions__
#define ____fonctions__

int Hash(char mot[], int a,int n,int taille_mots);

void Recherche_Successeur(T_GRAPHE G,FILE* f1,int taille_mot, int nombre_mots,int taille_table);


L_SOMMET* Creer_Graphe(FILE* fichier,int taille_mots, int nombre_mots);

int Taille_Mots(FILE*);
int Taille_Fichier(FILE* fichier); 
void Affiche(char* chaine);
Liste Creer_Liste(void);
int Est_Vide(Liste L);
//Liste rech(ELEMENT e, Liste L);
L_SUCC Rech_Chaine(char* chaine, L_SOMMET L);
T_SUCC Ajout_Tete(char* e, L_SUCC L,int taille_mots);
L_SUCC Ajout_Tete_L_SUCC(T_SUCC e, L_SUCC L);
int Taille_Liste(Liste l);
void Visualiser_Liste(L_SUCC L);
// d'autre fnctions de listes sont dispo dans le TD9

#endif /* defined(____fonctions__) */
