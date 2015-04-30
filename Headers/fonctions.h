//
//  fonctions.h
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#ifndef ____fonctions__
#define ____fonctions__

int hash(char mot[], int a,int n);

void recherche_successeur(T_GRAPHE G,FILE* f1,int taille_mot, int nombre_mots);

int taille_fichier(FILE* fichier); 

L_SOMMET* creer_graphe(FILE* fichier,int* taille_table,int taille_mots);

int Taille_Mots(FILE*);

void affiche(char* chaine);

#endif /* defined(____fonctions__) */
