//
//  graph.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//

#include "../Headers/main.h"

L_SOMMET* Creer_Graphe(FILE* fichier,int taille_mots, int nombre_mots){ // on va retourner en adresse la taille de la table
	char mot_fichier[30];  // 30 = taille max d'un mots avec de la marge
	int position=0;
	L_SOMMET* Table_hachage;
	rewind(fichier);
	//printf("\n\n ---\n");
	if((Table_hachage=(L_SOMMET*)calloc(nombre_mots,sizeof(*Table_hachage)))==NULL) return NULL;
	
// ici on va remplir notre tableau avec les listes. La position est déterminer par la sortie du hachoire
	while (fgets(mot_fichier,taille_mots+2,fichier)!=NULL){   
//fgets = null quand on a EOF. Il arrete la saise de charactere lorsqu'il rencontre un retour à la ligne. c'est pourquoi j'ai mis +2, comme ça il va aller lui meme 'buter' contre le retour à la ligne, et au coup	d'après il sera en bonne position.
		if(mot_fichier[strlen(mot_fichier)-1]=='\n') mot_fichier[strlen(mot_fichier)-1]='\0';
		if((strlen(mot_fichier)-1)<taille_mots){
//calcul de la position dans la table par fct de hachage
			position=Hash(mot_fichier,CODE_HACHAGE,nombre_mots,taille_mots); 		
			Table_hachage[position]=Ajout_Tete_L_SUCC(Ajout_Tete(mot_fichier,NULL,taille_mots),*(Table_hachage+position));
// puis on l'ajoute en tete de liste pour ne pas deranger les éventuels mots deja présents
		}
	};
	//printf("--- \n\n");
	rewind(fichier);
	return (Table_hachage);
}


void Recherche_Successeur(T_GRAPHE G,FILE* f1,int taille_mots, int nombre_mots){
	int i=0,chgt_alpha=0,P_Hash=0,lettre=0;
	int position = 0;
	char* mot_origine;
	char* mot_test; 
	mot_test=(char*)calloc(taille_mots,sizeof(*mot_test));
//On utilisera cette chaine de caractère pour mofifier les charactères dans le mot "mot"
	char alpha[26]="abcdefghijklmnopqrstuvwxyz";
// On prend un pointeur pour pouvoir parcourir les listes associées à la table de hachage
	L_SOMMET p_collision = NULL;
	p_collision = *(G.table);
	L_SOMMET r =NULL;
	rewind(f1);
//On parcours la table de hashage pour chaque mot formé avec la variable "mot_test"."mot_remplisssage" est formé à partir des mots déjà présent dans la table de hashage en changeant une lettre à la fois. Et si on trouve ce nouveau mot_test dans la table de hashage on peut l'ajouter en tête
	// lettre que l'on bouge
	for(lettre=0;lettre<taille_mots;lettre++){
		//P_Hash fait changer le ligne dans la table de hashage	
		for(P_Hash=0;P_Hash<nombre_mots;P_Hash++){
			p_collision=*((G.table)+P_Hash);
			while(p_collision){
				mot_origine=(p_collision->val)->mot;
				for (i=0;i<taille_mots;i++) mot_test[i]=mot_origine[i];
				for(chgt_alpha=0;chgt_alpha<26;chgt_alpha++){
//On modifie la lettre de mot_test avec le tableau alphabet
					mot_test[lettre]=alpha[chgt_alpha];
// on fait la suite que si le mot trouver est different du mots d'orrigine 
					if(strcmp(mot_test,mot_origine)) {
//On hash le mot_test et on regarde si il appartient à la table de hasgae
						position=Hash(mot_test,CODE_HACHAGE,nombre_mots,taille_mots);
//On recherche si le mot_remplissage est bien présent dans la table hashage
						r=Rech_Chaine(mot_test,*((G.table)+position));
//Si mot_test est présent dans la table de hashage, on peut faire un ajout en tête
						if(r){
							((p_collision->val)->Liste_succ)=Ajout_Tete_L_SUCC(r->val,(p_collision->val)->Liste_succ);
						}
					}
				}
				p_collision=p_collision->suiv;
			}
		}
	}
	rewind(f1);
}
	
