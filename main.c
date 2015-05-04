//
//  main.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "./Headers/main.h"


int main (FILE* f,int taille_mots){  // le main va prendre 2 arg. le fichier de mots et la tailles max des mots
	T_GRAPHE G;
	
<<<<<<< HEAD
	G.table = creer_graphe(f,&(G.taille));   // ici, le scelette du graphe est creer = tous les mots sont rangés selon le hachoire
=======
	G.table=creer_graphe(f,&(G.taille));   // ici, le squelette du graphe est créé = tous les mots sont rangés selon le hachoire

	
/*Création de la liste de successeur
	On prend un mot on change une lettre et on regarde si le nouveau mot appartient au fichier. 
	Si c'est le cas on ajoute ce mot en successeur avec un ajout tête. Il faut parcourrir l'ensemble 
	des élements de la table de hashage*/

	
}
