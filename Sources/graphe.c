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

void recherche_successeur(T_GRAPHE G,int taille_mot, int nombre_mots,int taille_table){

	
	int i = 0;
	int j = 0;
	int m = 0;
	int Position = 0;
	char mot_remplissage;
	char alphabet = "abcdefghijklmnopqrstuvwxyz" /*On utilisera cette chaine de caractère pour mofifier les charactères 
	dans le mot "mot"*/
	L_SOMMET* p = NULL;/* On prend un pointeur pour pouvoir parcourir les listes associées à la table de hachage*/
	L_SOMMET* q = NULL;
	q = G.Table;
	T_SOMMET* r = NULL;
	
	FILE* f1 = fopen(fichier,"r");    // On ouvre le fichier dans f1
	if (f1==NULL) return 1;
	
	/*On parcours la table de hashage pour chaque mot formé avec la variable "mot_remplissage". Ce mot "mot_remplisssage" est formé à partir 
	de des mots déjà présent dans la table de hashage. Et si on trouve ce nouveau mot_remplissage dans la table de hashage on peut l'ajouter en tête*/
	
	for(k=0,k<taille_mot,k++){
		/*On initialise le "mot_remplissage"*/
		for(m=0,m<taille_table,m++){$
			p = G.table+m;
			while(!est_vide(p)){/*On parcours l'ensemble des éléments associés à la case G.Table+m de la table de hashage*/
			mot_remplissage=(p->val)->mot;
				for(j=0, j<26,j++){
					mot_remplissage[k]=alphabet[j];	/*On modifie mot_remplissage avec le tableau alphabet*/
					Position = hash(mot_remplissage,CODE_HACHAGE,nombre_mots);/*On hash le mot_remplissage et on regarde si il appartient à la table de hasgae*/
						while(!est_vide(q[Position]){/*On parcours l'ensemble des L_SOMMET de la table de hashage associé à la position sur laquelle on a placé le mot_remplissage*/
						r = rech(mot_remplissage,(q[Position]->val));/*On recherche si le mot_remplissage est bien présent dans la tablde hashage*/
						if(!r){/*Si mot_remplissage est présent dans la table de hashage, on peut faire un ajout en tête*/
							ajout_tete(mot_remplissage,((G.table+m)->val)->Liste_succ);
						}/*On ajoute en tête si le mot est bien un métagramme présent dans la table de hashage*/
						q[Position]= q[Position]->suiv;
						}
				}
				p=p->suiv;
				
			}
	}
}
	

