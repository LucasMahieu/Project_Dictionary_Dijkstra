//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "../Headers/main.h"



int hash(char mot[], int a,int n){
	int i=(strlen(mot)-2);  // Ici je fait -2 (cf. commentaire debut de main) le \n fait partie du mot et le \0 aussi donc faut en enlever 2
	int h=1;
	while (i>0) {
		h=(h*a+mot[i])%n; 
		i--;
	}
	return h;
}

int Taille_Mots(FILE* fichier){
	int i = 0;
	char* chaine =NULL;
	int N = 20; /*Permet de déterminer la longueur des mots, pas de mots aussi long et seulement détection des retours à la ligne*/	
	chaine = fgets(mot_fichier,N,fichier);	
	if(mot_fichier[i]!='\n'){
		i++;
	}
return i;	
}



int taille_fichier(FILE* fichier){
	int i=0;
	char* lettre;
	
	while (lettre[0]!=EOF) {   // tant que l'on est pas à la fin du document
		fgets(lettre,2,fichier);     // on stock UN character dans lettre donc lettre = (le char, \0) 
		if (lettre[0]=='\n') {  // si c'est un retour à la ligne alors on le comptabilise
			i++;
		}
	}
	fclose(fichier);
	return i;   // le # de \n correspond au # de mots du fichier
}


L_SOMMET* creer_graphe(char* fichier,int* taille_table,int taille_mots){ // on va retourner en adresse la taille de la table
	
	FILE* f1 = fopen(fichier,"r");    // On ouvre le fichier dans f1
	if (f1==NULL) return NULL;     // si erreur
	
	char* mot_fichier;
	int Position=0;
	int nombre_mots=0;
	
	nombre_mots = taille_fichier(f1);
	
	L_SOMMET* Table_hachage; 
	
	if((Table_hachage=(L_SOMMET*)calloc(nombre_mots,sizeof(*Table_hachage)))==NULL) return NULL;  // il faudra faire une fonction qui calcule le # de mots
	
	// ici on va remplir notre tableau avec les listes. La position est déterminer par la sortie du hachoire AH AH AH (sadique)
	while (fgets(mot_fichier, taille_mots+2,f1)!=NULL){   
		//fgets = null quand on a EOF. Il arrete la saise de charactere lorsqu'il rencontre un retour à la ligne. c'est pourquoi j'ai mis +2, comme ça il va aller lui meme 'buter' contre le retour à la ligne, et au coup	d'après il sera en bonne position.
		
		Position = hash(mot_fichier,CODE_HACHAGE,nombre_mots); //calcul de la position dans la table par fct de hachage 
		ajout_tete(mot_fichier,Table_hachage[Position]);       // puis on l'ajoute en tete de liste pour ne pas deranger les éventuels mots deja présents
	};
	
	if(fclose(fichier)==NULL) return NULL;
	taille_table=nombre_mots;
	return (Table_hachage)
}
