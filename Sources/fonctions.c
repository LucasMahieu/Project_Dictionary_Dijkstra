//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "./Header/main.h"



int hash(char mot[], int a,int n){
	int i=(strlen(mot)-2);  // Ici je fait -2 (cf. commentaire debut de main) le \n fait partie du mot et le \0 aussi donc faut en enlever 2
	int h=1;
	while (i>0) {
		h=(h*a+mot[i])%n; 
		i--;
	}
	return h;
}




/* Je fais une fonction pour savoir si il y a exactement une lettre de différence entre deux chaines de caractères*/

int difference_une_lettre(char* mot1, char* mot2,int taille_mot){
	
	int i=0;
	int metagramme=0;
	int compteur = 0;
	
	for(i=0,i<taille_mot,i++){
		if(mot1[i]!=mot2[i])compteur ++;
	}
	if(compteur == 1)metagramme =1;
	return metagramme;
}/*Cette fonction retourne 1 si les deux mots différent exactement d'une lettre*/





