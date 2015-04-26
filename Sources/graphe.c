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
	if (f1==NULL) return 1;     // si erreur Y'A PAS UN PROBLEME DE TYPE ?
	
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

void recherche_successeur(T_GRAPHE G,int taille_mot){

	
	int i = 0;
	int j = 0;
	int m = 0;
	char mot_remplissage;
	char alphabet = "abcdefghijklmnopqrstuvwxyz" /*On utilisera cette chaine de caractère pour mofifier les charactères 
	dans le mot "mot"*/
	L_SOMMET* p = NULL;/* On prend un pointeur pour pouvoir parcourir les listes associées à la table de hachage*/
	
	FILE* f1 = fopen(fichier,"r");    // On ouvre le fichier dans f1
	if (f1==NULL) return 1;
	
	/*On initialise un mot auquel on changera toutes les lettres. La taille de ce mot dépend du fichier texte ouvert, on prendra la variable taille_mot*/
	for(i=0,i<taille_mot,i++){
		s[i]='a';//Je ne suis pas certain de cette initialisation
	}
	
	/*On parcours la table de hashage pour chaque mot formé avec la variable "mot_remplissage", et on regarde si ce nouveau mot_remplissage différe
	d'une lettre avec le sommet auquel on s'intéresse. Si c'est le cas on ajout en tête ce mot_remplissage formé à la liste de 
	successeur du mot en question. Il faut par ailleurs que le mot_remplissage modifié appartienne au fichier texte*/
	
	for(k=0,k<26,k++){
		for(j=0, j<26,j++){/*26 correspond à l taille de l'aphabet que l'on doit parcourir*/
			while (fgets(mot_fichier, taille_mots+2,f1)!=NULL){
				if(strcmp(mot_fichier,mot_remplissage) == 0){/*Si le mot "mot_remplissage" appartient au fichier texte, on peut alors chercher à parcourir la table de hashage.*/
					for(m=0,m<taille_table,m++){
						p = Table_hachage[m];
						while(p->suiv != NULL){
						/*Il faut chercher à savoir il y a exactement une lettre de différence, on utilise la fonction du fichier "fontions.c"*/
							if(difference_une_lettre(mot_remplissage,(p->valeur)->mot,taille_mot)==1){/*Il faut pointer sur le mot qui corresponf au valeur de T_SOMMET*/
								ajout_tete(mot_remplissage,(p->valeur)->Liste_succ);/*On ajoute en tête si le mot est bien un métagramme*/
							}
						}
					}
				}
			}
		mot_remplissage[0]=alphabet[j];/*On modifie la dernière lettre de mot_remplissage, en utilisant alphabet*/
		}	/*Mais comment faire pour avoir tous les cas ? On sait qu'il y aura 26^taille_mot combinaisons */
		mot remplissage[1]=alphabet[k];
	}

}	

