//
//  graph.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "./Header/main.h"


L_SOMMET* creer_graphe(FILE* fichier,int* taille_table){ // on va retourner en adresse la taille de la table

	FILE* f1 = fopen(fichier,"r");    // On ouvre le fichier dans f1
	if (f1==NULL) return 1;     // si erreur
	
	char* mot_fichier;
	int Position=0;
	
	L_SOMMET* Table_hachage; 
	if(Table_hachage=(L_SOMMET*)calloc(nombre_mots,sizeof(*Table_hachage))==NULL) return 2;  // il faudra faire une fonction qui calcule le # de mots
	
	// ici on va remplir notre tableau avec les listes. La position est déterminer par la sortie du hachoire AH AH AH (sadique)
	while (fgets(mot_fichier, taille_mots+2,f1)!=NULL){   
	//fgets = null quand on a EOF. Il arrete la saise de charactere lorsqu'il rencontre un retour à la ligne. c'est pourquoi j'ai mis +2, comme ça il va aller lui meme 'buter' contre le retour à la ligne, et au coup	d'après il sera en bonne position.
		
		Position = hash(mot_fichier,CODE_HACHAGE,nombre_mots); //calcul de la position dans la table par fct de hachage 
		ajout_tete(mot_fichier,Table_hachage[Position]);       // puis on l'ajoute en tete de liste pour ne pas deranger les éventuels mots deja présents
	};
	
	if(fclose(fichier)==NULL) return 1;
	taille_table=nombre_mots;
	return (Table_hachage)
}

void recherche_successeur(T_GRAPHE G,)



