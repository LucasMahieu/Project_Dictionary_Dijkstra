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
void recherche_successeur(T_GRAPHE G,int taille_mot);

int taille_fichier(FILE* fichier); 

L_SOMMET* creer_graphe(char* fichier,int* taille_table,int taille_mots);

int Taille_Mots(char*);

#endif /* defined(____fonctions__) */
